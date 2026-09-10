
#include "prot.c"

int main(int agrc, char* argv[]){
    srand(time(NULL));
    int socketFd = socket(PF_INET, SOCK_STREAM, 0);
    struct sockaddr_in socketClient;
    socketClient.sin_addr.s_addr = inet_addr(SERVER_ADDRS);
    socketClient.sin_family = PF_INET;
    socketClient.sin_port = htons(SERVER_PORT);
    socklen_t socketClientLen = sizeof(socketClient);

    if(connect(socketFd, (struct sockaddr*)&socketClient, socketClientLen)<0){
        perror("connect");
    }
    int counter = 0;
    while(1){
        counter++;
        int n = htonl(rand()%256);
        if(send(socketFd, (void*)&n, sizeof(n), 0)<0){
            perror("send");
        }
        int byteRicevuti = recv(socketFd, (void*)&n, sizeof(n), 0);
        if(byteRicevuti <= 0){
            if(byteRicevuti == 0){
                printf("Il client ha chiuso la connessione");
                break;
            }
            else{
                perror("recv");
            }
        }
        n = ntohl(n);
        printf("Il server ha risposto con %d\n", n);
        if(counter > atoi(argv[1])){
            break;
        }
        sleep(2);
    }

    close(socketFd);
    return 0;
}