#include <stdio.h>
#include <string.h>
#include <sys/types.h> //qui prendiamo tutti i tipi di socket
#include <sys/socket.h> //questo serve per usare le socket
#include <netinet/in.h> //questo serve per htons htonl ecc...
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#define BACKLOG 1 //max clients in queue
#define PORT 6769

//funzione che crea il server
int createServer(uint16_t port){ //unsigned int a 16bit

    int socketServerFD;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);

    if((socketServerFD = socket(PF_INET,SOCK_STREAM,0)) < 0){
        perror("Errore nell'apertura del socket");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(6769);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if((bind(socketServerFD,(struct sockaddr *)&addr,sizeof(addr))) < 0){
        perror("Errore nella bind");
        return -1;
    }

    if((listen(socketServerFD,BACKLOG)) < 0){
        perror("Errore nella listen");
        return -1;
    }

    return socketServerFD;

}    


int main(){
    int arrayDest[2] = {0};
    int server_fd, client_fd;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    int somma = 0;
    
    server_fd = createServer(PORT);
    if(server_fd < 0){
        exit(-1);
    }
    printf("Server running on port %d\n", PORT);

    while(true){

        if((client_fd = accept(server_fd,(struct sockaddr*)&addr, &addr_len)) < 0){
            perror("accept failed");
            continue;
        }
        
        read(client_fd,arrayDest,sizeof(arrayDest));
        printf("Numeri forniti dal client: ");
        for(int i = 0; i < 2; i++){     //scrivo i dati
            printf("%d ",arrayDest[i]);
            somma = somma + arrayDest[i];
        }
        printf("\nLa somma dei numeri: %d\n",somma);
        write(client_fd,&somma,sizeof(somma));

        close(client_fd);
        //break;
    }
    close(server_fd);




}