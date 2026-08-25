#include <stdlib.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CLIENTS 1

bool gestioneRicezione(int socketClient){
    srand(time(NULL));
    //////////logica di creazione delle parole e tentativi//////////////
    char *arrayParole[10] = {"bambola","macchina","sternocleidomastoideo","naso","casa","server","client","protocollo","router","armadio"};
    char bufferParola[25] = {'\0'};
    int tentativi = 6;
    char Risposta[1];
    char arrayTentativi[25] = {'\0'};
    ////////////////////////////////////////////////////////////////////

    int random = rand() % 10;
    strcpy(bufferParola,arrayParole[random]);
    printf("La parola scelta è: %s",arrayParole[random]);
    
    printf("\n");
    do{
        int letteraIndovinata = 0;
        int bytesRicevuti = recv(socketClient,Risposta,sizeof(Risposta),0);
        printf("     %d      \n",bytesRicevuti);
        if(bytesRicevuti == 0){
            fprintf(stderr,"Il client non comunica, forse si è disconnesso\n");
            exit(EXIT_FAILURE);
        }

        for(int i = 0; i < 25; i++){
            if(bufferParola[i] != 0){
                if(Risposta[0] == bufferParola[i]){
                    letteraIndovinata = 1;
                    arrayTentativi[i] = bufferParola[i];
                }
            }
        }
        if(letteraIndovinata != 1){
            tentativi--;
            printf("\nTentativi Rimasti: %d\n", tentativi);
        }
        for(int i = 0; i < 25; i++){
            printf("%c ",arrayTentativi[i]);
        }

        send(socketClient,arrayTentativi,sizeof(arrayTentativi),0);

        if(strcmp(arrayTentativi,bufferParola) == 0){   //vittoria
        return 1;
        }

    }while(tentativi > 0);
    
    return 0;   //perdita
    
}

int main(int argc, char *argv[]){

    if(argc != 2){
        fprintf(stderr,"Errore: devi avviarmi con <PORT-server>.\n");
        exit(EXIT_FAILURE);
    }

    int socketServer;
    struct sockaddr_in indirizzoServer;

    memset(&indirizzoServer,0,sizeof(indirizzoServer));
    indirizzoServer.sin_family = AF_INET;
    indirizzoServer.sin_port = htons(atoi(argv[1]));
    indirizzoServer.sin_addr.s_addr = INADDR_ANY;

    if((socketServer = socket(AF_INET,SOCK_STREAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket.\n");
        exit(EXIT_FAILURE); 
    }

    if((bind(socketServer,(struct sockaddr*)&indirizzoServer,sizeof(indirizzoServer))) < 0){
        fprintf(stderr,"Errore nella bind della socket.\n");
        exit(EXIT_FAILURE); 
    }

    listen(socketServer,MAX_CLIENTS);

    printf("Server in ascolto sulla porta %s.\n",argv[1]);

    for(;;){

        int socketClient;
        socketClient = accept(socketServer,NULL,NULL);
        printf("Client connesso.\n");

        bool vincita = gestioneRicezione(socketClient);

        if(vincita == 1){
            printf("Il client ha vinto!\n");
            send(socketClient,"WIN",4,0);
            close(socketClient);
        }else{
            printf("Il client ha perso, lo disconnetto.\n");
            send(socketClient,"LOSE",5,0);
            close(socketClient);
        }

    }

}