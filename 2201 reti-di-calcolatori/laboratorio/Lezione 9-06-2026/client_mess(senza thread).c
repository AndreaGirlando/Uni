#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_MAX 160 //lunghezza massima di un messaggio SMS

int main(int argc, char* argv[]){

    if(argc<3){
        printf("Devi avviarmi usando <IP> <PORT>\n");
        exit(EXIT_FAILURE);
    }

    int socketFD;
    struct sockaddr_in indirizzoPortaServer;
    char bufferAux[BUFFER_MAX];

    socketFD = socket(AF_INET, SOCK_STREAM, 0);

    //puliamo la struct per sicurezza
    memset(&indirizzoPortaServer, '\0', sizeof(indirizzoPortaServer));

    //settiamo la socket con le varie info passate da argomento
    indirizzoPortaServer.sin_family = AF_INET;
    indirizzoPortaServer.sin_port = htons(atoi(argv[2]));
    indirizzoPortaServer.sin_addr.s_addr = inet_addr(argv[1]);

    if(connect(socketFD, (struct sockaddr *) &indirizzoPortaServer, sizeof(indirizzoPortaServer))<0){
        printf("Errore di connessione");
        exit(EXIT_FAILURE);
    }

    printf("Connesso al server %s:%s\n", argv[1], argv[2]);

    //! fino a qui è solo setting, sotto c'è quello che cambia per ogni esercizio

    //loop logico applicativo
    for(;;){
        fflush(stdout);
        fgets(bufferAux, BUFFER_MAX, stdin);

        bufferAux[strcspn(bufferAux, "\n")] = '\0'; //Sostituisco tutti gli \n con il fine stringa

        if(strcmp(bufferAux, "esci") == 0){
            break;
        }

        send(socketFD, bufferAux, strlen(bufferAux), 0); // invio il messaggio

        memset(bufferAux, '\0', strlen(bufferAux)); //pulisco il buffer

        int bytesRicevuti = recv(socketFD, bufferAux, BUFFER_MAX, 0); //mi metto in ascolto di una risposta (è bloccante)

        if(bytesRicevuti < 0){
            printf("Errore in ricezione");
            continue;
        } else if(bytesRicevuti == 0){
            printf("Il server ha chiuso la connessione o è caduta");
        }

        printf("Ho ricevuto: %s\n", bufferAux);

        //! Se il server non mi risponde resto bloccato alla receive, implementiamo i thread (altro file)
    }
}