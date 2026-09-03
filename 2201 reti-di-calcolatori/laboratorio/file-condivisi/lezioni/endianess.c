#include <stdio.h> 
#include <stdint.h> 
#include <string.h>
#include <arpa/inet.h>

int main (){ 
    printf("Rappresentazione endianess in base al PC in uso:\n");
    int x = 0x1234567; 
    uint8_t buffer[256]; //intero senza segno a 8bit quindi è = 1 byte oppure ad un char (il char è 1 byte)
    memcpy(buffer, &x, sizeof(x)); //copia parti di memoria in altre parti di memoria, dentro al buffer metti tutto quello che prendi dal secondo parametro
    for(int i = 0; i < sizeof(x); i++){ 
        printf("%02hhx ", buffer[i]);
    } 
    printf("\n"); 
    //fino a qui vedo se il mio pc usa big o little endian

    //ora lo scriviamo secondo lo standard (network byte order)
    printf("Rappresentazione endianess usando il network byte order:\n");    
    uint32_t network_order = htonl(x); //htonl converte da little endian a big endian che è lo standard del network byte order 
    uint8_t buffer2[256]; 
    memcpy(buffer2, &network_order, sizeof(network_order)); 
    for(int i = 0; i < sizeof(network_order); i++){ 
        printf("%02hhx ", buffer2[i]); 
    }
    printf("\n"); 

    //con le stringhe la cosa del big o little endian non funziona perché le stringhe vengono codificate in ASCII sempre in ogni PC
    printf("Rappresentazione usando le stringhe:\n");
    char text[] = "Hello"; 
    uint8_t buffer3[256]; 
    memcpy(buffer3, text, sizeof(text)); 
    for(int i = 0; i < sizeof(text); i++){ 
        printf("%02hhx (%c) ", buffer3[i], buffer3[i]); 
    } 
    printf("\n");
}