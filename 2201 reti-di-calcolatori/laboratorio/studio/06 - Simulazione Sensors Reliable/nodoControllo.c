//Riceve gli allarmi dal nodo centrale
//aspetta 5 secondi e permette lo sblocco
//salva gli allarmi dentro un file "LOG"

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

int main(){
    char* path = "LOG";
    int serverFd = create_server(CONTROL_PORT);

    printf("Server avviato e in ascolto sulla porta %d\n", CONTROL_PORT);

    int centraleFd;
    struct sockaddr_in centraleSocket;
    socklen_t centraleSocketLen = sizeof(centraleSocket);
    if((centraleFd = accept(serverFd, (struct sockaddr*)&centraleSocket, &centraleSocketLen))<0){
        perror("accept");
    }

    printf("Collegato al server centrale\n");

    FILE* file = fopen(path, "w");

    while(1){
        msgCentrale msgRes = {0,0};
        msgCentrale msgReq = {0,0};

        int byteRicevuti = recv(centraleFd, (void*)&msgRes, sizeof(msgRes), 0);
        if(byteRicevuti<=0){
            if(byteRicevuti == 0){
                printf("Il server centrale ha chiuso la connessione");
                exit(EXIT_FAILURE);
            }else{
                perror("recv");
            }
        }
        msgRes.idSensore = ntohl(msgRes.idSensore);
        msgRes.inAllarme = ntohl(msgRes.inAllarme);

        if(msgRes.inAllarme){
            printf("Il sensore %d è in allarme\n", msgRes.idSensore);
            fprintf(file, "Il sensore %d è in allarme\n", msgRes.idSensore);
            fflush(file);
            sleep(1);
            msgReq.idSensore = htonl(msgRes.idSensore);
            msgReq.inAllarme = htonl(0);
            if(send(centraleFd, (void*)&msgReq, sizeof(msgReq), 0)<0){
                perror("Send");
                continue;
            }
            printf("Pacchetto di reset inviato\n");

        }
    }



    close(centraleFd);
    return 0;
}