#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#include "config.c"

int main(){
    int server_fd;
    struct sockaddr_in serverSocket;

    server_fd = socket(PF_INET, SOCK_STREAM, 0);

    serverSocket.sin_port = htons(SERVER_PORT);
    serverSocket.sin_family = AF_INET;
    serverSocket.sin_addr.s_addr = inet_addr(SERVER_IP);

    socklen_t lenServerSocket = sizeof(serverSocket);

    if(connect(server_fd, (struct sockaddr *)&serverSocket, lenServerSocket) < 0){
        perror("Connect: ");
        return 1;
    }

    while (1){
        uint32_t array[2];
        printf("Inserisci i due numeri da sommare: \n");
        scanf("%d", &array[0]);
        scanf("%d", &array[1]);

        array[0] = htonl(array[0]);
        array[1] = htonl(array[1]);

        send(server_fd, array, sizeof(array), 0);

        char res[256];
        recv(server_fd, res, 256, 0);

        printf("Il risultato arrivato dal server è: %s\n", res);
    }
    close(server_fd);

    return 0;
}