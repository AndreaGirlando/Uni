#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
//#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <time.h>

#define Max_question_buffer 512
#define Max_buffer 128
#define Max_client 1

int main(int argc, char* argv[]){
    srand(time(NULL));
    int bytesRicevuti = 0;
    char bufferRisposta[Max_buffer];
    char bufferDomanda[Max_question_buffer];
    int socketServer;
    struct sockaddr_in indirizzoServer;
    socklen_t addr_len = sizeof(indirizzoServer);
    char *listaRisposte[10] = {"Assolutamente si", "Si","Assolutamente no", "No", "Forse", "Magari ti va bene", "Cosa può andare storto", "Non lo so", "Lo sappiamo entrambi...", "I segnali indicano un disastro"};

    if(argc < 3){
        printf("Errore: parametri insufficenti passare da riga di comando indirizzo IP e porta del server\n");
        exit(EXIT_FAILURE);
    }

    memset(&indirizzoServer,0,sizeof(indirizzoServer));
    indirizzoServer.sin_family = AF_INET;
    indirizzoServer.sin_port = htons(atoi(argv[2]));
    indirizzoServer.sin_addr.s_addr = INADDR_ANY;

    if((socketServer = socket(AF_INET,SOCK_STREAM,0)) < 0){
        printf("Errore nella creazione della socket\n");
        exit(EXIT_FAILURE);
    }

    if((bind(socketServer,(struct sockaddr*)&indirizzoServer,sizeof(indirizzoServer))) < 0){
        perror("Errore nella bind della socket\n");
        exit(EXIT_FAILURE); 
    }

    listen(socketServer,Max_client);

    printf("Server in ascolto sulla porta %s\n",argv[2]);

    int socketClient = accept(socketServer,(struct sockaddr*)&indirizzoServer,&addr_len);
    for(;;){
        memset(&bufferRisposta,0,sizeof(bufferRisposta));

        if(bytesRicevuti = recv(socketClient,bufferDomanda,sizeof(bufferDomanda),0) <= 0){
            break;
        }
        //fase di elaborazione della risposta
        sleep(1);
        int numeroRandom = rand() % 10;
        strcpy(bufferRisposta,listaRisposte[numeroRandom]);
        send(socketClient,bufferRisposta,sizeof(bufferRisposta),0);

    }
    close(socketClient);
    close(socketServer);

}