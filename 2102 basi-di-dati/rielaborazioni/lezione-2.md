# Il modello relazionale dei dati

Un **modello dei dati** è un insieme di **meccanismi di astrazione** per definire una base di dati con associato un insieme predefinito di **operatori** e **vincoli di integrità**, il modello più diffuso è quello **relazionale** basato sul concetto matematico di **relazione**. 

**Relazione matematica**: una relazione matematica è un sottoinsieme del prodotto cartesiano di più insiemi
- quindi dati $D_1 \dots D_n$  il loro prodotto cartesiano è l'insieme delle **ennuple** formate da tutte le possibili combinazioni e quindi una **relazione** è un insieme di ennuple
- $D_1 \dots D_n$ sono i **domini** della relazione infatti da qua provengono tutti i possibili valori della nostra relazione
![[Pasted image 20251004132907.png|500]]
Le relazioni in matematica hanno una struttura **posizionale** infatti cambiando l'ordine dei vari domini il risultato non resta invariato, invece in informatica le relazioni hanno una struttura **non posizionale** infatti, a ciascun dominio viene assegnato un nome che ne descrive il "ruolo"
![[Pasted image 20251004125821.png|500]]
###### Schema di relazione
Uno **schema di relazione** $R: \{T\}$ è una coppia formata dal nome di una *relazione* **R** e da un *tipo relazione* **T**, 
- **Tipo Relazione (T)**:
	- Definito che interi, stringhe e booleani sono **tipi primitivi**
	- Siano $T_1, T_2, \dots T_n$ tipi primitivi e $A_1, A_2, \dots, A_n$ etichette dette attributi allora $$(A_1:T_1, A_2:T_2, \dots, A_n: T_n)$$è detto un **tipo ennupla di grado n**
	- Dato $T$ un tipo ennupla allora $\{T\}$ un **tipo relazione**
- **Relazione R**
	- la relazione viene definita da un tipo $(A_1:T_1, A_2:T_2, \dots, A_n: T_n)$ e consiste in un insieme finito di ennuple di quel tipo
	- **Cardinalità di una relazione**: il numero di ennuple di quella relazione

> [!TIP] Semplificando
> - Uno **schema di relazione** $R:\{T\}$ collega un nome di relazione $R$ a un **tipo relazione** $T$.
> - I **tipi primitivi** sono interi, stringhe e booleani.
> - Un **tipo ennupla** $(A_1:T_1, \dots, A_n:T_n)$ definisce gli attributi e i loro tipi.
> - Un **tipo relazione** $\{T\}$ indica l’insieme di tutte le possibili ennuple di quel tipo.
> - Una **relazione** $R$ è un insieme finito di ennuple del tipo specificato da $T$.
> - La **cardinalità** di $R$ è il numero di ennuple che contiene.

Uno **schema relazionale** (un database) è costituito da un insieme di schemi di relazione (le tabelle) Inoltre ha un insieme di proposizioni (vincoli di integrità) che permettono di vedere se i dati inseriti sono validi o no.
![[Pasted image 20251004135236.png |500]]
```
Esempio di schema relazionale
{ 
  Studenti : { (Nome : stringa, Matricola : intero(6), Indirizzo : stringa, Telefono :intero(6)) } 
  Esami : { (Corso : stringa, Matricola : intero(6), Voto: {18,19,…,30}) } 
  Corsi : { (Corso: stringa, Professore: stringa) } 
}
```

###### Vincoli di integrità
**I vincoli di integrità** servono a migliorare la qualità delle informazioni contenute nella base di dati, un vincolo deve essere rispettato da ogni ennupla nella base di dati, un'**istanza valida** di uno schema di relazione è una relazione dello schema che soddisfa tutti i vincoli di integrità
![[Pasted image 20251004140720.png|500]]

I vincoli più importanti sono:
- Quali attributi possono assumere il valore **NULL**
- Quali attributi sono **chiave**
- Quali attributi sono **chiave esterna**
###### Chiavi
Un insieme di attributi di uno schema di relazione $R$ è una **superchiave** se ogni istanza valida dello schema non contiene due ennuple con i valori degli attributi della superchiave uguali, invece una **chiave** è una superchiave minimale  
![[Pasted image 20251004142106.png |500]]
- La coppia {Nome, Matricola} è una superchiave
- {Matricola} è una chiave perché contiene il numero minore di attributi per rendere univoca ogni ennupla
L'esistenza delle chiavi garantisce l'accessibilità a ciascun dato della base di dati, inoltre queste ci permettono di mettere in relazione diversi dati tra di loro, infatti le chiavi devono essere sempre valorizzate sennò non permettono di indentificare univocamente le ennuple. Inoltre possiamo dire che ogni relazione è caratterizzata da una superchiave con tutti gli attributi su cui è definita quindi una relazione ha sempre almeno una chiave. Esistono 2 tipi principali di chiavi:
- **Chiave primaria**: è una chiave a scelta per un dato schema, non ammette valori NULL. (per indicare che un attributo è chiave primaria lo si sottolinea)
- **Chiave esterna**: è una chiave che si riferisce alla chiave primaria di un altro schema (per indicare che un attributo è chiave esterna lo si sottolinea tratteggiando)
![[Pasted image 20251004143539.png | 500]]
