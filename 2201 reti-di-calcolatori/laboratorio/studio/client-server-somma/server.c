#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdlib.h>

#include "config.c"

int main(){
    int server_fd, client_fd;
    struct sockaddr_in serverSocket, clientSocket;

    server_fd = socket(PF_INET, SOCK_STREAM, 0);

    serverSocket.sin_addr.s_addr = INADDR_ANY;
    serverSocket.sin_family = PF_INET;
    serverSocket.sin_port = htons(8080);

    socklen_t serverSocketLen = sizeof(serverSocket);
    socklen_t clientSocketLen = sizeof(clientSocket);

    if(bind(server_fd, (struct sockaddr*)& serverSocket, serverSocketLen)<0){
        perror("Bind: ");
        exit(1);;
    }
    if(listen(server_fd, 4)<0){
        perror("Listen: ");
        exit(1);;
    }

    printf("\nServer acceso e in ascolto sulla porta %d\n", SERVER_PORT);

    while (1){
        client_fd = accept(server_fd, (struct sockaddr*)&clientSocket, &clientSocketLen);
        if(client_fd<0){
            perror("Accept: ");
            break;
        }
        pid_t pid = fork();
        if(pid == 0){
            close(server_fd); // sono nel figlio il socket del server non mi serve
            printf("\nConnessione al client accettata\n");

            while(1){
                int req[2];
                char sendBuffer[256];
                recv(client_fd, req, sizeof(req), 0);

                req[0] = htonl(req[0]);
                req[1] = htonl(req[1]);

                int sum = req[0]+req[1];

                printf("Il client ha richiesto al seguente somma: %d+%d il risultato calcolato è %d\n", req[0], req[1], sum);

                snprintf(sendBuffer, 256, "%d", sum);
                send(client_fd, sendBuffer, strlen(sendBuffer), 0);
            }


            close(client_fd);
            exit(0);
        }else{
            close(client_fd); // sono nel padre non mi serve il client
        }

    }



    return 0;
}