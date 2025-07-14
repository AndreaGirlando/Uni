#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int lunghezza_stringa;
    cout << "Quanti caratteri si assegnano? " << endl;
    cin >> lunghezza_stringa;
    cin.ignore(); // Ignora il newline rimasto nel buffer

    const char *frase = "Carchel tambien esta en Sierra Magina";

    if (lunghezza_stringa < strlen(frase) + 1) {
        cout << "Errore: lunghezza insufficiente per copiare la stringa!" << endl;
        return 1;
    }

    char *p = new char[lunghezza_stringa]; // Allocazione corretta

    strcpy(p, frase); // Copia sicura
    cout << p << endl;

    delete[] p; // Uso corretto di delete[]

    cout << "Prema Invio per continuare";
    cin.get();
}
