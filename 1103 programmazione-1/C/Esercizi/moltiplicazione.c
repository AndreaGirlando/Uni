#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){


    int mA[2][3] = {{1,2,3},{4,5,6}};
    int mB[3][2] = {{4,0},{0,1},{-1,0}};

    int res[2][2] = {0};

    for(int i = 0; i<2; i++){
        for(int j = 0; j<3; j++){
            printf("\n%d * %d\n",mA[i][j],mB[j][i]);
        }
    }

    return 0;
}