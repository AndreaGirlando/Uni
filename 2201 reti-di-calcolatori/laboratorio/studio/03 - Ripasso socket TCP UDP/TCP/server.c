#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

int main(){
    fflush(stdout);
    int serverFD = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socketServer;
    socketServer.sin_addr.s_addr = INADDR_ANY;
    socketServer.sin_port = htons(9090);
    socketServer.sin_family = PF_INET;
    socklen_t lenSocketServer = sizeof(socketServer);

    if(bind(serverFD, (struct sockaddr*)&socketServer, lenSocketServer)<0){
        perror("Bind: ");
        exit(EXIT_FAILURE);
    }

    if(listen(serverFD, 4)<0){
        perror("Listen: ");
        exit(EXIT_FAILURE);
    }

    printf("Server in ascolto sulla porta 8080 \n");

    while(1){

        int clientFd;
        struct sockaddr_in socketClient;
        socklen_t lenSocketClient = sizeof(socketClient);

        clientFd = accept(serverFD, (struct sockaddr*)&socketClient, &lenSocketClient);

        if(clientFd < 0){
            perror("Accept: ");
            exit(EXIT_FAILURE);
        }

        int res;
        int bytesRicevuti = recv(clientFd, (void *)&res, sizeof(res), 0);

        if(bytesRicevuti <= 0){
            if(bytesRicevuti == 0){
                printf("Il server ha chiuso la connessione\n");
                exit(EXIT_SUCCESS);
            }else{
                perror("Recv: ");
            }
        }
        res = ntohl(res);
        printf("Il numero arrivato dal client è: %d\n", res);
        res = htonl(res + 1);


        if(send(clientFd, (void*)&res, sizeof(int), 0)<0){
            perror("Send");
            exit(EXIT_FAILURE);
        }
    }


}