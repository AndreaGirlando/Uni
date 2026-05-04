// ESAME 17 04 2025

// C'è una piccola differenza a livello di memoria condivisa, identificare qual'è e proporre una propia soluzione!!

#include <linux/limits.h>
#include <stdio.h>      // Per operazioni di I/O standard (printf, fprintf, fopen, fclose, fread, fwrite, fseek, ftell, perror)
#include <stdlib.h>     // Per funzioni di utilità generale (malloc, free, exit, EXIT_SUCCESS, EXIT_FAILURE)
#include <string.h>     // Per manipolazione di stringhe (strcpy, strcmp, memcpy, strrchr)
#include <pthread.h>    // Per la gestione dei thread POSIX (pthread_create, pthread_join, pthread_mutex_init, pthread_mutex_lock, pthread_mutex_unlock, pthread_cond_init, pthread_cond_wait, pthread_cond_signal, pthread_mutex_destroy, pthread_cond_destroy)
#include <unistd.h>     // Per funzioni di sistema (mkdir, stat)
#include <sys/stat.h>   // Per la struttura stat e le costanti per mkdir (S_IRWXU)
#include <sys/types.h>  // Per i tipi di dati di sistema (mode_t)
#include <fcntl.h>      // Per le costanti di controllo file (non direttamente usate qui, ma utili per I/O a basso livello)
#include <limits.h>     // Per costanti di sistema (PATH_MAX, NAME_MAX)
#include <libgen.h>

#define BLOCK_SZ 1024 // Dimensione del blocco per la lettura/scrittura dei file
#define STACK_CAP 10

/**
 * @brief Stampa un messaggio di errore su stderr e termina il programma.
 * @param msg Il messaggio di errore da stampare.
 */
void exit_with_msg(const char *msg){
    fprintf(stderr, "%s\n", msg); // Stampa un messaggio di errore su stderr.
    exit(EXIT_FAILURE); // Termina il programma con un codice di errore.
}

/**
 * @brief Stampa un messaggio di errore basato su `errno` (errore di sistema) e termina il programma.
 * @param msg Il messaggio descrittivo dell'operazione fallita.
 */
void exit_with_error(const char *msg){
    perror(msg); // Stampa un messaggio di errore basato su errno.
    exit(EXIT_FAILURE); // Termina il programma con un codice di errore.
}

/**
 * @brief Controlla il numero di argomenti passati al programma da riga di comando.
 * @param argc Il numero di argomenti.
 * @param argv L'array di stringhe degli argomenti.
 */
void check_args(int argc, char *argv[]){
    if(argc < 3) // Controlla se sono stati passati almeno due argomenti (nome del programma + almeno un altro argomento).
        exit_with_msg("Uso: duplicate-files-2 <file-1> [<file-2> ... <file-n>] <destination-dir>");
}

/**
 * @brief Struttura `block_t` per un record nello stack condiviso.
 * Ogni record rappresenta un blocco di dati letto da un file sorgente e i suoi metadati.
 */
typedef struct { //record da 1 KiB + metadati
    char buf[BLOCK_SZ]; // Buffer per i dati del blocco
    char fname[PATH_MAX]; // Nome del file associato al blocco
    off_t file_size; // Dimensione del file associato al blocco
    off_t offset; // Offset corrente nel file associato al blocco
    size_t len; // Lunghezza del blocco (numero di byte validi nel buffer)
    int eof; // Flag per indicare se si è raggiunta la fine del file (1 se EOF, 0 altrimenti)
} block_t;

/**
 * @brief Struttura `block_stack_t` per lo stack condiviso tra i thread READER e il thread WRITER.
 * Implementa un buffer circolare per una gestione efficiente dei dati e include i meccanismi di sincronizzazione.
 */
typedef struct {
    block_t slots[STACK_CAP]; // Array di `block_t` che costituisce il buffer circolare.
    int count; // Numero di record attualmente nello stack (0 a STACK_CAP).

    pthread_mutex_t mtx; // Mutex per proteggere l'accesso concorrente allo stack.
    pthread_cond_t not_full; // Variabile condizione per segnalare che si può produrre (stack non pieno).
    pthread_cond_t not_empty; // Variabile condizione per segnalare che si può consumare (stack non vuoto).

} block_stack_t; // Struttura per gestire lo stack dei blocchi

/**
 * @brief Struttura `reader_arg_t` per passare argomenti al thread READER.
 * Poiché `pthread_create` accetta solo un `void *` come argomento, è necessario
 * incapsulare tutti i parametri necessari in una singola struttura.
 */
typedef struct {
    int             id;
    char            src_path[PATH_MAX];   /* file da duplicare */
    block_stack_t  *stack;                /* puntatore allo stack condiviso */
} reader_arg_t;

/**
 * @brief Struttura `writer_arg_t` per passare argomenti al thread WRITER.
 */
typedef struct {
    block_stack_t  *stack;       /* stack condiviso */
    const char     *dest_dir;    /* directory di destinazione */
    int             total_files; /* quanti file ci aspettiamo (serve per sapere quando terminare) */
} writer_arg_t;

/**
 * @brief Inizializza lo stack condiviso, impostando i contatori a zero e inizializzando
 *        il mutex e le variabili condizione.
 * @param s Puntatore alla struttura `block_stack_t` da inizializzare.
 * @return 0 in caso di successo.
 */
static int stack_init(block_stack_t *s){
    s->count = 0;
    pthread_mutex_init(&s->mtx, NULL);
    pthread_cond_init (&s->not_full,  NULL);
    pthread_cond_init (&s->not_empty, NULL);
    return 0; // Inizializza lo stack e le condizioni
}

/**
 * @brief Distrugge il mutex e le variabili condizione associate allo stack.
 *        Questa funzione deve essere chiamata alla fine del programma per rilasciare le risorse.
 * @param s Puntatore alla struttura `block_stack_t` da distruggere.
 */
static void stack_destroy(block_stack_t *s) {
    pthread_mutex_destroy(&s->mtx);
    pthread_cond_destroy (&s->not_full);
    pthread_cond_destroy (&s->not_empty);
}


/**
 * @brief Aggiunge un blocco (`block_t`) allo stack condiviso.
 * Questa funzione è chiamata dai thread READER. Se lo stack è pieno, il thread chiamante si blocca
 * fino a quando non c'è spazio disponibile.
 * @param s Puntatore alla struttura `block_stack_t` (lo stack).
 * @param blk Il blocco di dati da aggiungere.
 */
static void stack_push(block_stack_t *s, const block_t *blk)
{
    // Acquisisce il lock sul mutex dello stack per garantire l'accesso esclusivo.
    pthread_mutex_lock(&s->mtx);
    while (s->count == STACK_CAP)
        // Rilascia il mutex e attende `not_full`. Quando si risveglia, riacquisisce il mutex.
        pthread_cond_wait(&s->not_full, &s->mtx);

    s->slots[s->count++] = *blk; // Copia il blocco nel prossimo slot e incrementa il contatore.
    pthread_cond_signal(&s->not_empty);
    pthread_mutex_unlock(&s->mtx);
}


/**
 * @brief Estrae un blocco (`block_t`) dallo stack condiviso.
 * Questa funzione è chiamata dal thread WRITER. Se lo stack è vuoto, il thread chiamante si blocca
 * fino a quando non ci sono dati disponibili.
 * @param s Puntatore alla struttura `block_stack_t` (lo stack).
 * @param out Puntatore dove verrà copiato il blocco estratto.
 */
static void stack_pop(block_stack_t *s, block_t *out)
{
    pthread_mutex_lock(&s->mtx);
    while (s->count == 0)
        pthread_cond_wait(&s->not_empty, &s->mtx);

    *out = s->slots[--s->count];
    pthread_cond_signal(&s->not_full);
    pthread_mutex_unlock(&s->mtx);
}

/**
 * @brief Funzione eseguita dai thread READER.
 * Ogni thread READER è responsabile della lettura di un file specifico, blocco per blocco,
 * e dell'invio di questi blocchi allo stack condiviso.
 * @param arg Puntatore a una struttura `reader_arg_t` contenente i parametri del thread.
 * @return NULL (i thread POSIX restituiscono un puntatore a void).
 */
static void *reader_thread(void *arg){
    reader_arg_t *r = arg;
    FILE *fp = fopen(r->src_path, "rb");
    if(!fp)
        exit_with_error("[Thread] fopen");
    
    //dimensione totale del file (per calcolare eof/offset)
    if(fseek(fp, 0, SEEK_END) != 0)
        exit_with_error("[Thread] fseek");

    long fsz = ftell(fp);
    rewind(fp); // Torna all'inizio del file

    printf("[READER-%d] lettura del file '%s' di %ld byte\n",
       r->id, r->src_path, fsz);

    /* Estrai il nome-base (senza path) per la duplicazione */
    // `strrchr` trova l'ultima occorrenza di '/'. Se presente, il nome base è dopo '/'.
    // Altrimenti, l'intero percorso è il nome del file.
    char *bs = basename(r->src_path);

        
    /* 4)  Ciclo di lettura a blocchi da 1 KiB */
    off_t offset = 0;
    for (;;) {
        block_t blk = {0};
        size_t rd = fread(blk.buf, 1, BLOCK_SZ, fp);
        if (rd == 0 && feof(fp)) break;       /* fine file: se non sono stati letti byte 
        e si è alla fine del file, esci dal loop */

        blk.len       = rd;
        blk.offset    = offset;
        blk.file_size = fsz;
        strncpy(blk.fname, bs, PATH_MAX);
        blk.fname[PATH_MAX-1] = '\0';
        blk.eof = (offset + rd >= fsz);        /* ultimo blocco? */

        /* all’interno del ciclo, subito prima di stack_push */
        printf("[READER-%d] lettura del blocco di offset %ld di %zu byte\n", r->id, (long)offset, rd);
        /* 5)  Pubblica il blocco nello stack condiviso */
        stack_push(r->stack, &blk);

        offset += rd;
    }

    printf("[READER-%d] lettura del file '%s' completata\n", r->id, r->src_path);
    fclose(fp);
    return NULL;
}

/**
 * @brief Struttura `created_t` per tenere traccia dei file di destinazione già creati dal WRITER.
 */
typedef struct { char name[PATH_MAX]; int done; } created_t;

/**
 * @brief Funzione eseguita dal thread WRITER.
 * Il thread WRITER preleva i blocchi di dati dallo stack condiviso e li scrive nei file di destinazione.
 * Gestisce la creazione delle directory e dei file di destinazione, e la scrittura dei blocchi nelle posizioni corrette.
 * @param arg Puntatore a una struttura `writer_arg_t` contenente i parametri del thread.
 * @return NULL (i thread POSIX restituiscono un puntatore a void).
 */
static void *writer_thread(void *arg){
    writer_arg_t *w = arg;
    created_t *created = calloc(w->total_files, sizeof *created);
    int created_cnt = 0;

    /* ── 0)  Verifica/crea directory di destinazione ───────────── */
    struct stat st;
    if (stat(w->dest_dir, &st) != 0) {
        /* se non esiste, prova a crearla (permessi rwx per l’utente) */
        if (mkdir(w->dest_dir, 0700) != 0) {
            perror("mkdir (writer)");
            return NULL;
        }
    } else if (!S_ISDIR(st.st_mode)) {
        fprintf(stderr, "%s non è una directory\n", w->dest_dir);
        return NULL;
    }

    /* ── 1)  Ciclo di consumo dello stack ──────────────────────── */
    int done = 0;                            /* conteggio file completati */
    char dst_path[PATH_MAX * 2];             /* buffer per <dest>/<fname> */

    while (done < w->total_files) {
        block_t blk;
        stack_pop(w->stack, &blk); 

        int first_time = 1;
        for (int i = 0; i < created_cnt; ++i)
            if (strcmp(created[i].name, blk.fname) == 0) { first_time = 0; break; }
        
        if (first_time) {
            printf("[WRITER] creazione del file '%s' di dimensione %ld byte\n",
                blk.fname, (long)blk.file_size);

            if (created_cnt < w->total_files)           /* sicurezza */
                strncpy(created[created_cnt++].name, blk.fname, PATH_MAX);
            else
                fprintf(stderr, "WARNING: più file del previsto!\n");
        }

        /* Costruisci il percorso di output */
        snprintf(dst_path, sizeof dst_path, "%s/%s", w->dest_dir, blk.fname);

        /* Apri/crea il file in modalità “scrittura random” */
        int fd = open(dst_path, O_WRONLY | O_CREAT, 0644);
        if (fd < 0) {
            perror("open (writer)");
            continue;                        /* salta questo blocco ma non abortire */
        }

        /* Scrivi il blocco nella posizione corretta */
        ssize_t wr = pwrite(fd, blk.buf, blk.len, blk.offset);
        if (wr != (ssize_t)blk.len) {
            perror("pwrite");
        }
        printf("[WRITER] scrittura del blocco di offset %ld di %zu byte sul file '%s'\n",(long)blk.offset, blk.len, blk.fname);
        close(fd);

        /* Se questo era l’ultimo blocco di quel file, aggiorna il conteggio */
        if (blk.eof){
            printf("[WRITER] scrittura del file '%s' completata\n", blk.fname);    
            ++done;
        }
    }
    free(created);
    return NULL;
}

int main(int argc, char *argv[]){
    
    check_args(argc, argv); // Controlla gli argomenti passati al programma.
    const char *dest_dir = argv[argc - 1]; // L'ultimo argomento è la directory di destinazione.
    struct stat st;
    block_stack_t shared_stack;
    if(stack_init(&shared_stack) != 0)
        exit_with_error("stack_init");

    if (stat(dest_dir, &st) != 0)              // esiste/accessibile?
        exit_with_error("Errore nell'accesso alla directory di destinazione.");
    if (!S_ISDIR(st.st_mode))           // è una directory valida?
        exit_with_msg("Il percorso di destinazione non è una directory valida.");

    int n_files = argc - 2;
    printf("[MAIN] duplicazione di %d file\n", n_files);
    
    pthread_t  *reader_tid  = malloc(n_files * sizeof *reader_tid);
    reader_arg_t *reader_arg = malloc(n_files * sizeof *reader_arg);
    if (!reader_tid || !reader_arg) exit_with_error("malloc fallita");

    for (int i = 0; i < n_files; ++i) {
        strncpy(reader_arg[i].src_path, argv[1 + i], PATH_MAX);
        reader_arg[i].id = i + 1;
        reader_arg[i].src_path[PATH_MAX-1] = '\0';     /* sicurezza */
        reader_arg[i].stack = &shared_stack;

        if (pthread_create(&reader_tid[i], NULL,
                        reader_thread, &reader_arg[i])) {
            exit_with_msg("Errore creazione thread READER");
        }
    }

    writer_arg_t writer_arg = {
        .stack    = &shared_stack,
        .dest_dir = dest_dir,
        .total_files = n_files 
    };
    pthread_t writer_tid;
    if (pthread_create(&writer_tid, NULL, writer_thread, &writer_arg)) {
        exit_with_msg("Errore creazione thread WRITER");
    }

    for (int i = 0; i < n_files; ++i)
        pthread_join(reader_tid[i], NULL);

    pthread_join(writer_tid, NULL);

    free(reader_tid);
    free(reader_arg);
    stack_destroy(&shared_stack);
    printf("[MAIN] duplicazione di %d file completata\n", n_files);
    return EXIT_SUCCESS; // Il programma termina con successo.
}