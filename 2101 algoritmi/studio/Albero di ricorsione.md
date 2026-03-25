# Metodo albero di ricorsione – versione rapida

1. **Identifica la ricorrenza**  
    $$(T(n) = \text{sottoproblemi} + f(n))  $$
2. **Costruisci i livelli dell’albero**
    - Livello 0: $(f(n))$
    - Livello 1: costi dei sottoproblemi
    - Livello i: costi dei sottoproblemi del livello precedente
3. **Scrivi il costo di ogni livello**
    - (a) sottoproblemi di dimensione $$(n/b) → livello i = (a^i \cdot f(n/b^i))$$
    - 1 sottoproblema → livello $$i = (f(n/2^i))$$
4. **Conta il numero di livelli**
    - Finché dimensione = 1 → $$livelli ≈ (\log n)$$
5. **Somma i livelli**
    - Livelli decrescenti → domina il primo
    - Livelli crescenti → domina l’ultimo
    - Livelli simili → moltiplica per numero livelli
6. **Risultato finale (solo l’ordine di grandezza)**
    - Non serve somma esatta, basta capire quale livello domina