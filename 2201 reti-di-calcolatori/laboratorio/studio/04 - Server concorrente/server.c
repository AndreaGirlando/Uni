#include "protocollo.c"

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
    if (listen(socketServerFD , MAX_CLIENT) < 0) {
        perror ("listen failed" );
        return -2;
    }
    return socketServerFD ;
}

int reg(ClientList* clientList, clientInfo* client){ //0 operazione eseguita correttamente - 1 operazione fallita
    int trovato = 0;
    pthread_mutex_lock(&(clientList->mutex));
    for(int i = 0; i < clientList->count; i++){
        if((clientList->clients)[i]->id == client->id){
            trovato = 1;
        }
    }

    if(trovato == 0){
        if(clientList->count == 10){
            pthread_mutex_unlock(&(clientList->mutex));
            return 1;
        }
        clientList->clients[clientList->count] = client;
        clientList->count++;
        pthread_mutex_unlock(&(clientList->mutex));
        return 0;
    }else{
        pthread_mutex_unlock(&(clientList->mutex));
        return 1;
    }
}

int quit(ClientList* clientList, clientInfo* client){ //0 operazione eseguita correttamente - 1 operazione fallita

    pthread_mutex_lock(&(clientList->mutex));
    for(int i = 0; i < clientList->count; i++){
        if((clientList->clients)[i]->id == client->id){
            for(int j = i; j < clientList->count-1; j++){
                clientList->clients[j] = clientList->clients[j+1];
            }
            clientList->count--;
            clientList->clients[clientList->count] = NULL;
            pthread_mutex_unlock(&(clientList->mutex));
            return 0;
        }
    }
    pthread_mutex_unlock(&(clientList->mutex));
    return 1;
}

int set(ClientList* clientList, clientInfo* client, int valore){ //0 operazione eseguita correttamente - 1 operazione fallita

    pthread_mutex_lock(&(clientList->mutex));
    for(int i = 0; i < clientList->count; i++){
        if((clientList->clients)[i]->id == client->id){
            clientList->clients[i]->valore = valore;
            pthread_mutex_unlock(&(clientList->mutex));
            return 0;
        }
    }
    pthread_mutex_unlock(&(clientList->mutex));
    return 1;
}

char* list(ClientList* clientList, char* list){ //0 operazione eseguita correttamente - 1 operazione fallita

    pthread_mutex_lock(&(clientList->mutex));
    for(int i = 0; i < clientList->count; i++){
        char temp[BUFSIZ];
        snprintf(temp, sizeof(temp), "ID: %d - VALORE: %d\n", clientList->clients[i]->id, clientList->clients[i]->valore);
        strcat(list, temp);
    }
    pthread_mutex_unlock(&(clientList->mutex));
    return list;
}

typedef struct threadData{
    clientInfo* client;
    ClientList* clientList;
}threadData;

void* clientHandler(void* args){
    threadData* data = (threadData*)args;
    printf("[THREAD] Sto gestendo il client con id=%d\n", data->client->id);

    message* rcvMSG = malloc(sizeof(message));
    message* sndMSG = malloc(sizeof(message));

    while(1){
        int byteRicevuti = recv(data->client->socketFd, rcvMSG, sizeof(*rcvMSG), 0);
        if(byteRicevuti<=0){
            if(byteRicevuti == 0) {
                printf("Il client ha chiuso la connessione\n");
                break;
            }else{
                perror("recv");
            }
        }


        rcvMSG->messageType = ntohl(rcvMSG->messageType);
        rcvMSG->request = ntohl(rcvMSG->request);

        sndMSG->request = ntohl(0);
        sndMSG->messageType = htonl(SERVER);

        if(rcvMSG->messageType == REG){
            printf("[THREAD] il client ha richiesto una REG\n");
            reg(data->clientList, data->client);
            strcpy(sndMSG->response, "Il comando REG è stato eseguito\n");
            send(data->client->socketFd, sndMSG, sizeof(*sndMSG), 0);
        }
        else if(rcvMSG->messageType == SET){
            printf("[THREAD] il client ha richiesto una SET\n");
            set(data->clientList, data->client, rcvMSG->request);
            strcpy(sndMSG->response, "Il comando SET è stato eseguito\n");
            send(data->client->socketFd, sndMSG, sizeof(*sndMSG), 0);
        }
        else if(rcvMSG->messageType == LIST){
            printf("[THREAD] il client ha richiesto una LIST\n");
            char stringa[BUFSIZ] = "";
            list(data->clientList, stringa);
            snprintf(sndMSG->response, sizeof(sndMSG->response), "Il comando LIST è stato eseguito - di seguito la lista risultante:\n%s",stringa);
            send(data->client->socketFd, sndMSG, sizeof(*sndMSG), 0);
        }
        else if(rcvMSG->messageType == QUIT){
            printf("[THREAD] il client ha richiesto una QUIT\n");
            printf("%d\n", quit(data->clientList, data->client));
            strcpy(sndMSG->response, "Il comando QUIT è stato eseguito\n");
            send(data->client->socketFd, sndMSG, sizeof(*sndMSG), 0);
            close(data->client->socketFd);
            break;
        }
        else{
            printf("Comando non supportato %d-%d\n", rcvMSG->messageType, rcvMSG->request);
        }
    }

    return NULL;
}

int main(){

    int socketServer = create_server(SERVER_PORT);
    ClientList* clientList = malloc(sizeof(ClientList));
    pthread_mutex_init(&(clientList->mutex), 0);
    clientList->clients = malloc(sizeof(clientInfo*)*MAX_CLIENT);
    clientList->count = 0;

    printf("Server in ascolto sulla porta %d\n", SERVER_PORT);

    while(1){
        clientInfo* client = malloc(sizeof(clientInfo));
        client->socketClientLen = sizeof((client->socketClient));
        client->id = rand()%256;
        client->valore = 0;
        client->socketFd = accept(socketServer, (struct sockaddr*)&(client->socketClient), &(client->socketClientLen));
        if(client->socketFd < 0){
            perror("accept");
            continue;
        }

        threadData* th = malloc(sizeof(threadData));
        th->client = client;
        th->clientList = clientList;

        pthread_t newClient;
        pthread_create(&newClient, NULL, clientHandler, (void*)th);
        pthread_detach(newClient);

    }


}