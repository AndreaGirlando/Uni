Il laboratorio di sistemi consiste nella gestione delle seguenti aree:
- gestione *file system* e  dell'*I/O*
- gestione *processi*
- gestione *thread*
- gestione *sincronizzazione e comunicazione* tra processi e thread

###### Compilazione
```
Sorgente da un file: gcc -o nome-eseguibile sorgente.c
Sorgente da più file: gcc -o nome-eseguibile file1.o file2.o
Aggiunta di librerie esterne: gcc -l pthread -o nome-eseguibile file1.o
```

###### Costanti imporatnti
```
#include <unistd.h>
/* Standard file descriptors. */
#define STDIN_FILENO 0 /* Standard input. *
#define STDOUT_FILENO 1 /* Standard output. */
#define STDERR_FILENO 2 /* Standard error output. */


BUFSIZ \\definita in stdio.h e viene usata per i buffer interni alla libreria (come la scrittura negli stream)
```

###### Gestione degli errori
Includendo l'header *errno.h* viene definita una variabile *errno* dove vengono inseriti i codici di errore
- *strerror(errno)* passando errno questa ci ritorna delle stringhe in linguaggio umano, utili per debbuggare. 
- *perror("Errore")* questa funzione scrive a schermo "Errore: " seguito dalla stringa dell'ultimo errore.
![[gestioneErrori.c]]
- *exit()* passando le costanti *EXIT_SUCCESS* e *EXIT_FAILURE* termina il processo
- *atexit(funzioneDaAvviare)*  questa funzione ci permette di settare degli handler quando accade un exit() - dopo aver richiamato un exit() tutti i atexit() settati vengono richiamati in ordine LIFO
![[gestioneExit.c]]

### Gestione file
###### Apri, chiudi e crea file
```
#include "fcntl.h"
```
- *open("path", int flag)*, apre il file specificato nel path, -1 nel caso di errore un int identificativo del file in caso di successo, di seguito i vari flag
  ![[Pasted image 20260608112024.png|700]]
- *creat("path", mode_t mode)* crea il file nel path specifico con i permessi definiti in mode (man creat per vedere tutti i permessi disponibili)
- *close(id)* chiude il file specificato da quel id 
![[crea_chiudi_file.c]]

###### Permesssi sugli oggetti

- **Permessi sugli Oggetti del File-System UNIX**
    - Ogni oggetto ha tre tipi di permessi: lettura (R), scrittura (W) ed esecuzione (X).
    - Il tipo `mode_t` è un intero che codifica una maschera con i permessi divisi per utente proprietario (USR), gruppo proprietario (GRP) e tutti gli altri utenti (OTH).
    - La maschera si ricava da costanti definite in `sys/stat.h` come `S_IRUSR`, `S_IWGRP`, `S_IXOTH`, ecc..
    - È prassi comune (anche se non raccomandata) usare direttamente la rappresentazione numerica ottale, ad esempio `0640`.
    - Per le directory, il permesso X rappresenta specificamente il diritto di attraversamento.

- **Maschera di Creazione per i Permessi (umask)**
    - Quando si crea un file o una cartella, la maschera indicata viene combinata con una maschera di creazione (umask) che inibisce determinati permessi per sicurezza.
    - Il calcolo avviene tramite l'operazione logica: `maschera-effettiva = maschera-specificata & ( ~ maschera-creazione)`.
    - Ogni processo possiede la propria maschera di creazione, che viene regolarmente ereditata dai processi figli.
    - In ambiente C si controlla tramite la funzione `mode_t umask(mode_t cmask);` inclusa nell'header `<sys/stat.h>`.
    - Anche la shell dispone di una propria maschera di creazione, modificabile direttamente con il comando `umask`.
Nell'esempio del file C troveremo una maschera di qeusto tipo: 
```
#define RWRWRW_MASK (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
```
Che definisce i permessi per le tre categorie viste prima
- **Per l'utente proprietario (USR):**    
    - **`S_IRUSR`**: Abilita il permesso di lettura.
    - **`S_IWUSR`**: Abilita il permesso di scrittura.        
- **Per il gruppo proprietario (GRP):**
    - **`S_IRGRP`**: Abilita il permesso di lettura.
    - **`S_IWGRP`**: Abilita il permesso di scrittura.
- **Per tutti gli altri utenti (OTH):**
    - **`S_IROTH`**: Abilita il permesso di lettura.
    - **`S_IWOTH`**: Abilita il permesso di scrittura.

- *umask(maschera)* impedisce a creat di inserire nella maschera del file che crea i permessi specifcati in *maschera*
![[Pasted image 20260608113840.png|800]]
il primo file è creato con la maschera completa, invece il seconod applicando umask con i seguenti parametri:
```
umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH); // inibisce la possiblità di dare permessi di lettura/scrittura
```

![[creazione_maschera_file.c]]

###### Posizionamento nel file
```
<unistd.h>
```
Quando apriamo un file questo simula l'accesso sequenziale, in apertura ci troviamo all'indice 0.
- *lseek(idFile, offset, int whence)* ritorna -1 in caso di errore o la nuova posizione rispetto all'inizio del file
questa funzione fa uno spostamento di *offset* byte rispetto a *whence*, quest'ultima è una costante:
- *SEEK_SET*: rispetto all'inizio del file
- *SEEK_CUR*: rispetto alla posizione attuale
- *SEEK_END*: rispetto alla fine del file
```
pos = lseek(fd, 0, SEEK_CUR); //Otteniamo la posizione attuale
```

![[seek.c]]

###### Lettura e scrittura
```
<unistd.h>
```
- *ssize_t read(IdFile, void \*buf, size_t nbytes)* legge dal file identificato IdFile e inserisce dentro *buf*, ritorna:
	- -1 in caso di errore
	- 0 se siamo alla fine del file
	- $\ge0$ indicando il numero di byte letti 
- *ssize_t write(IdFile, const void \*buf, size_t nbytes);* legge *nbytes* dal *buf* e li scrive nel file identificato, ritorna:
	- -1 in caso di errore
	- $\ge 0$ indicando il numero di byte scritti

![[scrivi_file.c]]

Quando scriviamo e lasciamo un buco tra una scritta e l'altra il file system crea dei byte nulli che non verranno allocati veramente nel disco
![[Pasted image 20260608121454.png]]
il primo comando ci indica la dimensione apparente del nostro file (con i byte nulli), il secondo comando invece ci mostra la dimensione reale nel nostro disco (in quanto i byte nulli non vengono allocati)
![[Pasted image 20260608121917.png|700]]

###### Condivisione di file e strutture dati di supporto
Ragionando in uno scenario multi-thread, più processi potrebberò aprire lo stesso file e avere problemi di letture e scritture concorrenti, quindi nascono le funzioni *pread* e *pwrite* che sono omonime a read e write ma sono atomiche.

Può essere utile creare dei duplicati degli identificatori dei file per fare qeusta cosa usiamo:
- *int dup(int fd);* prende il *FileId* in input e ne ritorna un nuovo ma che punta allo stesso file
```
// Questi write scrivono nello stesso file
write(FileId, buffer1, sizeof(buffer1) - 1);
write(newFileID, buffer1, sizeof(buffer1) - 1);
```
- *int dup2(int fd, int fd2);* sovrascrive la voce `fd2` rimpiazzandola con una copia esatta di `fd`. Se `fd2` era già aperta, il sistema la chiude automaticamente prima di sostituirla.
```
int standardOutput = dup(STDOUT_FILENO); // mi salvo il backup di stdout
dup2(FileId, STDOUT_FILENO); // l'id di stdout diventa quello del file
printf("\n Sto scrivendo nel file usando printf \n"); // scrivo sul file
fflush(stdout); // forzo la scrittura reale nel file 
dup2(standardOutput, STDOUT_FILENO); // resetto stdout con il riferimento salvato
printf("\n Sto scrivendo nella console \n"); //scrivo nella consoel
```

Il Sistema Operativo usa la RAM libera come cache del disco, anche in scrittura questo ritarda le scritture per ragioni di efficienza (in genere per massimo 30 s) questo può creare problemi indesiderati è sempre possibile forzare il sistem operativo tramite *0_SYNC* in fase di apertura di una file o anche attraverso le seguenti chiamate di sistema:
- *int fsync(int fd);* 
- *void sync(void);*

![[Pasted image 20260608194514.png|500]]
![[2203 sistemi-operativi/file-condivisi/git/eserciziLaboratorio/redirect.c|redirect]]
### Stream
###### Apri e chiudi stream
C fornisce una libreria per l'I\O bufferizzato basato su stream, questo per ridurre il numero di chiamate di sistema *read/write* è sempre possibile forzare scritture pendenti nel buffer con fflush. Per creare uno stream aprendo un file specificato usiamo: 
- *FILE \*fopen(const char \*pathname, const char \*type);* 
- *FILE \*fdopen(int fd, const char \*type);* 
- *int fclose(FILE \*fp);*
![[apri_chiudi_stream.c]]

###### Leggi e scrivi sugli stream
Per leggere dagli stream abbiamo diversi comandi
- *int fgetc(FILE \*fp);*  legge un carattere, ritorna la costante *EOF* in caso di errore o fine file
- *int fputc(int c, FILE \*fp);*  scrive un carattere sullo stream
in combinazione con fgetc possiamo usare i due metodi sotto per disambiguare il caso di errore dalla fine del file
- *int ferror(FILE \*fp);* 
- *int feof(FILE \*fp);*

I buffer degli stream possono essere di tre tipi:
- *Unbuffered*: i dati vengono scritti subito sul canale, senza passare da un buffer. È il caso tipico di `stderr`.    
- *Line-buffered*: i dati vengono accumulati nel buffer e scritti quando viene incontrato `\n`. È il caso tipico di `stdout` quando stampa sul terminale.
- *Fully-buffered*: i dati vengono accumulati nel buffer e scritti solo quando il buffer si riempie, oppure quando chiamiamo `fflush()` o `fclose()`. È il caso tipico dei file.

Il buffering riduce il numero di chiamate al sistema operativo, rendendo le operazioni di I/O più efficienti. Possiamo disabilitare il buffering con:
```c
setbuf(fp, NULL);
```

![[2203 sistemi-operativi/file-condivisi/git/eserciziLaboratorio/streams-and-buffering.c|streams-and-buffering]]

![[2203 sistemi-operativi/file-condivisi/git/eserciziLaboratorio/copy.c|copy]]

- *char \*fgets(char \*buf, int n, FILE \*fp);* : legge una riga dallo stream *fp* e lo scrive come stringa sul *buf*, ritorna NULL in caso di fine-file o di errore
- *int fputs(const char \*str, FILE \*fp);* scrive la stringa sullo stream *fp*
I comandi sotto fanno lo stesso ma si basano su uno specifico pattern (*format*)
- *int fprintf(FILE \*fp, const char \*format, ...);* 
- *int fscanf(FILE \*fp, const char \*format, ...);*
![[2203 sistemi-operativi/studio/laboratorio/C/gestioneStream/my-cat.c|my-cat]]

![[Pasted image 20260610155839.png]]
leggono e scrivono nobj record dentro il file ciasuno di *size byte*, ritornano entrambi il numero di record effettivamente trasferiti

Queste funzioni sono simili tra di loro solo che in alcune situazioni una è migliore dell'altra
![[Pasted image 20260610160035.png|700]]
###### Posizionamento sugli stream
![[Pasted image 20260610160116.png]]

###### Raccolta di informazioni sui file 
- `stat()`, `fstat()` e `lstat()` servono a ottenere informazioni su un file o un altro oggetto del file system e le salvano in una struttura `struct stat`.
    - `stat(path, &buf)`: usa il pathname.
    - `fstat(fd, &buf)`: usa un file descriptor già aperto.
    - `lstat(path, &buf)`: come `stat()`, ma **non segue i link simbolici** (restituisce info sul link stesso).
- Campi importanti di `struct stat`:
    - `st_mode`: contiene **tipo del file** e **permessi**.
    - `st_uid`: UID del proprietario.
    - `st_gid`: GID del gruppo proprietario.
    - `st_atime`: data/ora dell'ultimo accesso.
    - `st_mtime`: data/ora dell'ultima modifica del contenuto.
    - `st_ctime`: data/ora dell'ultima modifica dei metadati (permessi, owner, ecc.) o del contenuto.
    - `st_ino`: numero dell'i-node.
    - `st_nlink`: numero di hard link associati all'i-node.
    - `st_size`: dimensione del file in byte.
- Analisi di `st_mode`:
  Permessi: si isolano con st_mode & 0777 (ottengo i classici permessi rwx per owner, group e others). Il tipo di file si scopre in questo modo:
```c
S_ISREG(mode)   // file regolare
S_ISDIR(mode)   // directory
S_ISBLK(mode)   // dispositivo a blocchi
S_ISCHR(mode)   // dispositivo a caratteri
S_ISLNK(mode)   // link simbolico
```
- Per ottenere il nome dell'utente e del gruppo a partire da UID e GID:
    - `getpwuid(st_uid)` → informazioni sull'utente.
    - `getgrgid(st_gid)` → informazioni sul gruppo.
- Da ricordare:
    - `st_ino` identifica l'i-node.
    - `st_nlink > 1` indica che esistono più hard link allo stesso i-node.
    - `lstat()` è utile quando si vogliono distinguere i link simbolici dal file a cui puntano.

### Gestione delle directory
- `opendir(path)` apre una directory e restituisce uno **stream di directory** (`DIR *`).
    - Ritorna `NULL` in caso di errore.
    - Va chiuso con `closedir()`.
- `readdir(dp)` legge la voce successiva della directory.
    - Restituisce un puntatore a `struct dirent`.
    - Ritorna `NULL` a fine directory o in caso di errore.
    - Campi importanti:
        - `d_ino` → numero di i-node.
        - `d_name` → nome del file/directory.
- Funzioni per muoversi nello stream della directory:
    - `rewinddir(dp)` → torna all'inizio.
    - `telldir(dp)` → ottiene la posizione corrente.
    - `seekdir(dp, pos)` → si sposta a una posizione salvata.
    - `closedir(dp)` → chiude lo stream.
![[2203 sistemi-operativi/studio/laboratorio/C/gestioneDirectory/list-dir.c|list-dir]]

---

- `link(existingpath, newpath)`
    - Crea un **hard link** (link fisico) a un file esistente.
    - Entrambi i nomi puntano allo stesso i-node.
    - Eliminare uno dei due nomi non elimina il contenuto se esistono altri hard link.
- `unlink(pathname)`
    - Rimuove un nome associato a un file (decrementa `st_nlink`).
    - Il file viene realmente eliminato solo quando:
        - non esistono più hard link;
        - nessun processo lo tiene aperto.
- `remove(pathname)`
    - Funzione più generica:
        - per i file usa `unlink()`;
        - per directory vuote usa `rmdir()`.
- `rename(oldname, newname)`
    - Rinomina o sposta file e directory.
    - Operazione generalmente atomica all'interno dello stesso filesystem.
- `symlink(actualpath, sympath)`
    - Crea un **link simbolico**.
    - Contiene il percorso del file/directory di destinazione.
    - Può puntare anche a oggetti inesistenti.
- `readlink(pathname, buf, size)`
    - Legge il contenuto di un link simbolico.
    - Copia nel buffer il percorso memorizzato nel link.
    - Non aggiunge automaticamente `'\0'`.
- Differenza fondamentale:
    - **Hard link (`link`)** → stesso i-node, stesso file fisico.
    - **Symbolic link (`symlink`)** → file speciale che contiene un percorso.
- Da ricordare:
    - `unlink()` rimuove hard link.
    - `lstat()` permette di ottenere informazioni sul link simbolico senza seguirlo.
    - Gli hard link aumentano il campo `st_nlink` dell'i-node.

![[2203 sistemi-operativi/studio/laboratorio/C/gestioneDirectory/move.c|move]]

###### Cose generiche sui file
- `truncate(path, length)` modifica la dimensione di un file tramite pathname.
    - Se `length` è minore della dimensione attuale, il file viene tagliato.
    - Se `length` è maggiore, il file viene esteso.
- `ftruncate(fd, length)` fa la stessa cosa di `truncate()`, ma usa un file descriptor già aperto
- L’estensione di un file può creare una **hole**, cioè una zona vuota/non allocata fisicamente fino all’effettivo uso.
- `chmod(path, mode)` cambia la maschera dei permessi di un oggetto del file system.
- `chown(path, owner, group)` cambia proprietario e gruppo di un file tramite UID e GID numerici.
- Su Linux e altri sistemi UNIX, normalmente solo l’amministratore può usare `chown()` per cambiare proprietario.

### Mappatura dei File
- *void \*mmap(void \*addr, size_t len, int prot, int flag, int fd, off_t off);*
Questa funzione mappa una porzione del file aperto (definita da *off* e *len*) sull'indirizzo virtuale *addr* abilitando i permessi *prot*, elencati di seguito
```C
PROT_READ   // posso leggere dalla memoria mappata
PROT_WRITE  // posso scrivere nella memoria mappata
PROT_EXEC   // posso eseguire codice da quella memoria
PROT_NONE   // nessun accesso
```
se lasciamo *addr* a *NULL* il sistema operativo trova un indrizzo idoneo
il campo *flag* serve a specificare **che tipo di mappatura vuoi creare**. I principali sono:
- `MAP_SHARED`: le modifiche fatte in memoria vengono riflesse sul file e sono visibili anche ad altri processi che mappano lo stesso file.
- `MAP_PRIVATE`: le modifiche restano private al processo; non vengono salvate nel file. Di solito usa il meccanismo copy-on-write.

questa funzione ritorna *MAP_FAILED* in caso di errore l'indirizzo di mappatura altrimenti.

- *int msync(void \*addr, size_t len, int flag);* : forza il sistema operativo a scrivere su disco eventuali modifiche in sospeso, i flag che possiamo usare specificano solo il tipo di richiesta che possiamo fare:
	- *MS_ASYNC*: richiesta asincrona
	- *MS_SYNC*: richiesta sincrona (bloccante)
- *int munmap(void \*addr, size_t len);* annulla la mappatura del file salvando le evntuali modifiche in caso di mappatura condivisa (effetti comunque applicati alla terminazione del processo)
### Gestione dei processi

###### FORK
- *pid_t getpid(void);* ritorna il pid del processo
- *pid_t getppid(void);* ritorna il pid del processo padre
- *pid_t fork(void);* duplica il processo chiamate, ritorna:
	- -1 nel caso di errore
	- il PID del processo figlio
	- oppure 0 nel figlio

incotriamo *snprintf()* la usiamo principalmente per scrivere una stringa formattata dentro un buffer in modo sicuro, evitando overflow.

Il processo padre condivide con i propri figli *la tabella globale dei file* e quindi i *flag di apertura* e  i *file di offset*, questo può essere utile quando più figli devono accedere allo stesso file.
- *pid_t wait(int statloc);*  il processo che lo avvia si mette in attesa del primo figlio che finisce
- *pid_t waitpid(pid_t pid, int statloc, int options);* il processo che lo avvia si mette in attesa che il figli con il pid specificato finisca,  se specifichiamo un puntatore per statloc trovermo qui il codice di terminazione del figlio, options non lo usiamo (sempre 0)
Entrambe le funzioni ritornatno -1 in caso di errore, il PID del figlio che ha terminato altrimenti

###### Esecuzione programmi esterni
- Le funzioni `exec*()` sostituiscono il programma corrente con un altro programma.
- Il processo resta lo stesso, quindi mantiene lo stesso PID, ma cambia il codice eseguito.
- Se `exec*()` va a buon fine, non ritorna mai al programma chiamante.
- Se fallisce, ritorna `-1`.
- `execl()` passa gli argomenti uno alla volta.
- `execv()` passa gli argomenti tramite un vettore di stringhe.
- Le varianti con `p`, cioè `execlp()` e `execvp()`, cercano l’eseguibile usando la variabile d’ambiente `PATH`.
- Nei sistemi UNIX un file testuale può essere eseguito come script.
- Per essere eseguibile deve avere il permesso `x`.
- La prima riga deve indicare l’interprete da usare tramite `#!`.
- L’esecuzione tramite interprete è gestita direttamente dal kernel.
- `system()` esegue un comando in un sotto-processo.
- Internamente usa una shell e meccanismi basati su `fork`, `exec` e `wait`.
- A differenza di `exec*()`, `system()` ritorna al programma chiamante dopo l’esecuzione del comando.

###### Invio di segnali ai processi
- *int kill(pid_t pid, int signo);* invia al processo specificato il segnale singno (non solo il kill)
- *int raise(int signo);* invia il segnale al processo chiamante stesso

ci sono diverse costanti signo definite in signal.h
![[Pasted image 20260610173343.png|700]]

### Gestione dei thread

###### Creazione
Pthread fornisce un interfaccia standard per interagire con le varie implementazioni disponibili sui vari SO. L'identificativo di un thread è un intero non negativo definito dal tipo *pthread_t*

oltre all'inclusione dell'header pthread.h, è necessario effettuare il linking all'apposita libreria:
```
gcc -l pthread -o eseguibile sorgente.c
```

![[Pasted image 20260610174445.png|700]]
questa funzioene crea un nuovo thread che eseguirà la funzione *thread_func* con argomento *thread_arg*.
- il prototipo di thread_func deve essere di questo tipo: *void funzione(void *argomento) { / corpo funz. / }*
- l'identificativo del thread è conservato dentro *tidp*
- *attr* per adesso NULL (vedremo successivamente)
ritorna il threadId
###### Coordinamento
![[Pasted image 20260610174950.png]]
- *pthread_exit()* termina il thread chiamante, il valore di ritorno del thread verra salvato in *rval_ptr* se un puntatote è fornito
- *pthread_join()* attende la terminzaione di uno specifico thread, diventa importante conservare il *thread id*, ritorna:
	- 0 in caso di successo
	- il codice d'errore >0 altrimenti

###### Condivisione dei dati
Tutti i thread di uno stesso processo condividono, in linea di principio, quasi tutto lo spazio di memoria del processo. Bisogna però rispettare lo **scope** delle variabili imposto dal linguaggio C.

Per condividere dati tra thread è meglio evitare le variabili globali: funzionano, ma possono diventare difficili da controllare e rendono il codice meno pulito.

La soluzione preferibile è passare i dati al thread tramite l’unico argomento disponibile della funzione, cioè il parametro `void *`, solitamente passando un indirizzo. Se i dati da condividere sono più di uno, conviene racchiuderli in una `struct` e passare il puntatore a quella struttura.

Poiché più thread possono accedere agli stessi dati contemporaneamente, possono verificarsi problemi di concorrenza, come le **race condition**.

Nell'esempio thread-conc-problem.c ci sono 6 thread che devono incrementare una variabile condivisa, in tutte le prove che ho fatto non riescono mai ad arrivare al risultato finale giusto, fanno accessi concorrenti e si perdono un sacco di incrementi. Per coordinare i thread usiamo i *Mutex lock*

###### Mutex lock
![[Pasted image 20260610181521.png|700]]
La struttura *pthread_mutex_t* va usata da tutti i thread come riferimento al lock.
- *pthread_mutex_init* inizializza dinamicamente *mutex* con eventuali attributi *attr* (non approfondiremo e pertanto passeremo sempre NULL)
- *pthread_mutex_destroy*: distrugge il mutex
- *pthread_mutex_lock* e *pthread_mutex_unlock*: acquisiscono e rilascino il lock
- *pthread_mutex_trylock*: prova il lock e ritorna subito con *EBUSY* se non riesce
in thread-conc-problem-fixed-with-mutex.c il problema citato prima si è sistemato, il valore finale è quello che ci aspettiamo.

###### Semafori numerici
![[Pasted image 20260610183406.png|700]]
La struttura dati di riferimento è *sem_t*
- *sem_init* inizializza il semaforo sem con il valore iniziale *value*, *pshared* dichiara il tipo di utilizzatori per adattare il meccanismo di sincronizzazione: 
	- PTHREAD_PROCESS_PRIVATE (0): tra thread dello stresso processo 
	- PTHREAD_PROCESS_SHARED (1): tra processi distinti tramite memoria condivisa
- *sem_wait*: decrementa il semaforo dove *sem_trywait* lo fa senza bloccarsi
- *sem_post* incrementa il semaforo

I semafori ci permettono di controllare quante entità possono accedere contemporaneamente a una risorsa.

###### Lock per lettori/scrittori
![[Pasted image 20260610184753.png|700]]
La struttura di riferimento è *pthread_rwlock_t*
- *pthread_rwlock_{init,destroy}* sono simili agli analoghi visti prima per i mutex
- *pthread_rwlock_\[try]{rd|wr}lock* acquisiscono il lock condiviso o esclusivo
- *pthread_rwlock_unlock* rilascia il lock precedentemente acquisito 

###### Monitor
![[Pasted image 20260611172515.png|700]]
La struttura di riferimento è *pthread_cond_t*
- *pthread_cond_init()* passiamo la condizione da far rispettare tramite il monitor - *attr* non lo usiamo
- *pthread_cond_destroy()*: distrugge il monitor
- *pthread_cond_wait()*: se la condizione associata è false allora dobbiamo richiamare *pthread_cond_wait()*
- *pthread_cond_{signal, broadcast}()*: risveglia uno (non si sa quale,  non possiamo fare affidamento che questa cosa accada in modo sequenziale) o più thread bloccati
Dopo che un thread viene risvegliato deve necessariamente ricontrollare la condizione tramite la *...wait*. 