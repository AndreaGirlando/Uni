/*
    pari(n) = dispari(n-1) se n>1
    pari(0) = true
    dispari(n) = pari(n-1) se n>1
    dispari(0) = false;
*/

#include <iostream>
using namespace std;
bool pari(int n);
bool dispari(int n);

bool dispari(int n){
    if(n == 0){
        return false;
    }
    else {
        return pari(n-1);
    }
}

bool pari(int n){
    if(n == 0){
        return true;
    }
    else {
        return dispari(n-1);
    }
}

int main(){
    int n = 20;
    bool isPari = pari(n);
    cout << "N: " << n << endl;
    cout << "isPari: " << isPari << endl;
    bool isDispari = dispari(n);
    cout << "isDispari: " << isDispari << endl;



    cout << endl;
    return 0;
}