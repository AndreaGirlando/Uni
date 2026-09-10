
#include "prot.c"

int create_server (uint16_t port){
    int socketServerFD ;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof (addr);
    if ((socketServerFD = socket (AF_INET , SOCK_STREAM , 0)) < 0) {
    perror ("socket failed" );
    return -1;
    }
    memset (&addr, 0, sizeof (addr));
    addr.sin_family = AF_INET ;
    addr.sin_port = htons (port);
    addr.sin_addr .s_addr = htonl (INADDR_ANY );
    // Bind and listen
    if (bind(socketServerFD , (struct sockaddr *)&addr, sizeof (addr)) < 0) {
        perror ("bind failed" );
        return -2;
    }
    if(listen(socketServerFD, MAX_CLIENTS)<0){
        perror("listen");
        return -2;
    }
    return socketServerFD ;
}

typedef struct clientInfo{
    int id;
    int clientFd;
    struct sockaddr_in socketClient;
    socklen_t socketClientLen;
    pthread_mutex_t fileMutex;
    char* path;
}clientInfo;

void scriviSuFile(char* path, pthread_mutex_t mutex, char* string){
    pthread_mutex_lock(&(mutex));

    FILE* file = fopen(path, "a");
    fprintf(file, string);
    fflush(file);
    fclose(file);

    pthread_mutex_unlock(&(mutex));
}

void* clientHandler(void* args){
    clientInfo* client = (clientInfo*)args;
    char temp[BUFSIZ] = "";
    snprintf(temp, BUFSIZ, "[THREAD-%d] Nuovo client connesso\n", client->id);
    scriviSuFile(client->path, client->fileMutex, temp);

    while(1){
        int n;
        int byteRicevuti = recv(client->clientFd, (void*)&n, sizeof(n), 0);
        if(byteRicevuti<=0){
            if(byteRicevuti == 0){
                printf("Il client ha chiuso la connessione \n");
                break;
            }else{
                perror("recv");
                exit(EXIT_FAILURE);
            }
        }
        n = ntohl(n);

        snprintf(temp, BUFSIZ, "[THREAD-%d] Ha inviato %d\n", client->id, n);
        scriviSuFile(client->path, client->fileMutex, temp);

        n = htonl(n + rand()%256);
        if(send(client->clientFd, (void*)&n, sizeof(int), 0)<0){
            perror("send");
        }
        n = ntohl(n);
        snprintf(temp, BUFSIZ, "[THREAD-%d] Il server ha risposto con %d\n", client->id, n);
        scriviSuFile(client->path, client->fileMutex, temp);
    }

    close(client->clientFd);
    free(client);
    return NULL;
}

int main(){
    int serverFd = create_server(SERVER_PORT);
    pthread_mutex_t mutex;
    pthread_mutex_init(&(mutex), 0);
    char* path = "log.log";

    scriviSuFile(path, mutex, "Server avviato e in ascolto\n");

    while(1){
        clientInfo *client = malloc(sizeof(clientInfo));
        client->clientFd = 0;
        client->id = rand()%256;
        client->socketClientLen = sizeof(client->socketClient);
        client->fileMutex = mutex;
        client->path = path;
        if((client->clientFd = accept(serverFd, (struct sockaddr*)&(client->socketClient), &(client->socketClientLen)))<0){
            perror("accept");
        }
        pthread_t th;
        pthread_create(&(th), NULL, clientHandler, (void*)client);
        pthread_detach(th);
    }


}