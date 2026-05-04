#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define PAUSE 8;

int main(int argc, char *argv[]){
    pid_t pid;
    char *process_name = "parent";
    int X = 5;
    int pause_father, pause_child;

    if(argc > 1 && strcmp(argv[1], "slow-child") == 0){
        printf("test con figlio lento che termina dopo il padre\n");
        pause_child = PAUSE;
        pause_father = 0;
    } else {
        printf("test con figlio veloce che termina prima del padre\n");
        pause_child = 0;
        pause_father = PAUSE;
    }

    printf("[%s] pid: %d, ppid: %d, X= %d\n", process_name, getpid(), getppid(), X);

    //fork
    printf("[%s] fork...\n", process_name);
    pid = fork ();
    // if ((pid = fork()) == -1) -> errore
    if (pid == 0) {
        process_name = "child";
        printf("[%s] X++", process_name);
        X++;

        if(pause_child > 0){
            printf(" [%s] pausa ...\n", process_name);
            sleep(pause_child);
        }
    } else {
        // codice del padre
        process_name = "parent";
        printf("[%s] X--", process_name);
        X--;

        if(pause_father > 0){
            printf(" [%s] pausa ...\n", process_name);
            sleep(pause_father);
        }
    }

    //codice eseguito da entrambi
    printf("[%s] pid: %d, ppid: %d, X= %d\n", process_name, getpid(), getppid(), X);
    printf("[%s] exit...\n", process_name);
    exit(EXIT_SUCCESS);
}