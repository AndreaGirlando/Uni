#include "protocollo.c"

int main(){

    int socketFD = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socketClient;
    socketClient.sin_addr.s_addr = inet_addr(SERVER_ADDRS);
    socketClient.sin_family = PF_INET;
    socketClient.sin_port = htons(SERVER_PORT);
    socklen_t socketClientLen = sizeof(socketClient);

    if(connect(socketFD, (struct sockaddr*)&socketClient, socketClientLen)<0){
        perror("Connect");
        exit(EXIT_FAILURE);
    }

    message* resMSG = malloc(sizeof(message));

    // Operazione REG
    message* reqMSG = malloc(sizeof(message));
    reqMSG->messageType = htonl(REG);
    reqMSG->request = htonl(rand()%100);
    if(send(socketFD, (void*)reqMSG, sizeof(*reqMSG), 0)<0){
        perror("Send");
        exit(EXIT_FAILURE);
    }

    int byteRicevuti = recv(socketFD, (void*)resMSG, sizeof(*resMSG), 0);
    if(byteRicevuti<=0){
        if(byteRicevuti == 0) {
            printf("Il server ha chiuso la connessione");
            exit(EXIT_SUCCESS);
        }else{
            perror("recv");
            exit(EXIT_FAILURE);
        }
    }
    printf("%s", resMSG->response);

    // Operazione SET
    reqMSG->messageType = htonl(SET);
    reqMSG->request = htonl(rand()%100);

    if(send(socketFD, (void*)reqMSG, sizeof(*reqMSG), 0)<0){
        perror("Send");
    }

    byteRicevuti = recv(socketFD, (void*)resMSG, sizeof(*resMSG), 0);
    if(byteRicevuti<=0){
        if(byteRicevuti == 0) {
            printf("Il server ha chiuso la connessione");
            exit(EXIT_SUCCESS);
        }else{
            perror("recv");
            exit(EXIT_FAILURE);
        }
    }
    printf("%s", resMSG->response);


    // Operazione LIST
    reqMSG->messageType = htonl(LIST);

    if(send(socketFD, (void*)reqMSG, sizeof(*reqMSG), 0)<0){
        perror("Send");
        exit(EXIT_FAILURE);
    }

    byteRicevuti = recv(socketFD, (void*)resMSG, sizeof(*resMSG), 0);
    if(byteRicevuti<=0){
        if(byteRicevuti == 0) {
            printf("Il server ha chiuso la connessione");
            exit(EXIT_SUCCESS);
        }else{
            perror("recv");
            exit(EXIT_FAILURE);
        }
    }
    printf("%s", resMSG->response);

    sleep(10);

    // Operazione LIST
    reqMSG->messageType = htonl(LIST);

    if(send(socketFD, (void*)reqMSG, sizeof(*reqMSG), 0)<0){
        perror("Send");
        exit(EXIT_FAILURE);
    }

    byteRicevuti = recv(socketFD, (void*)resMSG, sizeof(*resMSG), 0);
    if(byteRicevuti<=0){
        if(byteRicevuti == 0) {
            printf("Il server ha chiuso la connessione");
            exit(EXIT_SUCCESS);
        }else{
            perror("recv");
            exit(EXIT_FAILURE);
        }
    }
    printf("%s", resMSG->response);


    // Operazione QUIT
    reqMSG->messageType = htonl(QUIT);

    if(send(socketFD, (void*)reqMSG, sizeof(*reqMSG), 0)<0){
        perror("Send");
    }

    byteRicevuti = recv(socketFD, (void*)resMSG, sizeof(*resMSG), 0);
    if(byteRicevuti<=0){
        if(byteRicevuti == 0) {
            printf("Il server ha chiuso la connessione");
            exit(EXIT_SUCCESS);
        }else{
            perror("recv");
            exit(EXIT_FAILURE);
        }
    }
    printf("%s", resMSG->response);


    close(socketFD);


    return 0;
}