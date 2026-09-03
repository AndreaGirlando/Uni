#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
//#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 


#define Max_buffer 512
#define Max_buffer_answare 128

int main(int argc, char* argv[]){

    if(argc < 3){
        printf("Errore: parametri insufficenti passare da riga di comando indirizzo IP e porta\n");
        exit(EXIT_FAILURE);
    }

    char buffer[Max_buffer];
    char bufferRisposta[Max_buffer_answare];
    int clientSocket;
    struct sockaddr_in indirizzoPortaServer;
    int numeroBytes = 0;

    if((clientSocket = socket(AF_INET,SOCK_STREAM,0)) < 0){
        printf("Errore nella creazione della socket\n");
        exit(EXIT_FAILURE);
    }

    memset(&indirizzoPortaServer,0,sizeof(indirizzoPortaServer));
    indirizzoPortaServer.sin_family = AF_INET;
    indirizzoPortaServer.sin_port = htons(atoi(argv[2]));
    indirizzoPortaServer.sin_addr.s_addr = inet_addr(argv[1]);

    if((connect(clientSocket,(struct sockaddr*)&indirizzoPortaServer,sizeof(indirizzoPortaServer))) < 0){
        perror("Errore nella connessione al server");
        exit(EXIT_FAILURE);
    }

    printf("Connesso al server %s:%s, procedo ad inviare il messaggio...\n", argv[1],argv[2]);

    for(;;){
        numeroBytes = 0;
        fgets(buffer, Max_buffer,stdin);
        send(clientSocket,buffer,strlen(buffer),0);
        
        numeroBytes = read(clientSocket, bufferRisposta, sizeof(bufferRisposta));
        
        if(numeroBytes > 0){
            write(1, bufferRisposta, numeroBytes);
            printf("\n");
        }else if(numeroBytes == 0){
            printf("Il server ha chiuso la connessione o è caduta\n");
            break;
        }else{
            perror("Errore nella read\n");
            exit(EXIT_FAILURE);
        }
        //printf("ciaollsldls\n");

    }


}