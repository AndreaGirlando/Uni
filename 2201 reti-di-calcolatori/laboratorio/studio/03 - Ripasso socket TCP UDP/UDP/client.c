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
    int clientFd = socket(PF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in socketServer;
    socketServer.sin_addr.s_addr = inet_addr("127.0.0.1");
    socketServer.sin_port = htons(9095);
    socketServer.sin_family = PF_INET;
    socklen_t lenSocketServer = sizeof(socketServer);

    int n;
    printf("Inserisci il numero da inviare al server: ");
    scanf("%d", &n);
    n = htonl(n);
    if(sendto(clientFd, &n, sizeof(int), 0, (struct sockaddr*) &socketServer, lenSocketServer) < 0){
        perror("Send: ");
        exit(EXIT_FAILURE);
    }

    int res;
    int bytesRicevuti = recvfrom(clientFd, (void *)&res, sizeof(res), 0, (struct sockaddr*) &socketServer, &lenSocketServer);
    if(bytesRicevuti <= 0){
        if(bytesRicevuti == 0){
            printf("Datagramma vuoto");
            exit(EXIT_SUCCESS);
        }else{
            perror("Recv: ");
        }
    }
    res = ntohl(res);
    printf("Il numero arrivato dal server è: %d", res);


}