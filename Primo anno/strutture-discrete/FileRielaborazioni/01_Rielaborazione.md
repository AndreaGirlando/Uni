Questo file è la rielaborazione delle slide [[01_Parte1.pdf]]

La **logica** è un linguaggio formale usato per rappresentare informazioni. Ogni linguaggio è formato da:
- Sintassi: che definisce le frasi del linguaggio
- Semantica: che definisce il significato delle frasi
La logica più semplice di tutti è la logica proporzionale oggi connessa al mondo binario, viene detta proporzionale perché si occupa di proposizioni più precisamente di variabili proposizionali, quest'ultime possono assumere solo 2 valori: 
- 1 = VERO
- 0 = FALSO
Ogni variabile proposizionale è già da se una "formula" proposizionale, ovviamente questa è una formula molto basilare. Per creare delle formule più complesse usiamo dei connettivi logici che sono i seguenti:
- ==¬ (negazione)==: si legge "non", e inverte il valore di verità di una proposizione. Se una proposizione è vera, la sua negazione è falsa, e viceversa.
- ==∨ (disgiunzione logica)==: si legge "o", ed è vera se **almeno una** delle due proposizioni è vera.
- ==∧ (congiunzione logica)==: si legge "e", ed è vera se **entrambe** le proposizioni sono vere.
- ==⇒ (implicazione)==: si legge "se... allora…" o semplicemente "implica". È falsa solo se il primo termine è vero e il secondo è falso.
- ==⇔ (doppia implicazione o coimplicazione)==: si legge "se … e solo se …". È vera quando entrambi i termini sono veri o entrambi falsi.
**Esempi di formule** (usando le variabili P e Q scelte casualmente):
- ¬P
- Q
- P ∨ Q  = "P o Q"
- P ∧ Q = "P e Q"
- P ⇒ Q = "se P allora Q"
- P ⇔ Q = P se e solo se Q
Come per le operazioni normali (somma, moltiplicazione, ecc...) anche queste hanno delle precedenze,  la negazione (¬) ha la precedenza su tutto mentre congiunzione (∨) e disgiunzione (∧) hanno la stessa priorità infatti:
- ¬p ∨ q è la formula dove la negazione si applica solo a p 
- ¬(p ∨ q) è la formula dove la negazione si applica alla disgiunzione p ∨ q

Date 2 formule $P_1$ e $P_2$ che ovviamente posso assumere solo una valore (questa cosa la impone una funzione chiamata **interpretazione** che appunto assegna a $P_1$ e $P_2$  i valori 1 o 0) Di seguito si calcola il valore di verità delle seguenti formule complesse: 
- I(¬$P_1$) è vera solo se $P_1$ è vera
- I($P_1$ ∨ $P_2$) è vera se almeno una tra $P_1$ o $P_2$ è vera
- I($P_1$ ∧ $P_2$) è vera se entrambe sono vere
- I($P_1$ ⇒ $P_2$) è vera se I($P_1$) è falsa oppure se I($P_2$) è vera 
- I($P_1$ ⇔ $P_2$) è vera se e solo se I($P_1$ ⇒ $P_2$) è vera e I($P_2$ ⇒ $P_1$) è
Questa è la tabella della verità di tutte queste formule:

| $P_1$ | $P_2$ | ¬$P_1$ | $P_1$ ∨ $P_2$ | $P_1$ ∧ $P_2$ | $P_1$ ⇒ $P_2$ | $P_1$ ⇔ $P_2$ |
| ----- | ----- | ------ | ------------- | ------------- | ------------- | ------------- |
| 1     | 1     | 0      | 1             | 1             | 1             | 1             |
| 1     | 0     | 0      | 1             | 0             | 0             | 0             |
| 0     | 1     | 1      | 1             | 0             | 1             | 0             |
| 0     | 0     | 1      | 0             | 0             | 1             | 0             |

Nomenclature varie:
- Data una formula diremo che è ==**soddisfacibile**== se esiste almeno un caso in cui sia vera, qualunque siano i valori delle variabili ().
- Data una formula diremo che è **==insoddisfacibile==** se non esiste almeno una caso in cui sia vera, qualunque siano i valori delle variabili (esempio $P_2$ ∧ ¬$P_2$).
- Data una formula si dice **==tautologia==** se è sempre vera qualunque siano i valori delle variabili (esempio $P_2$ ∨ ¬$P_2$).
Di seguito degli esempi (usando le variabili della tabella di verità):
- $P_1$ ∧ $P_2$ è soddisfacibile
- $P_2$ ∨ ¬$P_2$ è tautologia (Questo viene chiamato ==**Principio del terzo escluso**==)
- $P_2$ ∧ ¬$P_2$ è insoddisfacibile (Questo viene chiamato ==**Principio di non contraddizione**==)

Due formule $P_1$ e $P_2$ si dicono equivalenti se hanno lo stesso valore è si scrivono in questo modo:  $P_1$ $\equiv$ $P_2$

Per la disgiunzione e la congiunzione vale la proprietà commutativa e associativa 
- p ∨ q ≡ q ∨ p (commutativa della disgiunzione)
- p ∨ (q ∨ r ) ≡ (p ∨ q) ∨ r (associatività della disgiunzione)
