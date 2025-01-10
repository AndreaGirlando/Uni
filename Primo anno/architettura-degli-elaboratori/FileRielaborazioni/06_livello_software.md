Questo file è la rielaborazione delle slide [[06_Livello-software.pdf]]

---

Il processo di programmazione consiste nel seguente paradigma:
1. Il programmatore scrive il programma in **linguaggio ad alto livello**
2. Il **compilatore** traduce il linguaggio ad alto in **linguaggio macchina assemblativo**
	- trasforma una serie di file sorgenti di linguaggio ad alto livello in file sorgenti assembly
3. L'**assemblatore** traduce il programma in linguaggio assemblativo in **sequenze binarie** 
	- trasforma una serie di file sorgenti assembly in file oggetto
4. Il **linker** collega assieme vari file oggetto e file di libreria in un unico programma oggetto 

![[Pasted image 20250103213625.png|500px]]

Per generare il file oggetto l'assemblatore esegue i seguenti passi:
1. Genera la codifica delle istruzioni espresse in assembly
2. Riconosce le direttive di assemblatore per l’allocazione di memoria mettendo queste informazioni nell’header del file oggetto
3. Riconosce le direttive che assegnano nomi a costanti
4. Sostituisce il valore binario ad ogni occorrenza di etichette di indirizzi relativi nel codice

Nel caso in cui l'assemblatore fosse del tipo "a due passi", man mano che incontra le etichette e dichiarazione di constanti, tiene traccia dei nomi dentro una **tabella dei simboli**, per poi sostituire ogni occorrenza di un nome con il valore indicato nella tabella. Questo tipo di assemblatore viene detto a 2 passate perché fa tutto ciò in 2 passi distinti:
- Passo 1: scorre il codice e raccoglie tutti i simboli
- Passo 2: scorre di nuovo il codice sostituendo i simboli con i valori in tabella

---
###### Loader
File sorgente, file oggetto e dati sono memorizzati nella memoria secondaria, per essere caricati in memoria facciamo uso del loader, per fare ciò esegue i seguenti step:
1. Leggere le informazioni quali la lunghezza del programma e la locazione dell'header del file oggetto.
2. Caricare il programma in memoria sulla base di tali informazioni
3. Saltare alla prima istruzione del programma da eseguire

---
###### Linker
Nella maggior parte dei casi un programma è distribuito in più file sorgente, in questi casi l'assemblatore genera un file oggetto incompleto, il file oggetto completo lo genera il **linker** che si occupa di combinare più file oggetto separati risolvendo i riferimenti a nomi esterni, inoltre crea il file eseguibile e lo salva sul disco.

---
###### Librerie
i file sorgente esterni di cui parlavamo nel linker, molte volte fanno parte di librerie di file, ovvero degli archivi di file oggetto utilizzabili in programmi esterni, i riferimenti vengono risolti sempre dal linker che andrà a risolvere i vari riferimenti nel programma oggetto finale.

---
###### Compilatore
Questo programma si occupa di trasformare un file sorgente scritto in linguaggio ad alto livello in un file scritto in assembly, un compilatore che riorganizza le istruzioni per ottimizzare il codice viene detto ottimizzante. Un programma ad alto livello può chiamare sottoprogrammi presenti in altri file assembly o scritti in altri linguaggi (il linker gestirà i collegamenti). Il compilatore è in grado di rilevare errori sintattici e nomi sconosciuti nel codice sorgente, ma non errori di programmazione (bug)

---
**Debugger**
il debugger è un programma che ci permette di eseguire il programma oggetto ed interrompere la sua esecuzione in qualsiasi instante, in modo da poterne valutare il suo funzionamento. Esistono 2 tipi di debugger:
- **Trace mode**: il programma viene eseguito passo-passo, interrompendosi dopo ogni istruzione
	- Si genera un’eccezione al termine dell’esecuzione di ogni istruzione del programma, il debugger viene lanciato come routine di servizio dell’istruzione cosicché il programmatore posso controllare il corretto funzionamento di quell'istruzione, una volta che il programmatore seleziona il comando per continuare l’esecuzione viene effettuato un rientro dall’interruzione e viene eseguita l’istruzione successiva
- **breakpoint**: l'esecuzione del programma si interrompe in punti di osservazione specifici
	- Quando il Debugger è in esecuzione, il programmatore può scegliere dei punti di osservazione (breakpoint) dove interrompere il programma. il debugger sostituisce e mette da parte le istruzioni in corrispondenza dei breakpoint con speciali interruzioni software (Trap), il programma viene eseguito normalmente fino ad arrivare alla prima Trap, dove l’esecuzione passa al Debugger, una volta che il programmatore seleziona il comando per continuare l’esecuzione il Debugger riprende l’esecuzione del programma
---
**Sistema operativo**
Il sistema operativo gestisce il coordinamento generale di tutte le attività del calcolatore. Il SO è formato da un insieme di routine essenziali che risiedono nella memoria centrale e un insieme di programmi di utilità che risiedono su disco e vengono caricati in memoria centrale per essere eseguiti. Durante l’inizializzazione del sistema, un processo di avvio (boot-strapping) viene usato per caricare in memoria una porzione iniziale del SO. Sistemi operativi capaci di eseguire più istruzioni contemporaneamente sono chiamati **concorrenti** o **multitasking**, per fare ciò il sistema operativo divide il tempo di esecuzione di un programma in slice di tempo, sarà lo scheduler a scegliere quale slice eseguire. I programmi possono trovarsi in 3 stati: **running**, **runnable** e **blocked**