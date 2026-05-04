/*---------------------------------------------------------------------------
 * mmap-reverse-parallel.c
 * -----------------------
 * Inverte un file in-place con mmap + pthreads. Ogni thread elabora una
 * porzione distinta della prima metà del file.
 *
 * Uso:
 *      ./mmap-reverse-parallel <file> <num_thread>
 *                (num_thread opzionale, default = numero logico CPU)
 *
 * Compilazione:
 *      gcc -Wall -Wextra -pthread mmap-reverse-parallel.c -o mmap-reverse-parallel
 *---------------------------------------------------------------------------*/

#include <fcntl.h>          /* open(), O_RDWR …                            */
#include <stdio.h>          /* printf(), perror()                          */
#include <stdlib.h>         /* exit(), EXIT_FAILURE / SUCCESS              */
#include <sys/mman.h>       /* mmap(), munmap(), PROT_READ/WRITE           */
#include <sys/stat.h>       /* struct stat, fstat()                        */
#include <unistd.h>         /* close(), sysconf()                          */
#include <stdint.h>         /* intmax_t                                    */
#include <pthread.h>        /* pthread_*                                   */

/* ========== Helper errori ============================================== */
static void exit_with_error(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}
static void exit_with_msg(const char *msg)
{
    fprintf(stderr, "[Error] %s\n", msg);
    exit(EXIT_FAILURE);
}

/* ========== Struttura argomenti thread ================================= */
typedef struct {
    char   *data;       /* puntatore mmap condiviso                        */
    off_t   start;      /* indice iniziale (incluso)                       */
    off_t   end;        /* indice finale   (escluso)                       */
    off_t   file_size;  /* dimensione totale file                          */
} thread_arg_t;

/* ========== Routine di inversione per ogni thread ====================== */
static void *reverse_chunk(void *arg_void)
{
    thread_arg_t *arg = (thread_arg_t *)arg_void;
    char *p   = arg->data;
    off_t N   = arg->file_size;

    for (off_t i = arg->start; i < arg->end; ++i) {
        char tmp            = p[i];
        p[i]                = p[N - i - 1];
        p[N - i - 1]        = tmp;
    }
    return NULL;
}

/* =================== main ============================================= */
int main(int argc, char *argv[])
{
    /* --- 1. Argomenti -------------------------------------------------- */
    if (argc != 2 && argc != 3)
        exit_with_msg("Usage: mmap-reverse-parallel <file> [num_thread]");

    int num_thr = (argc == 3) ? atoi(argv[2])
                               : 4;

    if (num_thr <= 0)
        exit_with_msg("num_thread must be > 0");

    /* --- 2. Apertura file e stat -------------------------------------- */
    int fd = open(argv[1], O_RDWR);
    if (fd < 0)
        exit_with_error(argv[1]);

    struct stat sb;
    if (fstat(fd, &sb) < 0)
        exit_with_error("fstat");

    if (!S_ISREG(sb.st_mode))
        exit_with_msg("Not a regular file");

    off_t size = sb.st_size;
    if (size < 2) {           /* 0-1 byte: niente da fare                  */
        printf("File troppo piccolo per inversione (%jd byte)\n",
               (intmax_t)size);
        close(fd);
        return EXIT_SUCCESS;
    }

    /* --- 3. mmap in R/W condiviso ------------------------------------- */
    char *data = mmap(NULL, size,
                      PROT_READ | PROT_WRITE,
                      MAP_SHARED, fd, 0);
    if (data == MAP_FAILED)
        exit_with_error("mmap");

    close(fd); /* fd non più necessario dopo mmap                         */

    /* --- 4. Preparazione thread --------------------------------------- */
    off_t half      = size / 2;                /* lavoriamo solo metà     */
    off_t chunk_len = half / num_thr;          /* divisione equa          */
    off_t remainder = half % num_thr;          /* byte residui            */

    /* Allocazione dinamica degli array per gli ID dei thread e gli argomenti */
    pthread_t *tid = calloc(num_thr, sizeof *tid);  /* Array per memorizzare gli ID dei thread */
    thread_arg_t *targ = calloc(num_thr, sizeof *targ); /* Array per memorizzare gli argomenti dei thread */
    
    /* Verifica che l'allocazione sia andata a buon fine */
    if (!tid || !targ)
        exit_with_msg("calloc");  /* Termina il programma se calloc fallisce */
    /*Allocates a zero-initialised block big enough for num_thr elements, each the size of one pthread_t object.
    Using sizeof *tid (instead of sizeof(pthread_t)) is an idiom that automatically picks up the correct type even if the variable’s type changes later.*/
    
    off_t cursor = 0;
    for (int t = 0; t < num_thr; ++t) {
        off_t extra = (t < remainder) ? 1 : 0; /* distribuiamo residui    */
        /*
        Se l’indice del thread t è più piccolo di remainder, quel thread riceve 1 byte in più (extra = 1). 
        I primi remainder thread risultano quindi leggermente più “grandi”.
        */
        targ[t].data      = data;
        targ[t].start     = cursor;
        targ[t].end       = cursor + chunk_len + extra;
        targ[t].file_size = size;

        if (pthread_create(&tid[t], NULL, reverse_chunk, &targ[t]) != 0)
            exit_with_error("pthread_create");

        cursor = targ[t].end;
    }

    /* --- 5. Join dei thread ------------------------------------------ */
    for (long t = 0; t < num_thr; ++t)
        if (pthread_join(tid[t], NULL) != 0)
            exit_with_error("pthread_join");

    /* --- 6. Cleanup --------------------------------------------------- */
    free(tid);
    free(targ);

    if (munmap(data, size) < 0)
        exit_with_error("munmap");

    printf("File '%s' invertito con successo usando %d thread\n",
           argv[1], num_thr);

    return EXIT_SUCCESS;
}
