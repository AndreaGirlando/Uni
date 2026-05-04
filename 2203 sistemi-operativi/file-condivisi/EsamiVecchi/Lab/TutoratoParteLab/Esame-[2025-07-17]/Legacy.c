#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5

/*
AVVERTIMENTO AGLI INCAUTI: IL MUTEX CHE SEGUE, BENCHÉ POSTO A LIVELLO GLOBALE,
 È STATO QUI INTRODOTTO SOLTANTO A TITOLO DIMOSTRATIVO E NON RIENTRA AFFATTO
 TRA LE PRESCRIZIONI DEL COMPITO D’ESAME.

 LA SUA FUNZIONE È MERAMENTE ORNAMENTALE: ESISTE UNICAMENTE PER RENDERE PIÙ
 COMPOSTO E DISCIPLINATO L’OUTPUT DEL PROGRAMMA, GIACCHÉ LE printf DEI VARI THREAD,
 IN ASSENZA DI TALE PRESIDIO, S’INTRECCIAVANO FRA LORO IN CAOTICA MANIERA.
 PARTICOLARMENTE, IL MUTEX VIENE QUI USATO ALLORCHÉ I THREAD LETTORI STAMPANO
 LE MATRICI APPENA RECUPERATE PER MEZZO DI mmap DAI FILE BINARI.

 RIMOSSO QUESTO MUTEX, L’INTERA ARCHITETTURA LOGICA DEL PROGRAMMA RESTA INTATTA
 E PIENAMENTE CONFORME AL DETTATO DELLA PROVA (VEDASI PDF): MUTANDO SOLO
 L’ORDINE DELLE STAMPE, NON L’ESSENZA DEL FUNZIONAMENTO.

 IN BREVE: QUESTO MUTEX È NULL’ALTRO CHE UN ORPELLO.
 NON CONFONDETE, PER PIACERE, UN SIMILE ORNAMENTO CON PARTE INTEGRANTE
 DEL COMPITO.

 Guardare main.c per una versione senza questa variabile globale
*/

pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;
void safe_print(const char *message) {
    pthread_mutex_lock(&print_mutex);
    printf("%s", message);
    pthread_mutex_unlock(&print_mutex);
}
//---------------------

// Struttura per rappresentare una matrice
typedef struct {
    unsigned char matrix[16][16];  // Dimensione massima 16x16
    int size;
    int reader_id;
    int square_num;
    int valid;  // 1 se valida, 0 se terminazione
} square_t;

// Coda intermedia
typedef struct {
    square_t squares[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int count;
    int finished_readers;
    int total_readers;
    pthread_mutex_t mutex;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
} queue_t;

// Record finale
typedef struct {
    square_t square;
    int has_data;
    int finished;
    pthread_mutex_t mutex;
    pthread_cond_t data_ready;
} final_record_t;

// Parametri per i thread lettori
typedef struct {
    char *filename;
    int reader_id;
    int matrix_size;
    queue_t *queue;
} reader_params_t;

// Parametri per il thread verificatore
typedef struct {
    int matrix_size;
    queue_t *queue;
    final_record_t *final_record;
} verifier_params_t;

// Inizializza la coda
void init_queue(queue_t *queue, int total_readers) {
    queue->front = 0;
    queue->rear = 0;
    queue->count = 0;
    queue->finished_readers = 0;
    queue->total_readers = total_readers;
    pthread_mutex_init(&queue->mutex, NULL);
    pthread_cond_init(&queue->not_empty, NULL);
    pthread_cond_init(&queue->not_full, NULL);
}

// Inizializza il record finale
void init_final_record(final_record_t *final_record) {
    final_record->has_data = 0;
    final_record->finished = 0;
    pthread_mutex_init(&final_record->mutex, NULL);
    pthread_cond_init(&final_record->data_ready, NULL);
}

// Inserisce un quadrato nella coda
void enqueue(queue_t *queue, square_t *square) {
    pthread_mutex_lock(&queue->mutex);
    
    while (queue->count == MAX_QUEUE_SIZE) {
        pthread_cond_wait(&queue->not_full, &queue->mutex);
    }
    
    queue->squares[queue->rear] = *square;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->count++;
    
    pthread_cond_signal(&queue->not_empty);
    pthread_mutex_unlock(&queue->mutex);
}

// Segnala che un reader ha finito
void reader_finished(queue_t *queue) {
    pthread_mutex_lock(&queue->mutex);
    queue->finished_readers++;
    pthread_cond_signal(&queue->not_empty);
    pthread_mutex_unlock(&queue->mutex);
}

// Estrae un quadrato dalla coda (con gestione terminazione)
int dequeue(queue_t *queue, square_t *square) {
    pthread_mutex_lock(&queue->mutex);
    
    while (queue->count == 0 && queue->finished_readers < queue->total_readers) {
        pthread_cond_wait(&queue->not_empty, &queue->mutex);
    }
    
    if (queue->count == 0 && queue->finished_readers == queue->total_readers) {
        pthread_mutex_unlock(&queue->mutex);
        return 0; // Nessun dato disponibile, tutti i reader hanno finito
    }
    
    *square = queue->squares[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->count--;
    
    pthread_cond_signal(&queue->not_full);
    pthread_mutex_unlock(&queue->mutex);
    
    return 1; // Dato disponibile
}

// Inserisce un quadrato nel record finale (non bloccante se pieno)
void put_final_square(final_record_t *final_record, square_t *square) {
    pthread_mutex_lock(&final_record->mutex);
    
    // Se c'è già un dato, aspetta che venga prelevato
    while (final_record->has_data && !final_record->finished) {
        pthread_cond_wait(&final_record->data_ready, &final_record->mutex);
    }
    
    if (!final_record->finished) {
        final_record->square = *square;
        final_record->has_data = 1;
        pthread_cond_signal(&final_record->data_ready);
    }
    
    pthread_mutex_unlock(&final_record->mutex);
}

// Estrae un quadrato dal record finale
int get_final_square(final_record_t *final_record, square_t *square) {
    pthread_mutex_lock(&final_record->mutex);
    
    while (!final_record->has_data && !final_record->finished) {
        pthread_cond_wait(&final_record->data_ready, &final_record->mutex);
    }
    
    if (final_record->has_data) {
        *square = final_record->square;
        final_record->has_data = 0;
        pthread_cond_signal(&final_record->data_ready);
        pthread_mutex_unlock(&final_record->mutex);
        return 1; // Dato disponibile
    }
    
    pthread_mutex_unlock(&final_record->mutex);
    return 0; // Nessun dato, verificatore ha finito
}

// Segnala la fine al record finale
void signal_final_finished(final_record_t *final_record) {
    pthread_mutex_lock(&final_record->mutex);
    final_record->finished = 1;
    pthread_cond_broadcast(&final_record->data_ready);
    pthread_mutex_unlock(&final_record->mutex);
}

// Stampa una matrice inline
void print_matrix_inline(square_t *square) {
    for (int i = 0; i < square->size; i++) {
        printf("(");
        for (int j = 0; j < square->size; j++) {
            printf("%d", square->matrix[i][j]);
            if (j < square->size - 1) printf(", ");
        }
        printf(")");
        if (i < square->size - 1) printf(" ");
    }
}

// Stampa una matrice su più righe
void print_matrix_multiline(square_t *square) {
    for (int i = 0; i < square->size; i++) {
        printf("(");
        for (int j = 0; j < square->size; j++) {
            printf("%d", square->matrix[i][j]);
            if (j < square->size - 1) printf(", ");
        }
        printf(")\n");
    }
}

// Verifica se una matrice è un quadrato semi-magico
int is_semi_magic(square_t *square) {
    int size = square->size;
    int target_sum = -1;
    
    // Calcola la somma della prima riga
    int sum = 0;
    for (int j = 0; j < size; j++) {
        sum += square->matrix[0][j];
    }
    target_sum = sum;
    
    // Verifica tutte le righe
    for (int i = 1; i < size; i++) {
        sum = 0;
        for (int j = 0; j < size; j++) {
            sum += square->matrix[i][j];
        }
        if (sum != target_sum) return 0;
    }
    
    // Verifica tutte le colonne
    for (int j = 0; j < size; j++) {
        sum = 0;
        for (int i = 0; i < size; i++) {
            sum += square->matrix[i][j];
        }
        if (sum != target_sum) return 0;
    }
    
    return target_sum;
}

// Thread lettore
void *reader_thread(void *arg) {
    reader_params_t *params = (reader_params_t *)arg;
    pthread_mutex_lock(&print_mutex);
    printf("[READER-%d] file '%s'\n", params->reader_id, params->filename);
    pthread_mutex_unlock(&print_mutex);

    // Apri il file
    int fd = open(params->filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        reader_finished(params->queue);
        return NULL;
    }
    
    // Ottieni la dimensione del file
    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        close(fd);
        reader_finished(params->queue);
        return NULL;
    }
    
    if (st.st_size == 0) {
        close(fd);
        reader_finished(params->queue);
        return NULL;
    }
    
    // Mappa il file in memoria
    unsigned char *data = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (data == MAP_FAILED) {
        perror("mmap");
        close(fd);
        reader_finished(params->queue);
        return NULL;
    }
    
    //print the content of the file + the number of matrices
    pthread_mutex_lock(&print_mutex);
    printf("[READER-%d] mappato file di %ld byte\n", params->reader_id, st.st_size);
    printf("[READER-%d] contenuto del file:\n", params->reader_id);
    // print the content of the file
    int c = 0;
    for (size_t i = 0; i < st.st_size; i+=params->matrix_size*params->matrix_size) {
        printf("matrice n: %d\n", c);
        for (int j = 0; j < params->matrix_size; j++) {
            for (int k = 0; k < params->matrix_size; k++) {
                printf("%d ", data[i + j * params->matrix_size + k]);
            }
            printf("\n");
        }
        c++;
    }
    printf("\n");
    pthread_mutex_unlock(&print_mutex);

    int matrix_size = params->matrix_size; //dimesnione della matrice
    int matrix_bytes = matrix_size * matrix_size; //byte per sinola matrice
    int num_matrices = st.st_size / matrix_bytes; //numero di matrici nel file
    
    for (int m = 0; m < num_matrices; m++) {
        square_t square;
        square.size = matrix_size;
        square.reader_id = params->reader_id;
        square.square_num = m + 1;
        square.valid = 1;
        
        // Leggi la matrice
        for (int i = 0; i < matrix_size; i++) {
            for (int j = 0; j < matrix_size; j++) {
                square.matrix[i][j] = data[m * matrix_bytes + i * matrix_size + j];
                //m * matrix_bytes: salta tutte le matrici precedenti
                //i * matrix_size: salta le righe precedenti nella matrice corrente
                //j: posizione nella riga corrente

                /*
                *   ESEMPIO NUMERICO (matrice 3x3, elemento riga=1 colonna=2 della matrice=1):
                * offset = 1 * 9 + 1 * 3 + 2 = 9 + 3 + 2 = 14
                * Quindi data[14] contiene l'elemento (1,2) della seconda matrice
                * 
                * VISUALIZZAZIONE DELL'OFFSET:
                * 
                * File: [00][01][02][10][11][12][20][21][22][00][01][02][10][11][12]...
                *        │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
                *        0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  <- offset
                *        └─────────── matrice 0 ─────────┘ └─────────── matrice 1 ─────
                *                                                              ↑
                *                                                         elemento (1,2)
                */
            }
        }
        
        // Stampa il quadrato candidato
        pthread_mutex_lock(&print_mutex);
        printf("[READER-%d] quadrato candidato n.%d: ", params->reader_id, m + 1);
        print_matrix_inline(&square);
        printf("\n");
        pthread_mutex_unlock(&print_mutex);
        
        // Inserisci nella coda
        enqueue(params->queue, &square);
    }
    
    pthread_mutex_lock(&print_mutex);
    printf("[READER-%d] terminazione con %d quadrati letti\n", params->reader_id, num_matrices);
    pthread_mutex_unlock(&print_mutex);
    // Cleanup
    munmap(data, st.st_size);
    close(fd);
    
    // Segnala che questo reader ha finito
    reader_finished(params->queue);
    
    return NULL;
}

// Thread verificatore
void *verifier_thread(void *arg) {
    verifier_params_t *params = (verifier_params_t *)arg;
    square_t square;
    
    while (dequeue(params->queue, &square)) {
        pthread_mutex_lock(&print_mutex);
        printf("[VERIF] verifico quadrato: ");
        print_matrix_inline(&square);
        printf("\n");
        pthread_mutex_unlock(&print_mutex);

        int magic_sum = is_semi_magic(&square);
        if (magic_sum > 0) {
            pthread_mutex_lock(&print_mutex);
            printf("[VERIF] trovato quadrato semi-magico!\n");
            pthread_mutex_unlock(&print_mutex);
            put_final_square(params->final_record, &square);
        }
    }
    pthread_mutex_lock(&print_mutex);
    printf("[VERIF] terminazione\n");
    pthread_mutex_unlock(&print_mutex);
    signal_final_finished(params->final_record);
    
    return NULL;
}

// Cleanup delle risorse
void cleanup_resources(queue_t *queue, final_record_t *final_record) {
    pthread_mutex_destroy(&queue->mutex);
    pthread_cond_destroy(&queue->not_empty);
    pthread_cond_destroy(&queue->not_full);
    
    pthread_mutex_destroy(&final_record->mutex);
    pthread_cond_destroy(&final_record->data_ready);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <M-square-size> <bin-file-1> ... <bin-file-N>\n", argv[0]);
        return 1;
    }
    
    int matrix_size = atoi(argv[1]);
    if (matrix_size < 3 || matrix_size > 16) {
        fprintf(stderr, "Dimensione matrice deve essere tra 3 e 16\n");
        return 1;
    }
    
    int num_files = argc - 2;
    pthread_mutex_lock(&print_mutex);
    printf("[MAIN] creazione di %d thread lettori e 1 thread verificatore\n", num_files);
    pthread_mutex_unlock(&print_mutex);
    
    // Inizializza le strutture condivise
    queue_t queue;
    final_record_t final_record;
    
    init_queue(&queue, num_files);
    init_final_record(&final_record);
    
    // Crea i thread
    pthread_t *reader_threads = malloc(num_files * sizeof(pthread_t));
    pthread_t verifier_thread_id;
    reader_params_t *reader_params = malloc(num_files * sizeof(reader_params_t));
    
    // Parametri per il verificatore
    verifier_params_t verifier_params;
    verifier_params.matrix_size = matrix_size;
    verifier_params.queue = &queue;
    verifier_params.final_record = &final_record;
    
    // Crea i thread lettori
    for (int i = 0; i < num_files; i++) {
        reader_params[i].filename = argv[i + 2];
        reader_params[i].reader_id = i + 1;
        reader_params[i].matrix_size = matrix_size;
        reader_params[i].queue = &queue;
        
        pthread_create(&reader_threads[i], NULL, reader_thread, &reader_params[i]);
    }
    
    // Crea il thread verificatore
    pthread_create(&verifier_thread_id, NULL, verifier_thread, &verifier_params);
    
    // Thread principale: raccoglie i quadrati semi-magici
    int semi_magic_count = 0;
    square_t square;
    
    while (get_final_square(&final_record, &square)) {
        pthread_mutex_lock(&print_mutex);
        printf("[MAIN] quadrato semi-magico trovato:\n");
        pthread_mutex_unlock(&print_mutex);
        print_matrix_multiline(&square);
        
        int magic_sum = is_semi_magic(&square);
        pthread_mutex_lock(&print_mutex);
        printf("totale semi-magico %d\n", magic_sum);
        pthread_mutex_unlock(&print_mutex);
        
        semi_magic_count++;
    }
    
    // Aspetta la terminazione di tutti i thread
    for (int i = 0; i < num_files; i++) {
        pthread_join(reader_threads[i], NULL);
    }
    pthread_join(verifier_thread_id, NULL);
    
    pthread_mutex_lock(&print_mutex);
    printf("[MAIN] terminazione con %d quadrati semi-magici trovati\n", semi_magic_count);
    pthread_mutex_unlock(&print_mutex);

    // Cleanup
    cleanup_resources(&queue, &final_record);
    free(reader_threads);
    free(reader_params);
    
    pthread_mutex_destroy(&print_mutex);
    return 0;
}