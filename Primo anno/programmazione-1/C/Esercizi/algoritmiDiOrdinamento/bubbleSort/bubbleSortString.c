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

int main(int argc, char **argv){

    int stringDim = atoi(argv[1]);

    char **stringArray = malloc(stringDim * (sizeof(char*)));

    for(int i = 0; i<stringDim;i++){
        stringArray[i] = genString(stringDim);
    }

    for(int i = 0; i<stringDim;i++){
        printf("%20s",stringArray[i]);
    }

    return 0;
}