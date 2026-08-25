#include <stdlib.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>



int main(int argc, char *argv[]){

    if(argc != 3){
        fprintf(stderr,"Errore: devi avviarmi con <PORT-server> <IP-server>.\n");
        exit(EXIT_FAILURE);
    }

    printf("Tentativo di connessione al server per iniziare la partita...\n");

    int socketClient;
    struct sockaddr_in indirizzoPortaServer;
    char lettera[1];
    char arrayTentativiRisposta[25] = {0};

    memset(&indirizzoPortaServer,0,sizeof(indirizzoPortaServer));
    indirizzoPortaServer.sin_family = AF_INET;
    indirizzoPortaServer.sin_port = htons(atoi(argv[1]));
    indirizzoPortaServer.sin_addr.s_addr = inet_addr(argv[2]);

    if((socketClient = socket(AF_INET,SOCK_STREAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket.\n");
        exit(EXIT_FAILURE); 
    }

    if((connect(socketClient,(struct sockaddr*)&indirizzoPortaServer,sizeof(indirizzoPortaServer))) < 0){
        fprintf(stderr,"Errore nella connessione con il server.\n");
        exit(EXIT_FAILURE); 
    }else{
        printf("Connessione al server riuscita, inizia il gioco:\n");
    }

    for(;;){
        printf("Inserirsci una lettera che credi sia nella parola -> ");
        scanf(" %c",&lettera[0]);
        printf("\n");
        send(socketClient,lettera,sizeof(lettera),0);

        int bytesRicevuti = recv(socketClient,arrayTentativiRisposta,sizeof(arrayTentativiRisposta),0);
        printf("     %d     ", bytesRicevuti);

        if(bytesRicevuti == 0){
            fprintf(stderr,"Il server non comunica, forse si è disconnesso\n");
            exit(EXIT_FAILURE);
        }

        if(strcmp("WIN",arrayTentativiRisposta) == 0){
            printf("\n🎉 COMPLIMENTI! Hai indovinato la parola e VINTO la partita! 🎉\n");
            break;
        }
        if(strcmp("LOSE",arrayTentativiRisposta) == 0){
            printf("\n😢 PECCATO! Hai esaurito i tentativi e PERSO la partita! 😢\n");
            break;
        }        

        for(int i = 0; i < 25; i++){
            if(arrayTentativiRisposta[i] != 0){
                printf("%c",arrayTentativiRisposta[i]);
            }else{
                printf(" - ");
            }
        }

        printf("\n");
    }
    close(socketClient);
    
}