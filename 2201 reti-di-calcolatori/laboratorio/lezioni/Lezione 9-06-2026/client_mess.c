#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_MAX 160

int socketFD; // lo mettiamo globale perché in comune a gli N thread

void* gestoreInvio(void* argomenti){
    char buffer[BUFFER_MAX];
    for(;;){
        fflush(stdout);
        fgets(buffer, BUFFER_MAX, stdin); //aspetta che l'utente inserisca il messaggio da inviare

        buffer[strcspn(buffer, "\n")] = '\0'; //Sostituisco tutti gli \n con il fine stringa

        if(strcmp(buffer, "esci") == 0){
            break;
        }

        send(socketFD, buffer, strlen(buffer), 0); // invio il messaggio

        memset(buffer, '\0', strlen(buffer)); //pulisco il buffer

    }

    return NULL;
}

void* gestoreRicezione(void* argomenti){
    char buffer[BUFFER_MAX];
    int bytesRicevuti = 0;
    for(;;){
        memset(buffer, '\0', strlen(buffer)); //pulisco il buffer
        bytesRicevuti = recv(socketFD, buffer, BUFFER_MAX, 0); //mi metto in ascolto di una risposta (è bloccante)

        if(bytesRicevuti < 0){
            printf("Errore in ricezione");
            continue;
        } else if(bytesRicevuti == 0){
            printf("Il server ha chiuso la connessione o è caduta");
        }

        printf("Ho ricevuto: %s\n", buffer);
    }

    fflush(stdout);
    return NULL;

}

int main(int argc, char* argv[]){

    if(argc<3){
        printf("Devi avviarmi usando <IP> <PORT>\n");
        exit(EXIT_FAILURE);
    }


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

        pthread_t threadInvio, threadRicezione;

        pthread_create(&threadInvio, NULL, gestoreInvio, NULL);
        pthread_create(&threadRicezione, NULL, gestoreRicezione, NULL);

        pthread_join(threadInvio, NULL);
        pthread_join(threadRicezione, NULL);

        close(socketFD);
        exit(0);

    }
}