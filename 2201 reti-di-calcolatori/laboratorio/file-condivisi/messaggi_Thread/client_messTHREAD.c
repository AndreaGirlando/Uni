#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#define BUFFER_MAX 160

int socketFD;       //è globale perche è in comune con altri thread

void* gestioreInvio(void* argomenti){       //funzione thread invio

    char buffer[BUFFER_MAX];
    //loop logico
    for(;;){
        fflush(stdout); //pulisco lo standard out
        fgets(buffer, BUFFER_MAX, stdin);       //fgets(dove scrivo,quanto è grande questo spazio dove scrivere, da dove prendo i dati), è una sorta di scanf
        buffer[strcspn(buffer, "\n")] = '\0';  //quando scriviamo una stringa e premiamo invio (\n) questo fa parte della stringa, ma a noi non serve quindi dato che buffer è un array di char diciamo che alla posizione "strcspn(buffer, "\n")" sostiuiamo \n con '\0'
        if(strcmp(buffer, "esci") == 0){        //strcspn restituisce la posizione in cui si trova il carattere tra "" in questo caso \n
            break;
            exit(-1);
        }

        send(socketFD,buffer, strlen(buffer),0);
        memset(buffer, 0, strlen(buffer)); //svuoto il buffer per prepararlo all'arrivo della risposta
    }

    return NULL;

}

void* gestioreRicezione(void* argomenti){       //funzione thread ricezione

    char buffer[BUFFER_MAX];
    int bytesRicevuti = 0;

    for(;;){
        int bytesRicevuti = recv(socketFD,buffer, BUFFER_MAX,0);   //questa operazione è bloccante come la accept lato server

        if(bytesRicevuti < 0){            
            printf("Errore in ricezione\n");
            continue;
        }else if(bytesRicevuti == 0){
            printf("Il server ha chiuso la connessione o è caduta");
            break;
        }

        printf("Ho ricevuto: %s\n", buffer);
        
    }
    fflush(stdout);
    return NULL;
}


int main(int argc, char* argv[]) { 
    if(argc <3){ //remember, argv[0] is the same program! 
        printf ("Devi avviarmi usando <IP> <Port> \n");
        exit(1); 
    } 

    //int socketFD;
    struct sockaddr_in indirizzoPortaServer;
    char bufferAux[BUFFER_MAX];

    memset(&indirizzoPortaServer, 0, sizeof(indirizzoPortaServer));
    indirizzoPortaServer.sin_family = AF_INET;
    indirizzoPortaServer.sin_port = htons(atoi(argv[2]));
    indirizzoPortaServer.sin_addr.s_addr = inet_addr(argv[1]);

    socketFD = socket(AF_INET, SOCK_STREAM,0);

    if(connect(socketFD, (struct sockaddr*)&indirizzoPortaServer,sizeof(indirizzoPortaServer)) < 0){
        printf("Errore di connessione: ");
        exit(1);
    }

    printf("Connesso al server %s:%s\n", argv[1],argv[2]);

    //fin qui ci siamo solamente connessi al server, questa parte è abbastanza standard per ogni esercizio

    //per chiarire queste funzioni sui thread guardare "Thread in C" nelle note di obsidian
    pthread_t thread_invio, thread_ricezione;
    pthread_create(&thread_invio, NULL, gestioreInvio, NULL);
    pthread_create(&thread_ricezione, NULL, gestioreRicezione, NULL);

    pthread_join(thread_invio, NULL);
    pthread_join(thread_ricezione,NULL);

    close(socketFD);

} 

