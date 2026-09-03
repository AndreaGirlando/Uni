#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <time.h>
#include <stdlib.h>


#include "config.c"

char* win = "Hai vinto!";
char* lose = "Hai perso! riprova";

void* threadWork(void* args){
    int* tempArg = (int*)args;
    int client_fd = *tempArg;
    int n = rand()%100;

    printf("Sono un thread di risposta e sto rispondendo al client: %d [Ho scelto il numero %d]\n", client_fd, n);

    for(;;){
        int m;

        int bytesRicevuti = recv(client_fd, &m, sizeof(m), 0);

        // printf("[DEBUG] Bytes ricevuti %d", bytesRicevuti);

        if(bytesRicevuti>0){
            // printf("[DEBUG]: il client ha inviato: %d\n", m);
            if(ntohl(m) == n){
                send(client_fd, (void*)win, strlen(win), 0);
                break;
            }
            send(client_fd, (void*)lose, strlen(lose), 0);
        }else{
            perror("recv: ");
            break;
        }
    }


    close(client_fd);
    return 0;
}

int main(){

    int server_fd;
    struct sockaddr_in socketServer;

    socketServer.sin_addr.s_addr = inet_addr(SERVER_ADDRS);
    socketServer.sin_family = PF_INET;
    socketServer.sin_port = htons(SERVER_PORT);

    socklen_t socketServerlen = sizeof(socketServer);

    server_fd = socket(PF_INET, SOCK_STREAM, 0);

    if(bind(server_fd, (struct sockaddr*)&socketServer, socketServerlen)<0){
        perror("Bind: ");
        return 1;
    }
    if(listen(server_fd, 4)<0){
        perror("Listen: ");
        return 1;
    }

    printf("Server avviato e in ascolto sulla porta %d\n", SERVER_PORT);

    for(;;){
        struct sockaddr_in socketClient;
        socklen_t socketClientLen = sizeof(socketClient);
        int temp = accept(server_fd, (struct sockaddr*)&socketClient, &socketClientLen);

        int* client_fd = malloc(sizeof(int));
        client_fd = &temp;

        pthread_t clientThread;
        if(client_fd > 0){
            pthread_create(&clientThread, NULL, threadWork, (void*)client_fd);
        }
    }

    return 0;
}
