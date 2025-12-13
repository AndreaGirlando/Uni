# Algoritmi di ordinamento senza confronti 

### Counting sort

###### Premesse
Per superare la barriera imposta dall'albero di decisione abbiamo bisogno di algoritmi di ordinamento che non fanno confronti, e quindi presentiamo il counting sort. Per fare questa cosa il counting sort suppone che ciascuno degli $n$ elementi in input sia un intero compreso tra $0$ e $k$

###### Algoritmo
Per usare il counting sort abbiamo bisogno:
- $A$ un array in input di $n$ elementi interi che vanno da $0-k$
- $C$ un array con $k$ celle i cui valori indicano il numero di occorrenze di $k$ in $A$
- $B$ array di output

```
Counting-Sort(A, B, n):
    k = max(A)                     // valore massimo in A
    C = new Array(k+1)

    // inizializza C a 0
    for i = 0 to k:
        C[i] = 0

    // conta le occorrenze
    for i = 0 to n-1:
        C[A[i]] = C[A[i]] + 1

    // calcola le posizioni cumulative
    for i = 1 to k:
        C[i] = C[i] + C[i-1]

    // costruisci l'array ordinato B in maniera stabile
    for i = n-1 downto 0:
        B[C[A[i]] - 1] = A[i]     // -1 perché B è 0-indexed
        C[A[i]] = C[A[i]] - 1

```

Di seguito per step la spiegazione:
1. Cerchiamo il nostro $k$ che sarebbe il massimo di $A$
2. Creiamo il nostro array $C$ con $k+1$ posizioni
3. *Primo FOR*: inizializza a 0 l'array C
4. *Secondo FOR*: controlliamo ogni elemento di $A$ e incrementiamo di uno l'indice corrispondente in $C$
	- Dopo questo passo $C[i]$ contiene il numero di occorrenze di $i$ in $A$
5. *Terzo FOR*: contiamo il numero di elementi in $A$ minore o uguali $i$
6. *Quarto FOR*: Inseriamo ogni elemento di $A$ dentro $B$ usando come indice il valore calcolato nel terzo passaggio, la riduzione di $C[A[i]]$ serve per fare in modo che il successivo elemento con valore uguale ad $A[j]$ venga inserito una posizione prima

###### Implementazione
```C++
void countingSort(int *A, int* B, int n){
    int k = max(A, n);
    int* C = new int[k+1];
   
    for(int i = 0; i <= k; i++)
        C[i] = 0;

    for(int i = 0; i < n; i++)
        C[A[i]] = C[A[i]] + 1;

    for(int i = 1; i <= k; i++)
        C[i] = C[i]+C[i-1];

    for(int i = n-1; i >= 0; i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }
   
}
```
Questa implementazione se avviata sull'array: $A = \{2,6,1,7,8\}$ da il seguente output:
```
Array di base: 2 - 6 - 1 - 7 - 8
Primo For: 0 - 0 - 0 - 0 - 0 - 0 - 0 - 0
Secondo For: 0 - 1 - 1 - 0 - 0 - 0 - 1 - 1
Terzo For: 0 - 1 - 2 - 2 - 2 - 2 - 3 - 4
Quarto For: 1 - 2 - 6 - 7 - 8
```
###### Complessità
- il primo ciclo impiega $\Theta(k)$
- il secondo $\Theta(n)$
- il terzo $\Theta(n)$
- il quarto $\Theta(k)$
Quindi il tempo totale è $\Theta(n+k)$
Inoltre è **stabile**: ovvero i numeri con lo stesso valore si presentano nell'array di output nello stesso ordine in cui si trovano nell'array di input, questa cosa solitamente è importante solo quando abbiamo dati satellite, ma nel counting è sempre importante perché molte volte viene usato come subroutine per implementare il radix sort.

### Radix sort

###### Premesse
Il radix sort è l'algoritmo di ordinamento usato in principio per ordinare le schede perforate, ma ai giorni nostri viene utilizzato per ordinare in base a più chiavi contemporaneamente (es: anno, mese e giorno)

###### Algoritmo
Dati:
- $n$ numeri
- ogni numero ha $h$ cifre
- ogni cifra può avere fino a $k$ valori

quello che fa questo algoritmo è ordinare rispetto considerando solo una cifra dei numeri, partendo da quella meno significativa.  La sua implementazione tramite pseudocodice è molto semplice ma implica anche l'implementazione di un algoritmo di ordinamento stabile interno per ordinare rispetto ad una cifra (per noi sempre il counting sort)

```
RadixSort(A, n, h)
	for i <= 0 to h = 1 do:
		countingSort(A, n, i)
```

###### Implementazione
Ricordiamo che le cifre di un numero si estraggo facendo il modulo 10 nel nostro caso la formula per calcolare una cifra di un numero alle i-esima posizione diventa $$(A[i] \backslash 10^h) \% 10$$
```C++
int scegliCifra(int numero, int digit){
    return (numero/(int)pow(10,digit))%10;
}

void countingSortConCifraSpecifica(int *A, int n, int cifra) {
    const int k = 9;
    int* B = new int[n];
    int* C = new int[k + 1];
    
    for(int j = 0; j <= k; j++)
        C[j] = 0;
        
    for(int j = 0; j < n; j++) {
        C[scegliCifra(A[j], cifra)] = C[scegliCifra(A[j], cifra)] + 1;
    }
  
    for(int j = 1; j <= k; j++)
        C[j] = C[j] + C[j-1];
     
    for(int j = n - 1; j >= 0; j--) {
        int d = scegliCifra(A[j], cifra);
        B[C[d] - 1] = A[j];
        C[d] = C[d] - 1;
    }

    for (int j = 0; j < n; j++) {
        A[j] = B[j];
    }

}

void radixSort(int* A, int len, int h){
    for(int i = 0; i < h; i++){
        countingSortConCifraSpecifica(A, len, i);
    }
}
```

###### Complessità
La sua complessità dipende dall'algoritmo di ordinamento usato al suo interno, nel nostro caso abbiamo usato il counting sort quindi abbiamo una complessità: $$O(h(n+k)) \in O(n)$$


# Dizionari
