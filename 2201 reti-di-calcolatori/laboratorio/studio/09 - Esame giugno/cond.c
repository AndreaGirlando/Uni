#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SERVER_PORT 8080
#define SERVER_ADDRS "127.0.0.1"
#define MAX_CLIENTS 10
#define BASELINE_PORT 5000

typedef struct message{
    int src; //id client sorgente
    int dst; // id client destinazione
    int type; //0 - broadcast, 1 - unicast
    int value; //valore scambiato

} message;

int create_server (uint16_t port){
    int socketServerFD ;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof (addr);
    if ((socketServerFD = socket (AF_INET , SOCK_DGRAM , 0)) < 0) {
        perror ("socket failed" );
        exit(EXIT_FAILURE);
    }
    memset (&addr, 0, sizeof (addr));
    addr.sin_family = AF_INET ;
    addr.sin_port = htons (port);
    addr.sin_addr .s_addr = htonl (INADDR_ANY );
    // Bind and listen
    if (bind(socketServerFD , (struct sockaddr *)&addr, sizeof (addr)) < 0) {
        perror ("bind failed" );
        exit(EXIT_FAILURE);
    }
    return socketServerFD ;
}