#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_MAX 160
#define MAX_CLIENTS 64


//! Andrebbe gestita la chiusura del server, chiudendo la socket specifica (MEME)

typedef struct {
    int socketClient;
    struct sockaddr_in indirizzoPorta;
    // altre info sul client se necessarie
} client_info_t;

typedef struct {
    client_info_t *list[MAX_CLIENTS];
    int count;
    pthread_mutex_t mutex;
} client_list_t;

client_list_t clients = { .count = 0 }; //Struttura globale per gestire la lista dei client

void broadcast_message(const char* messaggio, int socketCheHaInviato){
    pthread_mutex_lock(&clients.mutex);

    for(int i = 0; i < clients.count; i++){
        if(clients.list[i]->socketClient == socketCheHaInviato) continue;
        send(clients.list[i]->socketClient, messaggio, strlen(messaggio),0);
    }

    pthread_mutex_unlock(&clients.mutex);
}

void * gestione_client(void *arg){
    client_info_t *client = (client_info_t*)arg;

    int socketClient = client->socketClient;
    char buffer[BUFFER_MAX];
    char ipAddress[INET_ADDRSTRLEN];
    int port = ntohs(client->indirizzoPorta.sin_port);

    inet_ntop(AF_INET, &client->indirizzoPorta.sin_addr, ipAddress, INET_ADDRSTRLEN);

    printf("Si è collegato il client %s: %d\n", ipAddress, port);

    pthread_mutex_lock(&clients.mutex);
    clients.list[clients.count] = client;
    clients.count++;
    pthread_mutex_unlock(&clients.mutex);

    for(;;){
        int numBytes = recv(socketClient, buffer, BUFFER_MAX, 0);
        if(numBytes < 0){
            printf("Errore in ricezione\n");
        }
        if(numBytes == 0){
            printf("il client %s:%d si è disconnesso \n", ipAddress, port);
            break;
        }

        printf("Il client %s:%d ha inviato %s a tutti\n", ipAddress, port, buffer);
        broadcast_message(buffer, socketClient);

        memset(buffer, '\0', BUFFER_MAX);
    }

    close(socketClient);

    pthread_mutex_lock(&clients.mutex);
    for(int i = 0; i < clients.count; i++){
        if(clients.list[i]->socketClient == socketClient){
            // ho trovato il client che si sta disconnettendo
            free(clients.list[i]);
            for(int j = i; i < clients.count-1; j++){
                clients.list[j] = clients.list[j+1];
            }
            clients.count--;
            break;
        }
    }
    pthread_mutex_unlock(&clients.mutex);

    return NULL;
    //Dobbiamo aggiornare la lista dei clients
    //avviare il ciclo infinito di gestione del singolo cliente
    //gestire ricezione e broadcasting
    //gestire chiusura
    //fine
}

// server <PORT>
int main(int argc, char * argv[]){
    if(argc < 2){
        printf("Devi avviarmi con <PORT>\n");
        exit(EXIT_FAILURE);
    }

    int socketServer;
    struct sockaddr_in ipPortaServer;
    pthread_mutex_init(&clients.mutex, NULL);

    ipPortaServer.sin_family = AF_INET;
    ipPortaServer.sin_port = htons(atoi(argv[1]));
    ipPortaServer.sin_addr.s_addr = INADDR_ANY;

    socketServer = socket(AF_INET, SOCK_STREAM, 0);

    if(bind(socketServer, (struct sockaddr*) &ipPortaServer, sizeof(ipPortaServer))<0){
        printf("Errore di bind, porta già utilizzata");
        exit(EXIT_FAILURE);
    }

    listen(socketServer, MAX_CLIENTS);

    printf("Server in ascolto sulla porta %s\n", argv[1]);

    //ora posso accettare connessioni
    //per ogni messaggio che ricevo devo inviare lo stesso a tutti quelli collegati7

    for(;;){
        client_info_t *client = malloc(sizeof(client_info_t));
        socklen_t addrlen = sizeof(client->indirizzoPorta);

        client->socketClient = accept(socketServer, (struct sockaddr*)&client->indirizzoPorta, &addrlen);

        pthread_t clientThread;
        pthread_create(&clientThread, NULL, gestione_client, (void*)(client));

    }
    close(socketServer);
    exit(EXIT_SUCCESS);
}