#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main()
{
    int s, numBytes, client_fd;
    struct sockaddr_in server_addr; //struttura dove andiamo a salvare tutte i dati che ci servono per la connessione
    struct sockaddr_in client_addr; //strttura usata per i dati del client che si collega

    s = socket(PF_INET, SOCK_STREAM, 0); //creazione di un socket che userà il protocollo IPv4;

    server_addr.sin_family = AF_INET; //specifica che l'indirizzo dentro questa socket sarà di tipo IPv4
    server_addr.sin_port = htons(PORT); // specifichiamo la porta - usiamo htons per rendere la rappresentazione del PORT in BigEndian come da standard in tutto internet
    server_addr.sin_addr.s_addr = INADDR_ANY; //specificiamo l'indirizzo - usando quella funzione questo viene convertito nel giusto formato

    if (bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) { //facciamo il casting perché castiamo dalla struttura specifica per IPv4 (sockaddr_in) a quella generica
        perror("bind");
        return 1;
    }

    if (listen(s, 1) < 0) {
        perror("listen");
        return 1;
    }

    listen(s, 4);

    printf("Avvio del server...\n");

    for(;;){
        socklen_t client_len = sizeof(client_addr);
        client_fd = accept(s, (struct sockaddr*)&client_addr, &client_len);
        printf("Client accettato \n");
        pid_t pid = fork();

        char bufferSend[BUFSIZ];
        char bufferRecv[256];

        if(pid == 0){
            close(s);
            while(1){
                int numBytes = recv(client_fd, bufferRecv, 256, 0);
                bufferRecv[numBytes] = '\0';
                printf("Il client ha inviato: %s", bufferRecv);

                strcpy(bufferSend, "Ti ricopio il messaggio: ");
                strcat(bufferSend, bufferRecv);

                send(client_fd, bufferSend, strlen(bufferSend), 0);
            }
            close(client_fd);
            _exit(0);
        }
        else{
            //Chiudiamo perché gestita dal processo forkato
            close(client_fd);
        }

    }

    close(s);
    return 0;
}