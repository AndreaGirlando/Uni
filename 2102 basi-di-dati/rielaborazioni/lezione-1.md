# Introduzione alle basi di dati
**Una base di dati** è un insieme organizzato di dati che esistono e si evolvono nel tempo, disponibili in una cerca struttura per lo svolgimento della propria attività, quest'ultime sono molto essenziali in molteplici attività:
- *Mantere record interni ad una struttura*
- *Offrire servizi tramite internet*
- *Supportare diversi commerciali*
- ecc...
In qualsiasi attività le informazioni vengono gestite in diversi modi in specifico nei sistemi informatici le informazioni vengono rappresentate attraverso i **dati**, quest'ultimi devono essere sempre interpretati perché costituiscono spesso una risorsa strategica per fare ciò vengono usati i DBMS
###### Database management system (DBMS)
Un DBMS è uno strumento particolarmente potente per la **creazione e la gestione efficiente ed efficace di dati**, questo strumento permette all'utente di accedere o modificare i dati attraverso un potente linguaggio di interrogazione, ne esistono molteplici come:
- Oracle
- SQLServer
- MySQL
- PostgreSQL
###### Modello dei dati
Il modello con la quale i dati vengono rappresentati è un formalismo matematico composto da due parti:
- Una **notazione** per descrivere i dati
- Un insieme di **operatori** per manipolare tali dati
i principali modelli di dati sono 2:
- **modelli logici**: sono indipendenti dalle strutture fisiche e pur essendo un modello astratto riesce comunque a riflettere una particolare organizzazione logica 
	- come il **modello relazionale** che prevede un costruttore detto **relazione**, che permettere di definire insiemi di record omogenei usando un insieme di nomi (detti attributi) ![[Pasted image 20251004114211.png]]in questo caso gli attributo sono: Nome, Matricola, Indirizzo e Telefono
- **modelli concettuali**: permettono di rappresentare i dati in modo indipendente da ogni sistema, vengono utilizzati nelle fasi preliminari di progettazione, il modello più noto è il modello **entità-relazione**

###### Architettura di un DBMS 
Un DBMS viene generalmente diviso in due schemi:
- **Schema logico**: descrizione della base di dati attraverso un modello logico
- **Schema fisico**: rappresentazione dello schema logico per mezzo di strutture di memorizzazione

> [!FAQ] Indipendenza fisica
> Il livello logico è **indipendente** rispetto a quello fisico infatti una tabella è utilizza nello stesso modo qualunque sia la sua realizzazione fisica 

- **Schema esterno**: descrizione di parte della base di dati in un modello logico (viste, derivate o anche modelli diversi)
	- Esempio di vista: ![[Pasted image 20251004115125.png]]
> [!FAQ] Indipendenza logica
> Il livello esterno è indipendente da quello logico, aggiunte o modifiche alle viste non richiedono modifiche al livello logico

###### Linguaggi nei DBMS
Nei DBMS distinguiamo due linguaggi:
- **Data-definition language (DDL)**: consente all'utente di creare nuovi database e di specificarne i loro **schemi** (logici, esterni o fisici)
- **Data-manipulation language (DML)**: da agli utenti la possibilità di interrogare e modificare **istanze** di basi di dati