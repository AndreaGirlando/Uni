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
    socketServer.sin_addr.s_addr = inet_addr("127.0.0.1");
    socketServer.sin_port = htons(9090);
    socketServer.sin_family = PF_INET;
    socklen_t lenSocketServer = sizeof(socketServer);

    if(connect(serverFD, (struct sockaddr*)&socketServer, lenSocketServer)<0){
        perror("Connect: ");
        exit(EXIT_FAILURE);
    }

    int n;
    printf("Inserisci il numero da inviare al server: ");
    scanf("%d", &n);
    n = htonl(n);
    if(send(serverFD, &n, sizeof(int), 0) < 0){
        perror("Send: ");
        exit(EXIT_FAILURE);
    }

    int res;
    int bytesRicevuti = recv(serverFD, (void *)&res, sizeof(res), 0);
    if(bytesRicevuti <= 0){
        if(bytesRicevuti == 0){
            printf("Il server ha chiuso la connessione");
            exit(EXIT_SUCCESS);
        }else{
            perror("Recv: ");
        }
    }
    res = ntohl(res);
    printf("Il numero arrivato dal server è: %d", res);


}