#include <iostream>
using namespace std;
/*
    Implementa una classe chiamata bankAccount che rappresenti un semplice conto bancario.
    La classe deve permettere di:

    - Creare un conto con un nome del proprietario e un saldo iniziale
    - Depositare denaro
    - Prelevare denaro (solo se ci sono abbastanza fondi)
    - Visualizzare il saldo attuale
    - Stampare le informazioni del conto
    Specifiche della classe
    privati:
        string ownerName
        double balance
    pubblici:
        Costruttore per inizzializzare il conto con nome e saldo iniziale
        void deposit(double amount) Deposita denaro
        void withdraw(double amount) Preleva denaro
        double getBalance() Restituisce il saldo attuale
        void printAccountInfo() Stampare le informazioni del conto
*/

class bankAccount{
    public:
        bankAccount(string _ownerName, double _balance): ownerName(_ownerName), balance(_balance){
            cout << "Account creato con successo! \n";
        };
        void deposit(double amount){
            cout << "Deposito di " << amount << " fatto!\n";
            balance += amount;
        }
        void withdraw(double amount){
            if(balance - amount >= 0){
                cout << "Prelievo di " << amount << " fatto! \n";
                balance -= amount;
                return;
            }
            cout << "Fondi insufficienti \n";
        }
        double getBalance(){
            return balance;
        }
        void printAccountInfo(){
            cout << "\nOwnerName: " << ownerName << "\nBalance: " << balance << "\n";
        }
    private:
        string ownerName;
        double balance;
};

int main(){

    string name;
    cout << "Crea il tuo account bancario \n";
    cout << "Inserisci il tuo nome: ";
    getline(cin,name);

    bankAccount user(name,0);
    user.deposit(500);
    user.deposit(500);
    user.withdraw(500);
    user.withdraw(500);
    user.withdraw(500);
    user.printAccountInfo();





    return 0;
}