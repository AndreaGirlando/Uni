#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "config.h"

int main(){
    srand(time(NULL));

    int server_fd = socket(PF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in serverSocket;
    serverSocket.sin_addr.s_addr  = inet_addr(SERVER_ADDRS);
    serverSocket.sin_family = PF_INET;
    serverSocket.sin_port = htons(SERVER_PORT);

    socklen_t serverSocketLen = sizeof(serverSocket);

    while (1){
        data datiSatellite;
        datiSatellite.altitudine = htonl(rand()%500);
        datiSatellite.batteria = htonl(rand()%100);
        datiSatellite.id = htonl(rand());

        printf("Invio dati con id: %d\n", ntohl(datiSatellite.id));
        sendto(server_fd, (void*)&datiSatellite, sizeof(data), 0, (struct sockaddr*)&serverSocket, serverSocketLen);



        sleep(2);
    }



    printf("\n");
    return 0;
}