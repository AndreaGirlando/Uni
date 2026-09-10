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
    int serverFD = socket(PF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in socketServer;
    socketServer.sin_addr.s_addr = INADDR_ANY;
    socketServer.sin_port = htons(9095);
    socketServer.sin_family = PF_INET;
    socklen_t lenSocketServer = sizeof(socketServer);

    if(bind(serverFD, (struct sockaddr*)&socketServer, lenSocketServer)<0){
        perror("Bind: ");
        exit(EXIT_FAILURE);
    }
    printf("Server in ascolto sulla porta 8080 \n");

    while(1){
        struct sockaddr_in socketClient;
        socklen_t lenSocketClient = sizeof(socketClient);

        int res;
        int bytesRicevuti = recvfrom(serverFD, (void *)&res, sizeof(res), 0, (struct sockaddr*)&socketClient, &lenSocketClient);

        if(bytesRicevuti <= 0){
            if(bytesRicevuti == 0){
                printf("Il server ha chiuso la connessione\n");
                exit(EXIT_SUCCESS);
            }else{
                perror("Recv: ");
                exit(EXIT_FAILURE);
            }
        }
        res = ntohl(res);
        printf("Il numero arrivato dal client è: %d\n", res);
        res = htonl(res + 1);


        if(sendto(serverFD, (void*)&res, sizeof(int), 0, (struct sockaddr*)&socketClient, lenSocketClient)<0){
            perror("Send");
            exit(EXIT_FAILURE);
        }
    }


}