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

typedef struct{

    char bufferMail[64];
    char bufferPass[24];
    bool registrazione;

} Accesso;

int connectServer(int port, char *ip_server){
    printf("Connessione al server.\n");

    int socketServer;
    struct sockaddr_in indirizzoPortaServer;

    memset(&indirizzoPortaServer,0,sizeof(indirizzoPortaServer));
    indirizzoPortaServer.sin_family = AF_INET;
    indirizzoPortaServer.sin_port = htons(port);
    indirizzoPortaServer.sin_addr.s_addr = inet_addr(ip_server);

    if((socketServer = socket(AF_INET,SOCK_STREAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket\n");
        exit(EXIT_FAILURE);
    }

    if((connect(socketServer,(struct sockaddr*)&indirizzoPortaServer,sizeof(indirizzoPortaServer))) < 0){
        fprintf(stderr,"Errore nella connessione al server\n");
        exit(EXIT_FAILURE);
    }

    printf("Connessione al server riuscita\n");

    return socketServer;
}

void gestioneAccesso(int socketServer){
    int accessoAccount = 0;
    char accessoAccountChar[3];
    
    bool accessoEseguitoCorrettamente = 0;
    bool accesso = 0;   //questo valore sarà ritornato dal server
    Accesso dati;
    
    do{
        printf("Premi 1 per accedere o 2 per creare un account -> ");
        //scanf("%d",&accessoAccount);
        fgets(accessoAccountChar,sizeof(accessoAccountChar),stdin);
        accessoAccount = atoi(accessoAccountChar);
        switch (accessoAccount)
        {
        case 1:
            printf("Invia le credenziali di accesso, inserisci e-mail e password -> ");
            fgets(dati.bufferMail,sizeof(dati.bufferMail),stdin);
            dati.bufferMail[strcspn(dati.bufferMail, "\n")] = '\0';
            fgets(dati.bufferPass,sizeof(dati.bufferPass),stdin);
            dati.bufferPass[strcspn(dati.bufferPass, "\n")] = '\0';
            dati.registrazione = 0;
            dati.registrazione = htons(dati.registrazione);
            //inserire send con un bit che indica il login
            send(socketServer,&dati,sizeof(Accesso),0);
            
            printf("credenziali inviate\n");
            if(recv(socketServer,&accesso,sizeof(accesso),0) > 0){
                if(accesso == 1){
                    printf("Login eseguito con successo.\n");
                    accessoEseguitoCorrettamente = 1;
                }else{
                    printf("Credenziali Errate.\n");
                    accessoEseguitoCorrettamente = 0;
                }
            }else{
                fprintf(stderr,"Il server non comunica o ha chiuso la connessione.\n");
                exit(EXIT_FAILURE);
            }
            break;
        case 2:
            printf("Invia le credenziali per la registrazione, inserisci e-mail e password -> ");
            fgets(dati.bufferMail,sizeof(dati.bufferMail),stdin);
            dati.bufferMail[strcspn(dati.bufferMail, "\n")] = '\0';
            fgets(dati.bufferPass,sizeof(dati.bufferPass),stdin);
            dati.bufferPass[strcspn(dati.bufferPass, "\n")] = '\0';
            dati.registrazione = 1;
            //inserire send con un bit che indica la registrazione
            send(socketServer,&dati,sizeof(Accesso),0);
            
            printf("credenziali inviate\n");
            printf("\n");
            if(recv(socketServer,&accesso,sizeof(accesso),0) > 0){
                if(accesso == 1){
                    printf("Registrazione eseguita con successo.\n");
                    accessoEseguitoCorrettamente = 1;
                }else{
                    printf("Problema nella registrazione.\n");
                    accessoEseguitoCorrettamente = 0;
                }
            }else{
                fprintf(stderr,"Il server non comunica o ha chiuso la connessione.\n");
                exit(EXIT_FAILURE);
            }
            break;
        
        default:
            break;
        }

    }while(accessoEseguitoCorrettamente == 0);

}

bool gestioneWaiting(){
    printf("Avvio la ricerca...\n");
    
}

void gioca(){
    printf("Inizia il gioco.\n");


}

int main(int argc, char *argv[]){

    if(argc != 3){
        fprintf(stderr,"Errore: devi avviarmi inserendo <PORT-server> <IP-server>\n");
        exit(EXIT_FAILURE);
    }

    int socket;

    int operazione = 0;
    char operazioneChar[3];
    bool autenticato = 0;
    printf("Benvenuto in carta forbice sasso.\nPremi 1 per connetterti al server-> ");

    do{
        if(autenticato == 1){
            printf("Sei nella LOBBY, vuoi metterti in attesa per giocare? In tal caso premi 2\n");
        }
        fgets(operazioneChar,sizeof(operazioneChar),stdin);
        operazione = atoi(operazioneChar);
        switch (operazione)
        {
        case 1:
            socket = connectServer(atoi(argv[1]),argv[2]);
            printf("Connesso al server %s | %s\n", argv[1],argv[2]);
            gestioneAccesso(socket);
            autenticato = 1;
            break;
        case 2:
            bool partitaTrovata = 0;
            partitaTrovata = gestioneWaiting();
            if(partitaTrovata == 1){
                gioca();
            }
            break;
        default:
            break;
        }
    }while(operazione != -1);

    printf("Uscita");

}