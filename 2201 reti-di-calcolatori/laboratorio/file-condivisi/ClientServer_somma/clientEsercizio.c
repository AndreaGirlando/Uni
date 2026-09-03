//Il server ascolta alla porta 6769 e indirizzo di loopback 127.0.0.1

#include <stdio.h>
#include <string.h>
#include <sys/types.h> //qui prendiamo tutti i tipi di socket
#include <sys/socket.h> //questo serve per usare le socket
#include <netinet/in.h> //questo serve per htons htonl ecc...
#include <arpa/inet.h>
#include <unistd.h>

int main(){
    int bytes;
    int s;
    struct sockaddr_in sa;  //perche uso ipv4
    int array[2] = {4,6};
    int somma = 0;

    if((s = socket(PF_INET,SOCK_STREAM,0)) < 0){      //creazione della socket
        perror("Errore nell'apertura del socket");
        return 1;
    }

    memset(&sa,0,sizeof(sa));

    sa.sin_family = AF_INET;
    sa.sin_port = htons(6769);
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(s,(struct sockaddr *)&sa,sizeof(sa)) < 0){
        perror("Errore nella connessione al server");
        close(s);
        return 1;
    }

    write(s,array,sizeof(array));    //fino a qui invio i dati al server
    printf("Dati inviati con successo. \n");
    printf("Attendo la somma\n");

    while((bytes = read(s,&somma,sizeof(somma))) > 0){
        //printf("CIAO");
        //write(1,&somma,bytes);    //la write non funziona corretamente perché il terminale crede che il 10 inviato siano caratteri ASCII quindi va a capo
        printf("La somma e': %d, numBytes %d",somma,bytes); //la print invece fa la conversione e scrive correttamente il 10
    }

}