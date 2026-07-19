#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

int main(int argc,char **argv){
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int k = atoi(argv[3]);

    char ***vettoreChar = malloc(n * sizeof(char**));

    for(int i = 0; i<n;i++){
        vettoreChar[i] = malloc(m * sizeof(char*));
        for(int j = 0;j<m;j++){
            vettoreChar[i][j] = malloc(k * sizeof(char));
            strcpy(vettoreChar[i][j],genString(k));
        }
    }

    for(int i = 0; i<n;i++){
        for(int j = 0;j<m;j++){
            printf("%10s",vettoreChar[i][j]);
        }
        printf("\n");
    }

    return 0;
}