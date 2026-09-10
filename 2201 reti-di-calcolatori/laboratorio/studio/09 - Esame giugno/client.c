// il client si collega al server e questo gli manda la lista dei client

#include "cond.c"

typedef struct threadData{
    int id;
    int numeroClient;
    int serverFd;
}threadData;

void* gestioneAnello(void* args){
    flockfile(stdout);
    // printf("[DEBUG] il thread per la gestione dell'anello è stato avviato\n");
    funlockfile(stdout);
    threadData* th = (threadData*)args;
    int porta = th->id + BASELINE_PORT;

    while (1)
    {
        struct sockaddr_in socketClient;
        socklen_t socketClientLen = sizeof(socketClient);

        message msgReceived;
        message msgToSend;

        int byteRicevuti = recvfrom(th->serverFd, (void*)&msgReceived, sizeof(msgReceived), 0, NULL, NULL);

        if(byteRicevuti <= 0){
            if(byteRicevuti==0){
                printf("Pacchetto vuoto");
                continue;
            }
            perror("recvfrom");
            continue;
        }

        int idNextClient = (th->id+1)%th->numeroClient;
        msgReceived.dst = ntohl(msgReceived.dst);
        msgReceived.src = ntohl(msgReceived.src);
        msgReceived.type = ntohl(msgReceived.type);
        msgReceived.value = ntohl(msgReceived.value);


        msgToSend.dst = htonl(msgReceived.dst);
        msgToSend.src = htonl(msgReceived.src);
        msgToSend.value = htonl(msgReceived.value);
        msgToSend.type = htonl(msgReceived.type);

        struct sockaddr_in socketNextClient;
        socketNextClient.sin_addr.s_addr = inet_addr("127.0.0.1");
        socketNextClient.sin_port = htons(idNextClient+BASELINE_PORT);
        socketNextClient.sin_family = PF_INET;
        socklen_t lenSocketServer = sizeof(socketNextClient);

        // se la sorgente è uguale alla destinazione significa che il pacchetto ha fatto il giro dell'anello -> si deve fermare
        if(msgReceived.src == th->id) continue;

        if(msgReceived.type == 1){
            //il messaggio è arrivato in unicast se come destinazione contiene questo client lo stampo
            if(msgReceived.dst == th->id){
                flockfile(stdout);
                printf("Il client %d ha inviato %d in unicast\n", msgReceived.src, msgReceived.value);
                funlockfile(stdout);
                continue; // il pacchetto è arrivato a destinazione, non deve essere inoltrato al client successivo
            }
        }else if(msgReceived.type == 0){
            //il messaggio è arrivato in broadcast lo stampo e lo invio al client successivo
            flockfile(stdout);
            printf("Il client %d ha inviato %d in broadcast\n", msgReceived.src, msgReceived.value);
            funlockfile(stdout);
        }

        if(sendto(th->serverFd, (void*)&msgToSend, sizeof(msgToSend), 0, (struct sockaddr*)&socketNextClient, lenSocketServer)<0){
            perror("sendto");
        }
    }

}

int main(int argc, char* argv[]){

    threadData* thData = malloc(sizeof(threadData));
    thData->id = atoi(argv[1]);
    thData->numeroClient = atoi(argv[2]);
    thData->serverFd = create_server(BASELINE_PORT+thData->id);
    pthread_t th;
    pthread_create(&(th), NULL, gestioneAnello, (void*)thData);

    int isPassivo = atoi(argv[3]);

    printf("Sono il client: %d (%s)\n", thData->id, isPassivo? "client passivo":"client attivo");

    if(isPassivo){
        while(1){
            int type = 0;
            int valore = 0;
            int destinazione = 0;
            printf("Scelta: 0 - broadcast, 1 - unicast\n");
            scanf("%d", &type);

            printf("Valore: valore numerico\n");
            scanf("%d", &valore);

            printf("Destinazione: valore da 0 a %d (in caso di broadcast qualsiasi valore va bene)\n", thData->numeroClient-1);
            scanf("%d", &destinazione);

            int idNextClient = (thData->id+1)%thData->numeroClient;
            struct sockaddr_in socketNextClient;
            socketNextClient.sin_addr.s_addr = inet_addr("127.0.0.1");
            socketNextClient.sin_port = htons(idNextClient+BASELINE_PORT);
            socketNextClient.sin_family = PF_INET;
            socklen_t lenSocketServer = sizeof(socketNextClient);

            message msgToSend;
            msgToSend.dst = htonl(destinazione);
            msgToSend.src = htonl(thData->id);
            msgToSend.value = htonl(valore);
            msgToSend.type = htonl(type);

            if(sendto(thData->serverFd, (void*)&msgToSend, sizeof(msgToSend), 0, (struct sockaddr*)&socketNextClient, lenSocketServer)<0){
                perror("sendto");
            }

            struct sockaddr_in socketServerLog;
            socketServerLog.sin_addr.s_addr = inet_addr("127.0.0.1");
            socketServerLog.sin_port = htons(SERVER_PORT);
            socketServerLog.sin_family = PF_INET;
            socklen_t lenSocketServerLog = sizeof(socketServerLog);

            if(sendto(thData->serverFd, (void*)&msgToSend, sizeof(msgToSend), 0, (struct sockaddr*)&socketServerLog, lenSocketServerLog)<0){
                perror("sendto");
            }
        }
    }


    pthread_join(th, NULL);
    return NULL;
}