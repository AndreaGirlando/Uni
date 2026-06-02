#include <fcntl.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define KEYS_SIZE 30
#define BUFFER_SIZE 100

typedef struct shared_data
{
    char buffer[BUFFER_SIZE];
    sem_t buffer_sem; // gestisce l'accesso al buffer
    int exit;
} shared_data_t;

typedef struct thread_data
{
    char key[KEYS_SIZE];
    int index;
    shared_data_t *data;
    sem_t read_sem;  // per bloccare il thread in attesa
    sem_t write_sem; // per sincronizzare il completamento
} thread_data_t;

char *decrypt(char *text, char *keys)
{
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n = strlen(text);
    
    char *dec_text = (char *)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++)
    {
        // strchr trova la prima occorrenza di un carattere e restituisce un puntatore
        char *index_c = strchr(keys, text[i]);
        if (index_c != NULL)
        {
            int index = index_c - keys;
            dec_text[i] = alphabet[index];
        }
        else
        {
            dec_text[i] = text[i];
        }
    }
    dec_text[n] = '\0'; // null terminator
    return dec_text;
}

int parse_text(char *text, char *cifar_text, int *index_key)
{
    int sep_index = -1;
    int len = strlen(text);
    
    // Trova il separatore ':'
    for (int i = 0; i < len; i++)
    {
        if (text[i] == ':')
        {
            sep_index = i;
            break;
        }
    }
    if (sep_index < 0)
        return -1;

    // Estrae l'indice della chiave
    char *index_text = (char *)calloc(sep_index + 1, sizeof(char));
    strncpy(index_text, text, sep_index);
    index_text[sep_index] = '\0';

    // Estrae il testo cifrato (rimuove anche il newline finale se presente)
    int cipher_len = 0;
    for (int i = sep_index + 1; i < len && text[i] != '\n' && text[i] != '\0'; i++, cipher_len++)
    {
        cifar_text[cipher_len] = text[i];
    }
    cifar_text[cipher_len] = '\0';

    *index_key = atoi(index_text);
    free(index_text);
    return 0;
}

void *thread_function(void *args)
{
    thread_data_t *dt = (thread_data_t *)args;
    printf("[K%d] chiave assegnata: %s\n", dt->index, dt->key);
    
    char local_buffer[BUFFER_SIZE];
    
    while (1)
    {
        // Attende di essere risvegliato
        sem_wait(&dt->read_sem);
        
        // Controlla se deve terminare
        if (dt->data->exit != 0)
        {
            break;
        }

        // Copia il buffer condiviso in locale
        sem_wait(&dt->data->buffer_sem);
        strcpy(local_buffer, dt->data->buffer);
        sem_post(&dt->data->buffer_sem);
        
        printf("[K%d] sto decifrando la frase di %d caratteri\n", dt->index, (int)strlen(local_buffer));

        // Decifra il testo
        char *dec = decrypt(local_buffer, dt->key);
        
        // Rimette il risultato nel buffer condiviso
        sem_wait(&dt->data->buffer_sem);
        strcpy(dt->data->buffer, dec);
        sem_post(&dt->data->buffer_sem);
        
        free(dec);

        // Notifica al main thread che ha completato
        sem_post(&dt->write_sem);
    }
    return NULL;
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Uso: %s <file_chiavi> <file_cifrato> [file_output]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *keys_input_filename = argv[1];
    char *cifar_input_filename = argv[2];
    char *output_filename = argc > 3 ? argv[3] : "output.txt";

    printf("[M] Leggo il file delle chiavi\n");
    FILE *key_fp = fopen(keys_input_filename, "r");
    if (key_fp == NULL)
    {
        perror("Errore nell'apertura del file delle chiavi");
        exit(EXIT_FAILURE);
    }

    // Conta il numero di chiavi
    int num_keys = 0;
    char temp_buffer[KEYS_SIZE];
    while (fgets(temp_buffer, KEYS_SIZE, key_fp) != NULL)
    {
        num_keys++;
    }
    fseek(key_fp, 0, SEEK_SET);

    printf("[M] trovate %d chiavi, creo i thread K-i necessari\n", num_keys);

    // Inizializza i dati condivisi
    shared_data_t *data = (shared_data_t *)malloc(sizeof(shared_data_t));
    data->exit = 0;
    
    if (sem_init(&data->buffer_sem, 0, 1) < 0)
    {
        perror("Errore nella creazione del semaforo buffer_sem");
        exit(EXIT_FAILURE);
    }

    // Crea i dati per i thread
    thread_data_t **thread_data_array = (thread_data_t **)malloc(sizeof(thread_data_t *) * num_keys);
    
    for (int j = 0; j < num_keys; j++)
    {
        if (fgets(temp_buffer, KEYS_SIZE, key_fp) == NULL)
        {
            fprintf(stderr, "Errore nella lettura delle chiavi\n");
            exit(EXIT_FAILURE);
        }
        
        // Rimuove il newline dalla chiave se presente
        temp_buffer[strcspn(temp_buffer, "\n")] = '\0';
        
        thread_data_t *item = (thread_data_t *)malloc(sizeof(thread_data_t));
        item->data = data;
        item->index = j;
        strcpy(item->key, temp_buffer);
        thread_data_array[j] = item;

        // Inizializza i semafori per questo thread
        if (sem_init(&item->read_sem, 0, 0) < 0)
        {
            perror("Errore nella creazione del semaforo read_sem");
            exit(EXIT_FAILURE);
        }
        
        if (sem_init(&item->write_sem, 0, 0) < 0)
        {
            perror("Errore nella creazione del semaforo write_sem");
            exit(EXIT_FAILURE);
        }
    }
    fclose(key_fp);

    // Crea i thread
    pthread_t *threads = (pthread_t *)malloc(sizeof(pthread_t) * num_keys);
    for (int i = 0; i < num_keys; i++)
    {
        if (pthread_create(&threads[i], NULL, thread_function, thread_data_array[i]) < 0)
        {
            perror("Errore nella creazione del thread");
            exit(EXIT_FAILURE);
        }
    }

    printf("[M] Processo il file cifrato\n");
    FILE *cif_fp = fopen(cifar_input_filename, "r");
    if (cif_fp == NULL)
    {
        perror("Errore nell'apertura del file cifrato");
        exit(EXIT_FAILURE);
    }

    // Apre il file di output
    FILE *out_fp = fopen(output_filename, "w");
    if (out_fp == NULL)
    {
        perror("Errore nella creazione del file di output");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    char cifar_text[BUFFER_SIZE];
    int cifar_index;
    
    // Processa ogni riga del file cifrato
    while (fgets(buffer, BUFFER_SIZE, cif_fp) != NULL)
    {
        if (parse_text(buffer, cifar_text, &cifar_index) < 0)
        {
            fprintf(stderr, "Formato del file cifrato non valido alla riga: %s", buffer);
            continue;
        }

        // Verifica che l'indice della chiave sia valido
        if (cifar_index < 0 || cifar_index >= num_keys)
        {
            fprintf(stderr, "Indice chiave non valido: %d\n", cifar_index);
            continue;
        }

        printf("[M] la riga '%s' deve essere decifrata con la chiave n. %d\n", cifar_text, cifar_index);

        // Carica il testo cifrato nel buffer condiviso
        sem_wait(&data->buffer_sem);
        strcpy(data->buffer, cifar_text);
        sem_post(&data->buffer_sem);

        // Risveglia il thread corrispondente
        sem_post(&thread_data_array[cifar_index]->read_sem);
        
        // Attende che il thread completi la decifratura
        sem_wait(&thread_data_array[cifar_index]->write_sem);

        // Legge il risultato
        sem_wait(&data->buffer_sem);
        strcpy(buffer, data->buffer);
        sem_post(&data->buffer_sem);

        printf("[M] la riga è stata decifrata in: %s\n", buffer);
        
        // Scrive il risultato sul file di output
        fprintf(out_fp, "%s\n", buffer);
        fflush(out_fp);
    }
    
    fclose(cif_fp);
    fclose(out_fp);

    printf("[M] Decifratura completata. Output salvato in: %s\n", output_filename);

    // Chiusura pulita del programma
    data->exit = 1;
    
    // Risveglia tutti i thread per farli terminare
    for (int i = 0; i < num_keys; i++)
    {
        sem_post(&thread_data_array[i]->read_sem);
        pthread_join(threads[i], NULL);

        sem_destroy(&thread_data_array[i]->read_sem);
        sem_destroy(&thread_data_array[i]->write_sem);
        free(thread_data_array[i]);
    }

    free(thread_data_array);
    free(threads);
    sem_destroy(&data->buffer_sem);
    free(data);

    return 0;
}