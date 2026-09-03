#include <stdio.h>
#include <string.h>
#include <sys/types.h> //qui prendiamo tutti i tipi di socket
#include <sys/socket.h> //questo serve per usare le socket
#include <netinet/in.h> //questo serve per htons htonl ecc...
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int s, numBytes;
    struct sockaddr_in sa;  //useremo questa struct perché vogliamo usare il protocollo ipv4
    // BUFSIZ è una costante definita in stdio.h (solitamente 1024 o 4096)
    char buffer[BUFSIZ + 1]; 

    // 1. Creazione del socket (TCP)
    if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Errore nell'apertura del socket");
        return 1;
    }

    // 2. Pulizia della struttura sockaddr_in e configurazione
    memset(&sa, '\0', sizeof(sa)); // È come se avessi inizializzato a 0 la variabile sa
    
    sa.sin_family = AF_INET;   // AF_INET sta per i protocolli TCP e UDP, inet di base sta per IPv4 se volessi IPv6 dovrei mettere inet6
    sa.sin_port = htons(13); // Porta 13: Daytime Protocol, deve essere formattata secondo il network byte order quindi uso htons dato che è un numero a 16 bit
    sa.sin_addr.s_addr = inet_addr("193.204.114.105"); //questo è un ip pubblico di un server italiano per l'ora esatta, lo passo come stringa

    // 3. Connessione al server
    if (connect(s, (struct sockaddr *)&sa, sizeof(sa)) < 0) { //Casting necessario da struct IPv4 a struct generica
        perror("Errore durante la connessione");
        close(s);
        return 2;
    }

    // 4. Lettura dei dati dal socket
    // Leggiamo a blocchi finché il server non chiude la connessione (read torna 0)
    while ((numBytes = read(s, buffer, BUFSIZ)) > 0) {  //read(da dove prendi i dati, dove li metti, quanto è grande il buffer)
        // Scriviamo direttamente sullo standard output (file descriptor 1) //molto simile ad usare un printf
        write(1, buffer, numBytes); //write(dove scrive, da dove prende, quanti byte deve prendere)
        //printf("ciao: %s , numBytes %d",buffer,numBytes);
    }

    // 5. Chiusura del socket
    close(s);
    
    return 0;
}