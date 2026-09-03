#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#define BUFFER_MAX 160
#define MAX_CLIENTS 64

typedef struct{     //La struct raggruppa logicamente tutto ciò che definisce un client connesso al server.
                    //Al momento contiene solo il socket e l'indirizzo
    int socketClient;
    struct sockaddr_in indirizzoPorta;
    //possiamo mettere altre informazioni sul client
} client_info_t;        //ognuno di questo mi rappresenta un client

typedef struct{     //Il suo scopo è raggruppare in un unico posto tutti i client attualmente connessi
                    //e fornire gli strumenti per gestirli in totale sicurezza.
    int count;
    client_info_t* list[MAX_CLIENTS];   //array di puntatori che può contenere fino a MAX_CLIENTS
    pthread_mutex_t mutex;
}clients_list_t;

clients_list_t clients = {.count = 0};

void broadcast_message(const char* messaggio, int socketCheHaInviato){
    pthread_mutex_lock(&clients.mutex);

    for(int i = 0; i < clients.count; i++){     //scorro tutti i client

        if(clients.list[i]->socketClient == socketCheHaInviato){
            continue;   //se l'if è vero passa al prossimo ciclo perché non deve mandare al client che ha scritto
        }
        send(clients.list[i]->socketClient,messaggio,strlen(messaggio),0);

    }
    pthread_mutex_unlock(&clients.mutex);    
}

void * gestione_client(void *arg){      //funzione eseguita dal thread (la libreria pthread.h impone una regola rigida: qualsiasi funzione tu voglia dare in pasto a un thread deve avere tassativamente questa identica struttura)
    client_info_t *client = (client_info_t*)arg;    //faccio il un-casting del parametro passato prima nel main (da void a client_info_t)
    int socketClient = client->socketClient;
    char buffer[BUFFER_MAX];
    char ipAddress[INET_ADDRSTRLEN];
    int port = ntohs(client->indirizzoPorta.sin_port);          //con queste righe prendiamo i valori di indirizzo ip e porta del client collegato per stamparli
    inet_ntop(AF_INET, &client->indirizzoPorta.sin_addr,ipAddress,INET_ADDRSTRLEN);

    printf("Si e' collegato il client: %s:%d\n",ipAddress,port);
    
    pthread_mutex_lock(&clients.mutex);         //servono i mutex per gestire l'accesso concorrente da parte di più thread a queste locazioni
    clients.list[clients.count] = client;   //dentro la lista metto un client collegato e aggiorno la variabile count
    clients.count++;
    pthread_mutex_unlock(&clients.mutex);

    for(;;){

        int numBytes = recv(socketClient, buffer,BUFFER_MAX,0); //in numBytes mette il numero di byte letti
        if(numBytes < 0){
            printf("Errore in ricezione");
            continue;
        }
        if(numBytes == 0){
            printf("Il client %s:%d si e' disconnesso\n",ipAddress,port);
            break;
        }
        printf("Il client %s:%d ha inviato: '%s' a tutti i client\n", ipAddress,port,buffer);
        broadcast_message(buffer,socketClient);

        memset(buffer, 0, BUFFER_MAX);
    }
    close(socketClient);

    pthread_mutex_lock(&clients.mutex);
    for(int i = 0; i < clients.count; i++){
        if(clients.list[i]->socketClient == socketClient){
        //ho trovato il client che si sta disconnettendo
        free(clients.list[i]);
        for(int j = i; j < clients.count-1; j++){   //qui chiudo lo spazio vuoto lasciato dal client disconnesso
            clients.list[j] = clients.list[j+1];
        }
        clients.count--;
        break;
    }
    }
    pthread_mutex_unlock(&clients.mutex);

    return NULL;
}

//server <PORT>
int main(int argc, char* argv[]) { 
    if(argc <2){ //remember, argv[0] is the same program! 
        printf ("Devi avviarmi usando <Port> \n");
        exit(1); 
    }

    int socketServer;
    struct sockaddr_in ipPortaServer;
    pthread_mutex_init(&clients.mutex, NULL);   //La funzione pthread_mutex_init serve a inizializzare un Mutex
    socketServer = socket(AF_INET, SOCK_STREAM,0);

    ipPortaServer.sin_family = AF_INET;
    ipPortaServer.sin_port = htons(atoi(argv[1]));
    ipPortaServer.sin_addr.s_addr = INADDR_ANY;

    socketServer = socket(AF_INET, SOCK_STREAM, 0);
    if(bind(socketServer, (struct sockaddr*)&ipPortaServer, sizeof(ipPortaServer)) < 0){
        printf("Errore di bind porta gia utilizzata:\n");
        exit(1);
    }

    listen(socketServer, MAX_CLIENTS);

    printf("Server in ascolto sulla porta: %s\n",argv[1]);

    //////////////////////////////////////////////
    //zona di accept e creazione dei thread
    for(;;){
        client_info_t *client = malloc(sizeof(client_info_t));  //alloco spazio per la struct client_info_t, "client" punta a questa struct
        socklen_t addrlen = sizeof(client->indirizzoPorta);

        client->socketClient = accept(socketServer,(struct sockaddr*)&client->indirizzoPorta,&addrlen);  //il server si ferma qui finché qualche client non l'ho contatta

        pthread_t clientThread;
        pthread_create(&clientThread, NULL, gestione_client, (void*)client);    //se mi si collegano n client nell'accept mi si creano n thread che vanno a eseguire la funzione gestione_client
                                                            //qui passo client che però va prima castato a void*, questo per qualsiasi tipo di variabile
    }
    close(socketServer);

}