// Serve per capire l'endianess del pc dove viene eseguito
#include <stdio.h>
#include <stdint.h>
#include <string.h>
int main (){
    int x = 0x1234567;
    uint8_t buffer[256];
    memcpy(buffer, &x, sizeof(x));
    for(int i = 0; i < sizeof(x); i++){
        printf("%02hhx ", buffer[i]);
    }
    printf("\n");
}
