#include <iostream>
#include <climits>
using namespace std;
unsigned long long int fact(double n){
    if(n==0){
        return 1;
    }else{
        return n*(fact(n-1));
    }
}

int main(){

    int numero;
    cout << "Inserisci un numero: ";
    cin >> numero;

    long long int temp = fact(numero);
    cout << temp << endl;

    return 0;
}