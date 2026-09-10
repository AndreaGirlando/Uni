#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENT 10
#define SERVER_ADDRS "127.0.0.1"
#define SERVER_PORT 9578
#define REG 0
#define SET 1
#define QUIT 2
#define LIST 3
#define SERVER 4

typedef struct client_info{
    int id;
    int valore;
    struct sockaddr_in socketClient;
    socklen_t socketClientLen;
    int socketFd;
} clientInfo;

typedef struct client_list{
    pthread_mutex_t mutex;
    clientInfo** clients;
    int count;
} ClientList;

typedef struct message{
    int messageType; // 0 = reg / 1 = set / 2 = quit / 3 = list / 4 = server
    int request;
    char response[BUFSIZ];
} message;