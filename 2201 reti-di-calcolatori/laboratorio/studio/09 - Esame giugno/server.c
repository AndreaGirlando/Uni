// il server è un nodo centrale che riceve diverse connessioni dai vari clienti
// espone un endpoint che dato in input l'id del client ti ritorna clientInfo del nodo successivo
#include "cond.c"

int main(){
    int serverFd = create_server(SERVER_PORT);

    FILE* file = fopen("LOG", "w");


    while(1){
        struct sockaddr_in clientSocket;
        socklen_t clientSocketLen = sizeof(clientSocket);
        message receivedMessage;
        recvfrom(serverFd, (void*)&receivedMessage, sizeof(receivedMessage), 0, (struct sockaddr*)&clientSocket, &clientSocketLen);

        receivedMessage.dst = ntohl(receivedMessage.dst);
        receivedMessage.src = ntohl(receivedMessage.src);
        receivedMessage.type = ntohl(receivedMessage.type);
        receivedMessage.value = ntohl(receivedMessage.value);

        if(receivedMessage.type == 1){
            fprintf(file, "Il client %d ha inviato al client %d il valore %d\n",
                receivedMessage.src, receivedMessage.dst, receivedMessage.value);
        }
        else{
            fprintf(file, "Il client %d ha inviato in broadcast il valore %d\n",
                receivedMessage.src, receivedMessage.value);
        }
        fflush(file);
    }


}