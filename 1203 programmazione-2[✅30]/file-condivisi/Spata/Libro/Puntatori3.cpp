#include <iostream>
using namespace std;
int main()
{
   int* Giorni = new int[3];
   Giorni[0] = 15;
   Giorni[1] = 8;
   Giorni[2] = 1999;
   cout  << "Le feste del paese sono in Agosto "
         << Giorni[0] << "/ "
         << Giorni[1] << "/ "
         << Giorni[2];
   delete [] Giorni;        // Libera memoria
   return 0;
}
