#include <stdio.h>

int main(){

    int b[5] = {1,2,3,4,5};
    printf("%d", *(b+2));
    printf("%d", *b);


    return 0;
}