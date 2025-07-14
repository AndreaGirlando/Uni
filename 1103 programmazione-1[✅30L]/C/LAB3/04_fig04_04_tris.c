#include<stdio.h>
#include<math.h>
#define R 0.05

int main() {
    int n = 10;
    double p = 1000;

    //double a = p*pow((1+R),n);

    double a = p;

    for(int i=0; i<n; i++) {
        a = a + a*R;
    }

    printf("%lf\n",a);
}