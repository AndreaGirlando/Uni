# Normalizzazione di schemi relazionali

###### Problema generale
La progettazione concettuale e logica produce uno schema relazionale che rappresenta la realtà dei dati nella nostra applicazione, ma alcune volte ci sono delle cose che possono essere ottimizzate, si seguito vedremo delle tecniche che ci permettono di farlo

###### Ridondanze
Abbiamo la seguente identità:
*StudenteEsami(Matricola, Nome, Telefono, Corso, Voto)*
Notiamo subito che ci sono dei problemi:
- **Anomalia di aggiornamento**: se il telefono dello studente cambia allora deve essere cambiato in ogni suo esame
- **Anomalia della cancellazione**: se vengono annullati gli esami dati non rimane traccia dello studente
- **Anomalia di inserimento**: se uno studente non ha ancora dato esami non può essere inserito
La soluzione a tutte queste anomalie è decomporre in due relazioni.

###### Dipendenze funzionali
Una dipendenza funzionale è un particolare vincolo di integrità che esprime legami funzionali tra gli attributi di una relazione

**Esempio**: prendendo in esame l'entità StudenteEsami descritta prima abbiamo che: 
- Matricola $\rightarrow$ Nome, Telefono
- Matricola, Corso $\rightarrow$ Voto

Dati:
- $R(A_1,A_2,\dots,A_n)$ uno schema di relazione 
- $X$ e $Y$ sottoinsiemi di $A_1,A_2,\dots,A_n$

Diciamo che *X implica funzionalmente Y* in simboli $X \rightarrow Y$ per ogni relazione $r$ dello schema $R$, se due tuple $t_1$ e $t_2$ di $r$ coincidono su tutti gli attributi di $X$ allora devono anche coincidere su tutti gli attributi di $Y$

**Notazione**: di seguito la notazione
- $A,B, \dots$ attributi
- $U,B,W,X,Y,Z$ insieme di attributi
- $R$ schema di relazione, $r$ relazione
- $ABC$ sta per $\{A,B,C\}$
- $XY$ sta per $X ∪ Y$ 
- $XA$ e $AX$ stanno per $X ∪ {A}$

###### Definizioni
**Soddisfazioni di dipendenze funzionali**: diciamo che una relazione $r$ soddisfa la dipendenza funzionale $X \rightarrow Y$ se per ogni coppia di tuple $t_1$ e $t_2$ in $r$ si ha che:
- $t_1[X] = t_2[X]$ implica $t_1[Y] = t_2[Y]$

**Logica delle dipendenze funzionali**: 
- Sia $F$ un insieme di dipendenze funzionali per uno schema $R$
- Sia $X \rightarrow Y$ una dipendenza funzionale. 
Diciamo che *F logicamente implica* $X \rightarrow Y$ e si scrive $$F ⊨ X \rightarrow Y$$*se per ogni relazione r* di $R$ che soddisfa tutte le dipendenze di $F$, $r$ soddisfa anche $X \rightarrow Y$ 
**Esempio**: $\{A\rightarrow B, B \rightarrow C\}⊨ A \rightarrow C$ 

**Chiusura di un insieme di dipendenze funzionali**: Dato un insieme $F$ di dipendenze funzionali la sua chiusura $F^+$ è l'insieme delle dipendenze funzionali che sono implicate logicamente da $F$ in simboli: $$F^+ = \{X\rightarrow Y | \; F ⊨ X \rightarrow Y\}$$
**Chiavi per uno schema con insieme di dipendenze funzionali**: 
Sia:
- $R(A_1, A_2, \dots, A_n)$
- $F$ un insieme di dipendenze su $R$
- $X$ sottoinsieme di $\{A_1,A_2,...,A_n\}$. 
Si dice che $X$ è una chiave di $(R,F)$ se:
- $X \rightarrow A_1A_2\dots A_n \in F^+$
- $Y \rightarrow A_1A_2\dots A_n \notin F^+$ 

**Commenti**:
- Un istanza di uno schema che rispetti una data dipendenza funzionale viene detta *istanza legale*
- Se $X$ è una chiave in uno schema $R$ allora ogni altro attributo di $R$ dipende funzionalmente da $X$
- Dire che $X\rightarrow Y$ significa asserire che i valori della componente $Y$ dipendono e da i valori della componente $X$
- Se $X \rightarrow Y$ non necessariamente risulta anche $Y \rightarrow X$

###### Necessità di calcolo logico
Il problema è quello di calcolare la chiusura di un insieme $F$ di dipendenze funzionali. 

Per fare ciò definiamo un calcolo logico tale che $F ⊨ X \rightarrow Y$ se e soltanto se $X \rightarrow Y$ si può sintatticamente dedurre da $F$ nel calcolo logico.

###### Assiomi di Armstrong
Di seguito i vari assiomi:
- $U = \{A_1,A_2,\dots A_n\}$ un universo di attributi
- *Riflessività*: $\text{Se } Y \subseteq X \subseteq U \text{ allora } F \vdash X \to Y$
- *Aumento*: $\text{Se } F \vdash X \to Y \text{ allora } F \vdash XZ \to YZ$
- *Transitività*: $\text{Se } F \vdash X \to Y \text{ e } F \vdash Y \to Z \text{ allora } F \vdash X \to Z$

###### Deducibilità di dipendenze funzionali
Diciamo che $F ⊢ X \rightarrow Y$ se $X \rightarrow Y$ si può dedurre da $F$ applicando un numero finito di volte gli assiomi di Armstrong. 
**Esempio:** $\{A \rightarrow B, B \rightarrow C, C \rightarrow D\}  ⊢ A \rightarrow D$ applicando 2 volte la transitività
il risultato dovrà rispetta le due proprietà di seguito:
- *Correttezza*: Se $F⊢X\rightarrow Y$ allora $F  ⊨ X \rightarrow Y$
- *Completezza*: $F ⊨ X \rightarrow Y$ allora $F ⊢ X \rightarrow Y$ 
Se gli assiomi di Armstrong sono dimostrabili allora siamo in grado di capire se una dipendenza funzionale è valida 

Di seguito le dimostrazioni:
![[Pasted image 20251209174505.png|500]]
![[Pasted image 20251209174518.png|500]]
![[Pasted image 20251209174530.png|500]]
![[Pasted image 20251209174555.png|500]]
###### Lemmi per derivare le dipendenze funzionali
**Regola di decomposizione**: Se $F⊢X \rightarrow Y$ e $Z ⊂ Y$ allora $F ⊢ X \rightarrow Z$
![[Pasted image 20251209175006.png|500]]
**Regola dell'unione**: Se $F ⊢ X \rightarrow Y$ e $F ⊢ X \rightarrow Z$ allora $F ⊢ X \rightarrow YZ$ 
![[Pasted image 20251209175115.png|500]]
**Regola di pseudotransitività**: Se $F ⊢ X \rightarrow Y$ e $F ⊢ WY \rightarrow Z$ allora $F ⊢ WX \rightarrow Z$ 
![[Pasted image 20251209175307.png|500]]
**Lemma fondamentale**: Definiamo $X^+_F = \{A | \; F ⊢ X \rightarrow A\}$ e diciamo che $$F ⊢ X \rightarrow Y \text{ se e solo se } Y ⊆ X^+$$
![[Pasted image 20251209175607.png]]

###### Dimostrazione di completezza
![[Pasted image 20251209175648.png|500]]
![[Pasted image 20251209175656.png|500]]
# Chiusure, equivalenze e ricoprimenti minimi

###### Calcolo delle chiusure
Ricordiamo che il calcolo di $F^+ = \{X\rightarrow Y | F⊨ X\rightarrow Y \;\}$ può essere particolarmente costoso 

Ad esempio se $F = \{A\rightarrow B_1, A \rightarrow B_2, \dots, A \rightarrow B_n\}$ allora $F^+$ include $A\rightarrow Y$per ogni $Y$ sottoinsieme di $\{B_1,B_2,\dots,B_n\}$. Quindi ha cardinalità almeno $2^n$.

Invece calcolare $X^+_F = \{A | \; F ⊢ X \rightarrow A\}$ è molto più semplice e lo si fa attraverso il seguente algoritmo: ![[Pasted image 20251209180640.png]]
###### Equivalenze di dipendenze funzionali
Siano $F, G$ insiemi di dipendenze funzionali allora diciamo che sono *equivalenti* se $F^+ = G^+$. 
La relazione di equivalenza tra insiemi di dipendenze ci permette di capire quando due schemi di relazione rappresentano gli stessi fatti, e si fa usando il seguente algoritmo:
- Per ogni $Y \rightarrow Z$  in $F$ controlliamo se essa è in $G^+$ calcolando $Y^+_G$ e controllando se $Z ⊆ Y^+_G$ questo implica $F^+ ⊆ G^+$ 
- Viceversa in maniera analoga si può controllare se $G^+ ⊆ F^+$

###### Insieme di dipendenze minimali
Un insieme di dipendenze funzionali $F$ è *minimale* se:
1. Ogni lato destro di una dipendenza è un singolo attributo
2. Per ogni dipendenza $X \rightarrow A$ in $F$, $F \ \{X \rightarrow A\}$ non è equivalente a $F$
3. Per ogni $X \rightarrow$ A in $F$ e $Z ⊂ X,F \ \{X \rightarrow A\} ∪ {Z \rightarrow A}$ non è equivalente a $F$
Dato $F$ si dice che $G$ è un suo *ricoprimento minimale* se $G$ è minimale ed è equivalente a $F$.

**Teorema**: Ogni insieme di dipendenze funzionali ha un ricoprimento minimale
**Dimostrazione**: ![[Pasted image 20251209181729.png]]
# Decomposizione di uno schema, decomposizioni che preservano i dati

###### Decomposizione di uno schema
Dato uno schema $R = {A_1,A_2,\dots A_n}$ una sua *decomposizione* è un insieme $d = \{R_1, R_2 \dots R_k\}$ di sottoinsiemi di $R$ tali che: $R = R_1 ∪ R_2 ∪ \dots ∪ R_k$ 
**Esempio**:
![[Pasted image 20251209184704.png]]

###### Preservazione dei dati
Decomporre lo schema iniziale comporta il vantaggio di evitare ridondanze nella rappresentazione. Nel nostro caso specifico basta fare una natural join per ottenere la composizione iniziale, questa proprietà della decomposizione si chiama **loss-less joins**

**Definizione**: 
- Dato uno schema $R$ con un insieme $F$ di dipendenze funzionali, 
- una sua decomposizione $D = \{R_1,R_2,\dots R_k\}$ 
si dice che *preserva i dati* se per ogni relazione $r$ di $R$ che soddisfa tutte le dipendenze di $F$ si ha: $$r = \pi_{R_1} (r) \bowtie \pi_{R_2} (r) \bowtie \cdots \bowtie \pi_{R_k} (r)$$
**Osservazioni**: siano 
- $R$ ed $F$ come sopra
- e sia $m_d(r) = \pi_{R_1} (r) \bowtie \pi_{R_2} (r) \bowtie \cdots \bowtie \pi_{R_k} (r)$
allora 
- $r ⊆ m_d(r)$ è sempre vero
- $m_d(r) ⊆ r$ non è sempre vero
**Esempio**
![[Pasted image 20251209190348.png|500]]

Per controllare se una decomposizione preserva i dati facciamo in questo modo:
![[Pasted image 20251209192300.png|500]]
![[Pasted image 20251209192324.png|500]]
![[Pasted image 20251209192334.png|500]]
**Esempio**: 
![[Pasted image 20251209192621.png|500]]
Sappiamo che questo metodo è valido per la seguente dimostrazione:
![[Pasted image 20251209192731.png|500]]
# Decomposizioni che conservano le dipendenze funzionali

###### Conservazione delle dipendenze
La proiezione $\pi_Z(F)$ di $F$ su un insieme $Z$ di attributi è l'insieme delle dipendenze $X \rightarrow$ Y appartenenti a $F^+$ tali che $XY ⊆ Z$

###### Algoritmo per il calcolo della proiezione di un insieme di dipendenze
![[Pasted image 20251210154119.png|500]]

###### Conservazione delle dipendenze II
Dato uno schema relazionale $(R,F)$ ed una sua decomposizione $d = \{R_1,R_2, \dots, R_k\}$ si dice che essa **conserva le dipendenze funzionali** se $F$ è implicata logicamente dall'unione delle proiezioni $\pi_{R_i}(F)$ 

Di seguito **l'algoritmo per controllare se una decomposizione preserva le dipendenze funzionali**:
![[Pasted image 20251210154527.png|500]]

###### Forma normale
Una relazione $r$ è detta in *forma normale di Boyce-Codd (BCNF)* se per ogni dipendenza funzionale $X\rightarrow A$ definita su di essa, $X$ contiene una chiave $K$ di $r$, cioè $X$ è superchiave per $r$
###### Terza forma normale
Una relazione $r$ è detta in *terza forma normale (3NF)* se per ogni dipendenza funzionale $X \rightarrow A$ definita su di essa si ha almeno una delle due seguenti condizioni:
1. $X$ contiene una chiave $K$ di $r$
2. $A$ appartiene ad almeno una chiave di $R$

###### Perché scegliamo queste forme normali?
**BCNF**: lo scopo di questa forma normale è quello di eliminare ridondanze causate dalle dipendenze
![[Pasted image 20251210161228.png|500]]
**3NF**:![[Pasted image 20251210161247.png|500]]
###### Lemmi
![[Pasted image 20251210161526.png|500]]
![[Pasted image 20251210161537.png|500]]
![[Pasted image 20251210161545.png|500]]

###### Decomposizioni che preservano i dati con componenti in BCNF
**Input**: Schema $R$ e dipendenze $F$
**Output**: Decomposizione che preserva i dati tale che ogni componente sia in BCNF rispetto alla proiezione di $F$ su quella componente
![[Pasted image 20251210161740.png|500]]

###### Preservazione delle dipendenze e 3NF
**Input**: $R,F$ con $F$ ricoprimento minimale
**Output**: Una decomposizione di $R$ che **conserva le dipendenze** e tale che ogni suo elemento è in **3NF**
![[Pasted image 20251210162030.png|500]]