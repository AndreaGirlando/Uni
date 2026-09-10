// registra un nuovo sensore usando un thread differente
// se riceve temperatura > 30 o qualità aria scarsa allora invia al controlNode un allarme
// attende una risposta che inoltrerà al sensore per farlo sbloccare

#include "cond.c"

int create_server(uint16_t port){
    int socketServerFD;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    if ((socketServerFD = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return -1;
    }
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    // Bind and listen
    if (bind(socketServerFD, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind failed");
        return -2;
    }
    if (listen(socketServerFD, MAX_CLIENTS) < 0) {
        perror("listen failed");
        return -3;
    }
    return socketServerFD;
}

void* clientHandler(void* args){
    threadData* thread = (threadData*)args;
    printf("[THREAD] Connessione al sensore %d accettata\n", thread->client->id);

    while(1){
        msgSensore msgReq = {0,0,0,0};
        int byteRicevuti = recv(thread->client->socketFd, (void*)&msgReq, sizeof(msgReq), 0);
        if(byteRicevuti<=0){
            if(byteRicevuti == 0){
                printf("Il client ha chiuso la connessione");
                return NULL;
            }else{
                perror("recv");
            }
        }
        msgReq.aria = ntohl(msgReq.aria);
        msgReq.temperatura = ntohl(msgReq.temperatura);
        msgReq.umidita = ntohl(msgReq.umidita);

        printf("[THREAD] aria: %d, temperatura %d, umidita: %d\n", msgReq.aria, msgReq.temperatura, msgReq.umidita);
        if(msgReq.aria <= 30 || msgReq.temperatura >= 30){
            printf("[THREAD] Il sensore %d è in allarme\n", thread->client->socketFd);

            msgCentrale msgCentraleReq = {htonl(thread->client->id), htonl(1)};
            msgCentrale msgCentraleRes = {0,0};

            if(send(thread->socketServerControllo, (void*)&msgCentraleReq, sizeof(msgCentraleReq),0)<0){
                perror("Send al server di controllo");
            }

            byteRicevuti = recv(thread->socketServerControllo, (void*)&msgCentraleRes, sizeof(msgCentraleRes), 0);
            if(byteRicevuti<=0){
                if(byteRicevuti == 0){
                    printf("Il server di controllo ha chiuso la connessione ha chiuso la connessione");
                    return NULL;
                }else{
                    perror("recv");
                }
            }

            msgCentraleRes.idSensore = ntohl(msgCentraleRes.idSensore);
            msgCentraleRes.inAllarme = ntohl(msgCentraleRes.inAllarme);

            if(msgCentraleRes.inAllarme == 0){
                msgSensore msgRes = {0,0,0,0};
                msgRes.isAllarmeRientrato = 1;
                send(thread->client->socketFd, (void*)&msgRes, sizeof(msgRes),0);
                printf("Conferma dal server centrale arrivata e invio pacchetto di reset al sensore\n");
            }
        }
    }

    return NULL;
}


int main(){

    int serverFd = create_server(CENTRAL_PORT);
    if(serverFd < 0){
        perror("Creazione server");
        exit(EXIT_FAILURE);
    }

    printf("Server avviato e in ascolto sulla porta %d\n", CENTRAL_PORT);

    // Socket client per connettersi al server centrale
    int socketControlloFd = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socketControllo;
    socketControllo.sin_addr.s_addr = inet_addr(CONTROL_ADDRS);
    socketControllo.sin_port = htons(CONTROL_PORT);
    socketControllo.sin_family = PF_INET;
    socklen_t socketClientLen = sizeof(socketControllo);
    if(connect(socketControlloFd, (struct sockaddr*)&socketControllo, socketClientLen)<0){
        perror("connect");
    }
    printf("Connessione avvenuta con il server di controllo avvenuta con successo");


    while(1){
        threadData* thData = malloc(sizeof(threadData));
        clientInfo* client = malloc(sizeof(clientInfo));
        client->id = rand()%256;
        client->socketLen = sizeof(client->socket);
        thData->client = client;
        thData->socketServerControllo = socketControlloFd;
        if((client->socketFd = accept(serverFd, (struct sockaddr*)&(client->socket), &(client->socketLen)))<0){
            perror("Connect");
        }

        pthread_t th;
        pthread_create(&(th), NULL, clientHandler, (void*)thData);
        pthread_detach(th);
    }


}