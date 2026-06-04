# Appunti sui Sistemi Operativi

## 1. Ambiti di Sviluppo di un Sistema Operativo
Gli ambiti dove si può sviluppare un S.O. sono molteplici:

* **1° Ambito (Risorsa abbondante) - Mainframe:** Calcolatori che hanno ordini di grandezza enormi, anche come capacità di calcolo. Caratterizzati da sistemi batch (job). Non sono molto diffusi ormai.
* **2° Ambito - Server:** Vi è la necessità di gestire un sistema spesso usato da molte persone. Lavora in multitasking (mandiamo più task al S.O.). È un sistema interattivo con un forte impatto sulla gestione delle risorse.
* **3° Ambito - Personal Computer:** Gestisce le necessità di un utente. Interagisce con vari processi, spesso tramite un'interfaccia grafica. Dev'essere il più reattivo possibile. Anche questo è un sistema interattivo.
> **Nota Sicurezza:** Tutti e tre questi primi ambiti toccano il tema della sicurezza in base a come si comportano e a come vengono utilizzati.
* **4° Ambito - Smartphone:** Sistema interattivo multiprogrammato, molto simile al PC ma diverso per certi aspetti. Ad esempio, la batteria ha una capacità limitata, quindi interviene la CPU per non farla andare in crisi gestendo i processi in background. Qui l'ambito di sicurezza è ancora più elevato.
* **5° Ambito - Sistemi Integrati (Embedded):** Dispositivi elettronici che hanno analogie con console (PS), TV, ecc. Vi è la necessità di gestire più processi, ma lavorano con peculiarità che li semplificano. Una caratteristica chiave è che in questi dispositivi normalmente non possiamo installare altri programmi esterni. Non c'è bisogno di un S.O. con eccessiva complessità.
* **6° Ambito - Real-Time:** Sono calcolatori più o meno complessi che hanno un settore di applicazione ben preciso. Chi li governa ha il compito di farli funzionare e fargli assolvere i loro compiti specifici. Utilizzano S.O. fortemente caratterizzati dalle tempistiche di reazione, per evitare che l'imprevedibilità crei situazioni critiche/spiacevoli. Sono sistemi chiusi dove i processi collaborano strettamente tra loro.

---

## 2. Possibili Strutture di un S.O.

* **Sistemi Monolitici:** È la prima struttura di un S.O., storicamente. È una struttura poco organizzata basata su un unico kernel che contiene tutto al suo interno. Ha tante procedure dove "ognuno si occupa di tutto" stile spaghetti code. Avere tanti processi tutti insieme porta a una scarsa manutenibilità. *Esempio storico:* Le prime versioni di UNIX.
* **Sistemi a Livelli / Strati:** Utilizza una gerarchia a livelli, dove ogni livello implementa una funzionalità e gestisce un protocollo. A ogni livello abbiamo un'astrazione (implementa un'interfaccia). Ogni strato offre un servizio a quello superiore e gli strati sottostanti aiutano quelli superiori.
    * *Vantaggi:* Permette l'isolamento degli obiettivi e dell'implementazione (i bug possono essere isolati facilmente). Aiuta a scrivere codice più ordinato.
    * *Svantaggi (Overhead):* L'overhead è il tempo extra che la CPU impiega per far funzionare il sistema stesso. Più strati abbiamo, più aumenta l'overhead. *Esempio:* Sistemi Multics.
* **Microkernel:** Da un kernel monolitico si "estrae" solo il nucleo piccolissimo ma fondamentale per gestire la macchina. I servizi aggiuntivi diventano processi utente (con spazi isolati di memoria) eseguiti in *user-mode*. 
    * Per funzionare, il kernel e questi processi esterni devono comunicare tramite **IPC** (Inter-Process Communication).
    * *Esempi:* Mac OS, Minix 3.
* **Struttura a Moduli:** Ci sono delle parti elementari nel nucleo centrale, e poi una serie di servizi e funzionalità progettate in termini di "moduli". Questi ultimi sono simili a oggetti: hanno strutture interne e un'interfaccia per far usufruire dei servizi.
    * *Differenza con Microkernel:* Quando i moduli vengono caricati in memoria, vengono eseguiti in *kernel-mode*, diventando parte integrante del S.O. a tutti gli effetti.
    * *Differenza con i Livelli:* Qualunque modulo può invocare un altro modulo in qualsiasi momento, senza i vincoli rigidi della gerarchia a strati.

---

## 3. Macchine Virtuali e Virtualizzazione
*L'estremizzazione del concetto di astrazione porta alla virtualizzazione.*

* **Definizione:** È un software che gira su un computer fisico. In pratica è un file (o un set di file) che si comporta a tutti gli effetti come se fosse un intero sistema hardware indipendente.
* **Utilizzi principali:** Si usa per fare testing di programmi o di nuovi sistemi operativi. È utilissimo anche per l'isolamento, ad esempio per testare file sospetti evitando che l'host prenda virus.
* **Hypervisor:** Tutto l'ambiente viene gestito dall'**Hypervisor** (es. *VirtualBox*). Questo livello software prende una parte delle risorse fisiche del PC (RAM, disco, ecc.) e le assegna in modo isolato alla virtual machine.
* **Esecuzione:** Il codice della macchina virtuale viene comunque eseguito e "gira" sulla CPU fisica della macchina host, quindi le architetture devono essere compatibili affinché l'esecuzione sia veloce ed efficiente.