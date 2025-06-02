#include <iostream>
#include <sstream>

using namespace std;

class ora_del_giorno {
public:
    ora_del_giorno(int o=0, int m=0, int s=0) : ora(o),minuti(m),secondi(s) {}
    ora_del_giorno(const ora_del_giorno& altro) 
    {
        (*this) = altro;
    }

    ora_del_giorno& operator=(const ora_del_giorno& altro);
    ora_del_giorno& operator=(int altro); 
    ora_del_giorno& operator+=(int altro);

    bool operator==(const ora_del_giorno& altro) const;

    friend ora_del_giorno operator+(const ora_del_giorno& ora1, const ora_del_giorno& ora2);
    //in alternativa potrei definirlo in questo modo:
    //ora_del_giorno operator+(const ora_del_giorno& altro) const;

    friend ostream& operator<<(ostream& stream, const ora_del_giorno& ora);

private:
    void aggiusta();

    int ora;
    int minuti;
    int secondi;
};

ora_del_giorno operator+(const ora_del_giorno& ora1, const ora_del_giorno& ora2);

ostream& operator<<(ostream& stream, const ora_del_giorno& ora);

int main()
{
    string line;
    cout << "Inserisci tre valori separati da spazio: ";
    getline(cin,line);
    stringstream stline(line); // includere l'header file #include <sstream>
    int i,j,k;
    stline >> i;
    stline >> j;
    stline >> k;
    ora_del_giorno a(i,j,k);

    ora_del_giorno b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    b = a;
    cout << "b = " << b << endl;
    b += 100;
    cout << "b = " << b << endl;
    b = 80;
    cout << "b = " << b << endl;
    ora_del_giorno c = b + a;
    cout << "c = " << c << endl;

    cout << "c == b + a ? " << (c == (b + a)) << endl;

    return 0;
}

ora_del_giorno& ora_del_giorno::operator=(const ora_del_giorno& altro)
{
    cout << "Effettuo la copia di: " << altro << endl;
    ora = altro.ora;
    minuti = altro.minuti;
    secondi = altro.secondi;
    return *this;
}

ora_del_giorno& ora_del_giorno::operator+=(int altro) 
{
    secondi += altro;
    aggiusta();
    return *this;       
}

ora_del_giorno& ora_del_giorno::operator=(int altro)
{
    ora = 0;
    minuti = 0;
    secondi = 0;
    *this += altro;
    return *this;       
}

void ora_del_giorno::aggiusta()
{
    while (secondi>=60) 
    {
        secondi -= 60;
        minuti++;
    }
    while (minuti>=60) 
    {
        minuti -= 60;
        ora++;
    }
    ora = ora % 24; 
}

ora_del_giorno operator+(const ora_del_giorno& ora1, const ora_del_giorno& ora2)
{
    ora_del_giorno nuovo;
    nuovo.ora = ora1.ora + ora2.ora;
    nuovo.minuti = ora1.minuti + ora2.minuti;
    nuovo.secondi = ora1.secondi + ora2.secondi;
    nuovo.aggiusta();
    return nuovo;
}

ostream& operator<<(ostream& stream, const ora_del_giorno& ora)
{
    stream << ora.ora << ":" << ora.minuti << ":" << ora.secondi;
    return stream;
}

bool ora_del_giorno::operator==(const ora_del_giorno& altro) const
{
    return ((this->ora == altro.ora) && (this->minuti == altro.minuti) && (this->secondi == altro.secondi));
}
