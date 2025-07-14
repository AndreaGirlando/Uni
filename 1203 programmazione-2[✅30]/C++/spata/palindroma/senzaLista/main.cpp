#include <iostream>
using namespace std;
/*
    Scrivere una classe Parola che gestice una stringa e fornisce un metodo per verificare se è palindroma

    creare metodo isPalindroma()
    creare metodo stampa()

*/

class Parola{
    public:
        Parola(string _word): word(_word){}
        bool isPalindroma(){
            const char* string = word.c_str();
            for(int i = 0; i < getLen()/2; i++){
                if(string[i] != string[getLen()-1-i]){
                    return false;
                }
            }
            return true;
        }
        void stampa(){
            cout << word;
        }
    private:
        int getLen(){
            return word.length();
        }
        string word;
};


int main(){

    string temp;
    cout << "Inserisci una parola: ";
    getline(cin, temp);

    Parola parola(temp);
    // parola.stampa();

    if(parola.isPalindroma()){
        cout << "Palindroma";
    } else{
        cout << "Non palindroma";
    }

    return 0;
}