/* Errori nel codice:
Allocazione di memoria insufficiente

p = new char[lunghezza_stringa];
Qui allochi solo lunghezza_stringa caratteri, 
ma poi copi una stringa più lunga con 
strcpy(p, "Carchel tambien esta en Sierra Magina"); 
Se la stringa è più lunga di lunghezza_stringa, 
la strcpy sovrascriverà la memoria non allocata, 
causando comportamento indefinito.

Uso di delete invece di delete[]

delete p;
Poiché p è stato allocato con new[], 
dovresti liberarlo con delete[] p; 
altrimenti si verifica un comportamento indefinito.
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
   int lunghezza_stringa;
   char *p;
   cout << "Quanti caratteri si assegnano? " << endl;
   cin >> lunghezza_stringa;
   cin.ignore(1);
   p = new char[lunghezza_stringa];
   strcpy(p, "Carchel tambien esta en Sierra Magina");
   cout << p << endl;
   delete p;
   cout << "Prema Invio per continuare";
   cin.get();
}  
