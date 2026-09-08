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
    int server_fd, numBytes;
    struct sockaddr_in server_addr; //struttura dove andiamo a salvare tutte i dati che ci servono per la connessione
    char buffer[BUFSIZ + 1]; //creiamo un buffer di dimensione standard + 1 per il fine stringa;

    server_fd = socket(PF_INET, SOCK_STREAM, 0); //creazione di un socket che userà il protocollo IPv4;

    server_addr.sin_family = AF_INET; //specifica che l'indirizzo dentro questa socket sarà di tipo IPv4
    server_addr.sin_port = htons(8080); // specifichiamo la porta - usiamo htons per rendere la rappresentazione del 13 in BigEndian come da standard in tutto internet
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //specificiamo l'indirizzo - usando quella funzione questo viene convertito nel giusto formato

    socklen_t server_len = sizeof(server_addr);

    connect(server_fd, (struct sockaddr *)&server_addr, server_len);

    printf("Scrivi quello che verrà inviato al server: ");
    while(1){
        fgets(buffer, BUFSIZ, stdin);
        send(server_fd, buffer, strlen(buffer), 0);
        int numBytes = recv(server_fd, buffer, BUFSIZ, 0);
        buffer[numBytes] = '\0';
        printf("%s", buffer);
    }

    close(server_fd);
    return 0;
}