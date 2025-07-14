#include<stdio.h>
int main() {
    int x; // dichiara x, valore indefinito
    printf("Valore indeterminato: %d\n", x); // valore indeterminato
    x = 5; // operatore di assegnamento, assegna il valore 5
    x = 2; // operatore di assegnamento, cambia il valore in 2

    // l'operatore di assegnamento restituisce il valore assegnato
    // pertanto, questo operatore può essere utilizzato in altre espressioni
    int y = 2 + (x = 3); //assegna 3 a x e poi calcola y = 2 + 3

    printf("%d\n",x); // 3
    printf("%d\n",y); // 5

    // É possibile effettuare più assegnamenti nella stessa istruzione come segue
    int z;
    x = y = z = 2;
    printf("%d %d %d\n", x, y, z); // 2 2 2

    // In C esistono anche degli operatori di assegnamento composto che permettono
    // Di unire in una unica istruzione l'operazione di assegnemento e una operazione aritmetica
    float h = 1;
    h+=1; //equivalente a x = x+1 
    printf("\n%f\n",h); //2
    h*=5; //equivalente a x = x*5
    printf("%f\n",h);//10
    h-=3; //equivalente a x = x-3
    printf("%f\n",h); //7
    h/=2; //equivalente a x = x/2
    printf("%f\n",h); //3.5

    // Le operazioni di incremento del tipo x = x + 1
    // Sono molto comuni, per cui C mette a disposizioni 
    // Due notazioni abbreviate: la prefissa (++x) e la suffissa (x++)


    int l = 1;
    printf("\n%d\n",++l); //2  //incrementa l di 1 e restituisce il valore l+1
    printf("%d\n",l++); //2  //incrementa l di 1 e restituisce il valore l
    printf("%d\n",l); //3  //stampa il valore di l

    // Analogamente, esistono degli operatori di decremento
    printf("\n%d\n",--l); //2 //incrementa l di 1 e restituisce il valore l+1
    printf("%d\n",l--); //2 //incrementa l di 1 e restituisce il valore l
    printf("%d\n",l); //1  //stampa il valore di l
}
