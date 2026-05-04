#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <ctype.h>

#define KEYS_SIZE 30
#define BUFFER_SIZE 100

typedef struct shared_data
{
    char buffer[BUFFER_SIZE];
    pthread_mutex_t buffer_mutex; // ha la funzione di gestire l'accesso al buffer
    int exit;
    // semafori
} shared_data_t;

typedef struct thread_data
{
    char key[KEYS_SIZE];
    int index;
    shared_data_t *data;
    pthread_mutex_t read_mutex;
    pthread_mutex_t write_mutex;

} thread_data_t;

char *decrypt(char *text, char *keys)
{
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n = strlen(text);
    int v = strlen(keys);

    char *dec_text = (char *)malloc(sizeof(char) * n);
    for (int i = 0; i < n; i++)
    {
        // strchr trova la prima occurenza di un carattere è restituisce un puntatore a tale char
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
    return dec_text;
}

int parse_text(char *text, char *cifar_text, int *index_key)
{
    int sep_index = -1;
    int len = strlen(text);
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

    char *index_text = (char *)calloc(sep_index,sizeof(char));
    for (int i = 0; i < sep_index; i++)
    {
        index_text[i] = text[i];
    }

    for (int i = sep_index + 1, j = 0; i < len - 1; i++, j++)
    {
        cifar_text[j] = text[i];
    }

    *index_key = atoi(index_text);
    free(index_text);
    return 0;
}

void *thread_function(void *args)
{
    thread_data_t *dt = (thread_data_t *)args;
    printf("[K%d] chiave assegnata : %s", dt->index, dt->key);
    char buffer[BUFFER_SIZE];
    while (dt->data->exit == 0)
    {
        // blocco il thread
        pthread_mutex_lock(&dt->read_mutex);
        if (dt->data->exit != 0)
            break;

        pthread_mutex_lock(&dt->data->buffer_mutex);
        strcpy(buffer, dt->data->buffer);
        int d = strlen(buffer);
        printf("[K%d] sto decifando la frase di %d  caratteri passata dal main\n", dt->index, d);

        char *dec = decrypt(buffer, dt->key);
        strcpy(dt->data->buffer, dec);
        free(dec);

        pthread_mutex_unlock(&dt->data->buffer_mutex);

        //  notificare al main che ha completato
        pthread_mutex_unlock(&dt->write_mutex);
    }
    return NULL;
}

void main(int argc, char **argv)
{
    if (argc < 3)
    {
        perror("Numero di parametri non valido");
        exit(EXIT_FAILURE);
    }

    char *keys_input_filename = argv[1];
    char *cifar_input_filename = argv[2];
    char *ouput_filename = argc > 3 ? argv[3] : "output.txt";

    printf("[M] Leggo il file delle chiavi");
    FILE *key_fp = fopen(keys_input_filename, "r");
    if (key_fp == NULL)
    {
        perror("File delle chiavi non valido");
        exit(EXIT_FAILURE);
    }

    int num_keys = 0;
    while (!feof(key_fp))
    {
        if (fgetc(key_fp) == '\n')
        {
            num_keys++;
        }
    }
    fseek(key_fp, 0, SEEK_SET);

    printf("[M] trovate %d chiavi, creo i thread k-i necessari\n", num_keys);

    shared_data_t *data = (shared_data_t *)malloc(sizeof(shared_data_t));
    data->exit = 0;
    thread_data_t **thread_data_array = (thread_data_t **)malloc(sizeof(thread_data_t *) * num_keys);

    int j = 0;
    char key_buffer[KEYS_SIZE];
    while (fgets(key_buffer, KEYS_SIZE, key_fp) != NULL)
    {
        thread_data_t *item = (thread_data_t *)malloc(sizeof(thread_data_t));
        item->data = data;
        item->index = j;
        strcpy(item->key, key_buffer);
        thread_data_array[j] = item;

        if (pthread_mutex_init(&item->read_mutex,NULL) < 0)
        {
            perror("Errore nella creazione del semaforo rread_mutex");
            exit(EXIT_FAILURE);
        }
        pthread_mutex_lock(&item->read_mutex);
        if (pthread_mutex_init(&item->write_mutex,NULL) < 0)
        {
            perror("Errore nella creazione del semaforo write_mutex");
            exit(EXIT_FAILURE);
        }
         pthread_mutex_lock(&item->write_mutex);

        j++;
    }
    fclose(key_fp);

    if (pthread_mutex_init(&data->buffer_mutex,NULL) < 0)
    {
        perror("Errore nella creazione del semaforo buffer_mutex");
        exit(EXIT_FAILURE);
    }

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

    char buffer[BUFFER_SIZE];
    char cifar_text[BUFFER_SIZE];
    int cifar_index;
    while (fgets(buffer, BUFFER_SIZE, cif_fp) != NULL)
    {
        if (parse_text(buffer, cifar_text, &cifar_index) < 0)
        {
            perror("File cifrato non valido");
            exit(EXIT_FAILURE);
        }

        printf("[M] la riga '%s' deve essere decifrata con la chiave n. %d\n", cifar_text, cifar_index);

        pthread_mutex_lock(&data->buffer_mutex);
        pthread_mutex_unlock(&thread_data_array[cifar_index]->read_mutex);
        strcpy(data->buffer, cifar_text);
        pthread_mutex_unlock(&data->buffer_mutex);
        pthread_mutex_lock(&thread_data_array[cifar_index]->write_mutex);

        // sem_wait(&data->buffer_mutex);
        strcpy(buffer, data->buffer);
        // sem_post(&data->buffer_mutex);

        printf("[M] la riga e' stata decifrata in %s\n", buffer);
    }
    fclose(cif_fp);

    // chiusura pulita del programma
    data->exit = 1;
    for (int i = 0; i < num_keys; i++)
    {
        pthread_mutex_unlock(&thread_data_array[i]->read_mutex);
        pthread_join(threads[i], NULL);

        pthread_mutex_destroy(&thread_data_array[i]->read_mutex);
        pthread_mutex_destroy(&thread_data_array[i]->write_mutex);
        free(thread_data_array[i]);
    }

    free(thread_data_array);
    pthread_mutex_destroy(&data->buffer_mutex);
    free(data);
}