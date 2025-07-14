Quando i nostri elementi non sono ordinati, per cercare un dato all'interno usiamo **la ricerca sequenziale**, di seguito uno snippet di codice di come viene implementata: 
la complessità di questo algoritmo è: $O(n)$
```c++
int ricercaLineare(int vettore[], int dim, int key){
	for(int i = 0; i < dim; i++){
		if(vettore[i] == key){
			return i
		}
		return -1
	}
}
```

Se il nostro array è ordinato possiamo usare la **ricerca binaria** per capire come ordinare un'array guardare [[Ordinamento]] 
