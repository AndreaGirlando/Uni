## 1. Struttura dell'Equazione

Data una ricorrenza nella forma:

$$T(n) = a T\left(\frac{n}{b}\right) + f(n)$$
- **$a$**: Numero di sotto-problemi (numero di rami per nodo).
- **$n/b$**: Dimensione di ogni sotto-problemo.
- **$f(n)$**: Costo del lavoro svolto al livello corrente (escluso il costo delle chiamate ricorsive).
---
## 2. Parametri dell'Albero

- **Livello ($i$):** Parte da $0$ (radice).
- **Dimensione del problema al livello $i$:** $n/b^i$.
- **Numero di nodi al livello $i$:** $a^i$.
- **Lavoro totale al livello $i$ ($L_i$):** $a^i \cdot f\left(\frac{n}{b^i}\right)$.
- **Altezza dell'albero ($h$):** $h = \log_b n$.
- **Numero di foglie:** $n^{\log_b a}$.
---
## 3. Analisi del Lavoro per Livello ($L_i$)

Dopo aver calcolato $L_i$ e semplificato i termini, si presentano due scenari:
### A. Lavoro Costante per Livello
Se i termini con la $i$ si annullano (il lavoro è uguale in ogni piano):
- **Logica:** Si moltiplica il lavoro di un singolo livello per il numero totale di livelli.
- **Formula:** $T(n) = L_i \cdot (\text{altezza} + 1) = L_i \cdot (\log_b n + 1)$.
- **Esempio:** Se $L_i = n^2$, allora $T(n) = \Theta(n^2 \log n)$.
### B. Lavoro Variabile per Livello
Se dopo la semplificazione resta un termine dipendente da $i$ (es. $n \cdot r^i$):
- **Logica:** Bisogna risolvere la sommatoria $\sum r^i$ (Serie Geometrica).
- **Formula:** $T(n) = \sum_{i=0}^{h-1} L_i + \text{costo foglie}$.

---
## 4. Regole Rapide di Complessità
In base alla ragione $r$ della serie geometrica
1. **Lavoro Decrescente ($r < 1$):**
    - Il costo è dominato dalla **radice**.
    - $T(n) = \Theta(f(n))$.
2. **Lavoro Costante ($r = 1$):**
    - Il costo è distribuito equamente.
    - $T(n) = \Theta(f(n) \cdot \log_b n)$.
3. **Lavoro Crescente ($r > 1$):**
    - Il costo è dominato dalle **foglie**.
    - $T(n) = \Theta(n^{\log_b a})$.
---
## 5. Formule Utili (Serie Geometriche)
- **Serie Geometrica Finita ($r \neq 1$):** $\sum_{i=0}^{k} r^i = \frac{r^{k+1} - 1}{r - 1}$
- **Serie Geometrica Infinita ($|r| < 1$):** $\sum_{i=0}^{\infty} r^i = \frac{1}{1 - r}$
- **Proprietà Logaritmi:** $a^{\log_b n} = n^{\log_b a}$