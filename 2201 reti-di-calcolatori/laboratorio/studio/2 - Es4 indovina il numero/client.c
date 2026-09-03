#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <stdlib.h>

#include "config.c"

int main(){

    int client_fd = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socketServer;
    socketServer.sin_addr.s_addr = inet_addr(SERVER_ADDRS);
    socketServer.sin_family = PF_INET;
    socketServer.sin_port = htons(SERVER_PORT);
    socklen_t socketServerlen = sizeof(socketServer);

    if(connect(client_fd, (struct sockaddr*) &socketServer, socketServerlen) == -1){
        perror("Connect: ");
        return 1;
    }

    for(;;){
        int n;
        printf("Inserisci un numero: \n");
        scanf("%d", &n); n = htonl(n);
        int byteInviati = send(client_fd, (void*)&n, sizeof(n), 0);

        if(byteInviati == -1){
            perror("Send: ");
        }

        char buffer[BUFSIZ];
        int byteRicevuti = recv(client_fd, buffer, BUFSIZ, 0);
        if(byteRicevuti == 0){
            printf("Il server ha chiuso la connessione\n");
            exit(0);
        }
        else if(byteRicevuti == -1){
            perror("Recv");
            exit(1);
        }

        buffer[byteRicevuti] = '\0';

        if(strstr(buffer, "Hai vinto")){
            printf("Hai vinto!");
            break;
        }

        printf("%s\n", buffer);

    }

    close(client_fd);

    return 0;
}
