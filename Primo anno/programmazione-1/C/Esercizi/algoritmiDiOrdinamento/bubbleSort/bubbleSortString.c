#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
unsigned int get_random() {
    static unsigned int m_w = 123456;
    static unsigned int m_z = 789123;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

char* genString(int numeroCaratteri){

    char* string = malloc(numeroCaratteri * sizeof(char));

    for(int i = 0;i<numeroCaratteri;i++){
        string[i] = get_random() % (122 - 97 + 1) + 97;
    }
    string[numeroCaratteri] = '\0';

    return string;
}

int main(int argc, char **argv){
    //! Per ordinare il vettore di stringhe in ordine alfabetico lo devo ordinare in modo crescente
    //! al contrario di come si fa di solito con il bubbleSort
    int stringDim = atoi(argv[1]);

    char **stringArray = malloc(stringDim * (sizeof(char*)));

    for(int i = 0; i<stringDim;i++){
        stringArray[i] = genString(5);
    }

    printf("Vettore generato: \n");
    for(int i = 0; i<stringDim;i++){
        printf("%10s",stringArray[i]);
    }


    for(int i = 0; i<stringDim; i++){
        for(int j = 0; j<stringDim-1;j++){

            if(strcmp(stringArray[i],stringArray[j])>0){
                char temp[stringDim];
                strcpy(temp,stringArray[i]);
                strcpy(stringArray[i],stringArray[j]);
                strcpy(stringArray[j],temp);
            }
        }
    }


    printf("\nVettore ordinato in ordine decrescente: \n");
    for(int i = 0; i<stringDim;i++){
        printf("%10s",stringArray[i]);
    }



    for(int i = 0; i<stringDim; i++){
        for(int j = 0; j<stringDim-1;j++){

            if(strcmp(stringArray[i],stringArray[j])<0){
                char temp[stringDim];
                strcpy(temp,stringArray[j]);
                strcpy(stringArray[j],stringArray[i]);
                strcpy(stringArray[i],temp);
            }
        }
    }

    printf("\nVettore ordinato in ordine crescente (e quindi alfabetico): \n");
    for(int i = 0; i<stringDim;i++){
        printf("%10s",stringArray[i]);
    }





    return 0;
}