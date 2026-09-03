#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

int main(){
    fflush(stdout);
    int client_fd, server_fd;
    struct sockaddr_in socketServer;

    server_fd = socket(PF_INET, SOCK_DGRAM, 0);

    socketServer.sin_family = PF_INET;
    socketServer.sin_addr.s_addr = inet_addr(SERVER_ADDRS);
    socketServer.sin_port = htons(SERVER_PORT);
    socklen_t lenSocketServer = sizeof(socketServer);

    if(bind(server_fd, (struct sockaddr*)&socketServer, lenSocketServer)<0){
        perror("Bind: \n");
        exit(1);
    }

    printf("Server avviato sulla porta %d\n", SERVER_PORT);

    // if(listen(server_fd, 4)<4){
    //     perror("Listen: ");
    //     exit(1);
    // }
    //! non ho capito perché no

    for(;;){
        data datiSatellite;

        struct sockaddr_in socketClient;
        socklen_t lenSocketClient = sizeof(socketClient);

        int bytes = recvfrom(server_fd, &datiSatellite, sizeof(data), 0, (struct sockaddr*)&socketClient, &lenSocketClient);

        if(bytes == -1){
            perror("recvfrom: \n");
            continue;
        }

        if(bytes>0){
            printf("[%s:%d - %d bytes] Id: %d - Altitudine: %d - Batteria: %d\n",
                inet_ntoa(socketClient.sin_addr),
                ntohs(socketClient.sin_port),
                bytes,
                ntohl(datiSatellite.id),
                ntohl(datiSatellite.altitudine),
                ntohl(datiSatellite.batteria)
            );
        }

    }


    printf("\n");
    return 0;
}