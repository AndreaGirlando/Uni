#include <stdio.h>
#include <string.h>
#include <errno.h>
int main(){
    FILE* f = fopen("Meme.txt", "r");
    if(f == NULL) perror("Errore nell'apertura del file");
    for(int i = 0; i < 10; i++){
        printf("Con il codice %d sterror() ha ritornato: %s\n", i, strerror(i));
    }

    return 0;
}