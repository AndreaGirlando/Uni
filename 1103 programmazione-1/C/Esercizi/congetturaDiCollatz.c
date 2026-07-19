#include <stdio.h>
#define numeroTraiettorie 100000
int main(){

    int start = 0;

    for(int i = 1; i <= numeroTraiettorie; i++){
        start = i;
        printf("\nn = %d: %8d",i,start);
        while(start > 1){
            if(start % 2 == 0){
                start = start / 2;
                printf("%4d",start);
            }else{
                start = 3 * start + 1;
                printf("%4d",start);
            }
        }
        printf("\n");
    }

    return 0;
}