/* Simulazione rete sensoristica: il sensore è un processo che è possibile avviare e identificare tramite PID
può fare 2 cose: 1) inviare periodicamente una lettura sensoristica al server centrale
2) se un valore di questa lettura dovesse essere maggiore di una soglia il sensore deve entrare in stato 
di errore e inviare questa informazione al server centrale
Se il sensore è in stato di allarme non deve fare nulla fino allo sblocco da parte del server centrale
Il segnale di allarme e il segnale di sblocco devono sempre essere AFFIDABILI le varie letture sensoristiche
possono essere invece non affidabili

Il server centrale è un servizio in grado di poter accettare le letture di vari sensori e anche dei loro allarmi
Se un sensore entra in stato di allarme, il server centrale dovrà comunicare ad un server di LOG tale
informazione in maniera affidabile
Se il server centrale ricevesse un segnale di sblocco da parte del server di LOG per un dato sensore, allora
il server centrale dovrà ... 
*/


#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#include "mioProtocollo.h"

//info per il sensore
int socketUDP,socketTCP;
uint16_t sensorID;
uint8_t isBlocked = 0;

//letture sensore:
float temperature;
float humidity;
uint8_t ceRiccobene = 0;

//posizione sensore
char citta[32];


//sensor <ID> <CITTA> <IP-server> <PORT-UDP> <PORT-TCP>
int main(int argc, char* argv[]){

    if(argc < 6){
        printf("Mi devi avviare con: <ID> <CITTA> <IP-server> <PORT-UDP> <PORT-TCP>\n");
        exit(EXIT_FAILURE);
    }

    sensorID = atoi(argv[1]);
    strcpy(citta,argv[2]);

    //info UDP
    struct sockaddr_in infoUDP;
    infoUDP.sin_family = AF_INET;
    infoUDP.sin_port = htons(atoi(argv[4]));
    infoUDP.sin_addr.s_addr = inet_addr(argv[3]);

    //info TCP
    struct sockaddr_in infoTCP;
    infoTCP.sin_family = AF_INET;
    infoTCP.sin_port = htons(atoi(argv[5]));
    infoTCP.sin_addr.s_addr = inet_addr(argv[3]);

    socketUDP = socket(AF_INET, SOCK_DGRAM,0);
    socketTCP = socket(AF_INET,SOCK_STREAM,0);

    if(connect(socketTCP,(struct sockaddr*)&infoTCP,sizeof(infoTCP)) < 0){
        printf("Impossibile collegarsi al server\n");
        exit(EXIT_FAILURE);
    }

    sensor_read_t letturaUscita;
    strcpy(letturaUscita.citta,citta);
    letturaUscita.seonsorID = htons(sensorID);

    for(;;){
        //leggere i dati dei sensori
        //se la temperatura è > 30 allora vai in allarme
        //altrimenti continua a leggere ogni secondo

        temperature = ((float)(rand()/ RAND_MAX)+15.0) + 20;
        humidity = temperature >= 30 ? (((float)(rand()/ RAND_MAX)+15.0) + 20.0)+80 : (((float)(rand()/ RAND_MAX)+15.0)*79.0);
        ceRiccobene = humidity < 50.0 ? 1 : 0;
        isBlocked = temperature >= 30.0 ? 1 : 0;

        letturaUscita.ceRiccobene = ceRiccobene;
        int temp = temperature * 100; //27.5 * 100 = 275 questo perche htonl vuole int e perderi i decimali
        letturaUscita.temperature = htonl(temp);
        int hum = ((int)humidity * 100)/100;    //stessa cosa di temp più o meno
        letturaUscita.humidity = htonl(hum);
        letturaUscita.isBlocked = isBlocked;

        protocol_message_t messaggioOut;
        messaggioOut.type = TYPE_READ;
        memcpy(messaggioOut.payload,&letturaUscita, sizeof(letturaUscita));

        if(isBlocked){
            //mando con TCP (affidabile)
            //allarme
            send(socketTCP,&messaggioOut,sizeof(messaggioOut),0);
            

            protocol_message_t messaggioIn;
            int numBytes = recv(socketTCP,&messaggioOut,sizeof(messaggioOut),0);
            if(numBytes == 0){
                break;
            }
            if(messaggioIn.type == TYPE_UNLOCK){
                sensor_unlock_t sbloccoRivecuto;
                memcpy(&sbloccoRivecuto,messaggioIn.payload, sizeof(sbloccoRivecuto));
                if(ntohs(sbloccoRivecuto.sensorID) == sensorID){
                    isBlocked = sbloccoRivecuto.isBlocked;
                    continue;
                }

            }

        }else{
            //mando le letture (con UDP non affidabile quindi)
           sendto(socketUDP, &messaggioOut, sizeof(messaggioOut),0,(struct sockaddr*)&infoUDP,sizeof(infoUDP));

        }

    }

    close(socketTCP);
    close(socketUDP);
    exit(0);
}