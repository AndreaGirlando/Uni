#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

#define CONTROL_ADDRS "127.0.0.1"
#define CONTROL_PORT 8000
#define CENTRAL_ADDRS "127.0.0.1"
#define CENTRAL_PORT 8561

#define MAX_CLIENTS 10

#define TEMPO 5;


typedef struct msgSensore{
    int temperatura;
    int umidita;
    int aria;
    int isAllarmeRientrato;
} msgSensore;

typedef struct msgCentrale{
    int idSensore;
    int inAllarme;
} msgCentrale;

typedef struct clientInfo{
    int id;
    struct sockaddr_in socket;
    int socketFd;
    socklen_t socketLen;
} clientInfo;

typedef struct threadData{
    struct clientInfo* client;
    int socketServerControllo;
} threadData;