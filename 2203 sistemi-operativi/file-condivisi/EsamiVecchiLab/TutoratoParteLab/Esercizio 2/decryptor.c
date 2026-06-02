#include <stdio.h>
#include <stdlib.h> //malloc, free
#include <string.h> 
#include <pthread.h>

typedef struct {
    char *key;
    int index;
} thread_arg_t;

static void *thread_func(void *arg){
    thread_arg_t *targ = (thread_arg_t *) arg;

    printf("Thread %d avviato - Elaboro chiave %s\n", targ->index, targ->key);
    char filename[32];
    int ret = snprintf(filename, sizeof(filename), "%d.txt", targ->index);

    if(ret >= (int)sizeof(filename)){
        fprintf(stderr,"Errore");
        return NULL;
    }

    printf("Thread %d: scrivo in file %s\n", targ->index, filename);

    FILE *out = fopen(filename, "w");
    if(!out){
        fprintf(stderr, "Errore");
        return NULL;
    }

    fprintf(out, "%s\n", targ->key);

    if(fclose(out) != 0) {
        fprintf(stderr, "Thread, problema durante la chiusura del file");
    }

    printf("thread completato");

    return NULL; 
    //recuperato dal main tramite pthread_join()
}

int main(int agrc, char *argv[]){
    
    printf("[MAIN]: Decryptor started\n");
    if (agrc != 2){
        fprintf(stderr, "[MAIN]: ❌ Usage: ./decryptor keys.txt\n");
        return EXIT_FAILURE;
    }

    printf("[MAIN]: 📖 Leggo chiavi dal file %s\n", argv[1]);

    FILE *kf = fopen(argv[1], "r");
    if(!kf){
        fprintf(stderr, "[MAIN]: ❌ Impossibile aprire il file %s\n", argv[1]);
        perror("");
        return EXIT_FAILURE;
    }

    // getline()

    char *line = NULL;
    size_t len = 0;    //dimensione attuale 
                       //buffer
    ssize_t nread = 0; //caratteri letti nell'ultima chiamata

    char **keys = NULL ;
    //Array per puntatori a stringhe
    size_t n_keys = 0;

    printf("[MAIN]: Inizio Lettura\n");
    while((nread = getline(&line, &len, kf)) != -1) {
        printf("[MAIN] Letta riga di %zd caratteri \n", nread);

        if(nread > 0 && (line[nread-1] == '\n')){
            line[--nread] = '\0';
        }
        if(nread == 0){
           // vuol dire che c'è una riga vuota
        }

        char *key_copy = strdup(line);
        //strdup() = malloc(strlen(s)+1) + strcopy()
        if(!key_copy){
            fprintf(stderr, "[MAIN]: Mem Fault");
            perror("strdup");

            /* clean up in caso errore */
            fclose(kf);
            free(line);
            for(size_t i = 0; i < n_keys; ++i){
                free(keys[i]);
            }
            free(keys);

            return EXIT_FAILURE;
        }
        printf("[MAIN]: salvata chiave %s\n", key_copy);
        char **tmp = realloc(keys, (n_keys + 1) * sizeof(char *));
        if(!tmp){
            fprintf(stderr, "❌");
            perror("realloc");
            /* clean up in caso errore */
            fclose(kf);
            free(line);
            for(size_t i = 0; i < n_keys; ++i){
                free(keys[i]);
            }
            free(keys);

            return EXIT_FAILURE;
        }
        keys = tmp;
        keys[n_keys++] = key_copy;
    }
    printf("[MAIN]: Abbiamo finito di leggere\n");

    /* cleanup lettura file */
    free(line);
    fclose(kf);

    if(n_keys < 0){
        fprintf(stderr,"[MAIN]: ❌ servono almeno 2 chiavi");
        /* Cleanup */
        for(size_t i = 0; i< n_keys; ++i){
            free(keys[i]);
        }
        free(keys);
        return EXIT_FAILURE;
    }

    //quanti thread devo creare? esattamente quante chiavi ho
    printf("[MAIN]: creo %zu thread (UNO PER CHIAVE)\n", n_keys);

    pthread_t    *threads = malloc(n_keys * sizeof(pthread_t));
    thread_arg_t *args    = malloc(n_keys * sizeof(thread_arg_t));

    if(!threads || !args){
        fprintf(stderr, "❌ impossibile allocare memora");
        perror("malloc");

        /* Cleanup */
        free(threads);
        free(args);
        for(size_t i = 0; i < n_keys; ++i){
            free(keys[i]);
        }
        free(keys);
        return EXIT_FAILURE;
    }

    for(size_t i = 0; i < n_keys; i++){
        args[i].key = keys[i]; // Ogni thread riceve la SUA CHIAVE
        args[i].index = (int)i;
        
        printf("[MAIN]: Avvio thread %zu con chiave %s\n", i, keys[i]);
        
        int create_result = pthread_create(&threads[i], NULL, thread_func, &args[i]);
    }

    printf("[MAIN]: attendo che tutti i thread terminano");
    
    for(size_t i = 0; i < n_keys; i++){
        int join_result = pthread_join(threads[i], NULL);
        if (join_result != 0){
            fprintf(stderr, "Errore durante la join dei thread");
        } else  {
            printf("Thread %zu terminato\n", i);
        }

        free(keys[i]);
    }
    
    free(keys);
    free(threads);
    free(args);

    return EXIT_SUCCESS;
}