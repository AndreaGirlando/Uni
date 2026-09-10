// Si collega al nodo centrale e inizia a spammare messaggi ogni 3 secondi di tipo temperatura, umidità e qualità dell'aria
// se temperatura > 30 o qualità aria scarsa allora si ferma ed entra in allarme
// aspetta che gli arrivi il comando di stoppare l'allarme

#include "cond.c"

int main(){
    srand(time(NULL));

    int socketFd = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socketClient;
    socketClient.sin_addr.s_addr = inet_addr(CENTRAL_ADDRS);
    socketClient.sin_port = htons(CENTRAL_PORT);
    socketClient.sin_family = PF_INET;
    socklen_t socketClientLen = sizeof(socketClient);
    if(connect(socketFd, (struct sockaddr*)&socketClient, socketClientLen)<0){
        perror("connect");
    }

    while(1){
        msgSensore msgReq = {0, 0, 0, 0};
        msgSensore msgRes = {0, 0, 0, 0};

        int aria = rand()%100;
        int temperatura = rand()%40;
        int umidita = rand()%100;

        msgReq.aria = htonl(aria);
        msgReq.temperatura = htonl(temperatura);
        msgReq.umidita = htonl(umidita);

        if(send(socketFd, (void*)&msgReq, sizeof(msgReq), 0)<0){
            perror("Send");
        }

        printf("Ho appena inviato al server: \t aria: %d, temperatura: %d, umidità: %d\n", aria, temperatura, umidita);

        if(temperatura >= 30 || aria <= 30){
            while(1){
                int byteRicevuti = recv(socketFd, (void*)&msgRes, sizeof(msgRes), 0);
                if(byteRicevuti <= 0){
                    if(byteRicevuti == 0){
                        printf("Il server ha chiuso la connessione");
                    }else{
                        perror("recv");
                    }
                    exit(EXIT_FAILURE);
                }
                msgRes.aria = ntohl(msgRes.aria);
                msgRes.temperatura = ntohl(msgRes.temperatura);
                msgRes.isAllarmeRientrato = ntohl(msgRes.isAllarmeRientrato);
                msgRes.umidita = ntohl(msgRes.umidita);
                if(msgRes.isAllarmeRientrato){
                    printf("Allarme rientrato\n");
                    break;
                }
            }
        }

        sleep(1);
    }
}