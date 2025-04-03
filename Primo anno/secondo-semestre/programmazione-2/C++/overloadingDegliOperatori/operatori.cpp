#include <iostream>
using namespace std;

class ora_del_giorno{
    public:
        //! This è il puntatore a questo oggetto stesso
        ora_del_giorno(int o = 0, int m = 0, int s = 0) : ora(o), minuti(m), secondi(s) {};
        ora_del_giorno(const ora_del_giorno& altro){
            (*this) = altro;
        }
        //Possiamo definire il la funzione come constante, si usa per specifare che quella funzione non scrive
        void stampa() const{
            cout << ora << ":" << minuti << ":" << secondi << "\n\n";
        }
        //! Vogliamo definire un operatore in grado di assegnare un'ora del giorno ad un'altro oggetto dello stesso tipo

        //? Operatore di copia
        //? operator può essere usato anche fuori dalla classe
        //? Praticamente una funzioen definita solo quando viene richiamato l'operatore = usando la classe ora_del_giorno
        ora_del_giorno& operator=(const ora_del_giorno& altro){
            cout << "Effettuo la copia di usando l'operatore di copia: ";
            altro.stampa();
            ora = altro.ora;
            minuti = altro.minuti;
            secondi = altro.secondi;
            return *this;
        }
        ora_del_giorno& operator=(int altro){
            ora = 0;
            minuti = 0;
            secondi = 0;
            *this += altro; //?In questo modo non duplichiamo il codice e usiamo sempre lo stesso operatore
            return *this;
        }
        ora_del_giorno& operator+=(int altro){
            secondi += altro;
            aggiusta();
            return *this;
        }
        //! Di seguito la definizione della somma tra 2 oggetti di tipo ora del giorno
        ora_del_giorno operator+(const ora_del_giorno& altro) const {
            ora_del_giorno nuovo  = *this;
            nuovo.ora = ora + altro.ora;
            nuovo.minuti = minuti + altro.minuti;
            nuovo.secondi = secondi + altro.secondi;
            nuovo.aggiusta();
            return nuovo;
        }

    private:
        int ora;
        int minuti;
        int secondi;
        void aggiusta(){
            while(secondi >= 60){
                secondi -= 60;
                minuti++;
            }
            while(minuti >= 60){
                minuti -= 60;
                ora++;
            }
            ora = ora % 24;
        }
};

// ora_del_giorno operator=(ora_del_giorno ora1, ora_del_giorno ora2){}
// implementazione esterna dalla classe di operator=

int main(){

    //? Gli operatori sono i seguenti: +-*/= == ecc..

    int i,j,k = 0;
    k = i+j; //Tipico uso dell'operatore +

    j = i+j; //+ operatore binario
    j++; //++ operatore unario

    ora_del_giorno a(15,25,26);
    cout << "a: ";
    a.stampa();
    ora_del_giorno b = a;
    cout << "b: ";
    b.stampa();

    b += 10;
    cout << "b: ";
    b.stampa();

    b = 120;
    cout << "b: ";
    b.stampa();


    (a + b).stampa();
    //Possiamo ridefinire gli operatori in qualsiasi classe (guarda classe ora_del_giorno)

    return 0;
}

//TODO Modificare l'implementazione come ha fatto il prof ovverro mettendo tutte le dichiarazioni fuori dalla classe
//TODO Guarda anche l'implementazione dell'operatore << usato insieme a cout
