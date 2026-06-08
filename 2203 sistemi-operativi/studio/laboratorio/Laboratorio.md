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
```

###### Gestione degli errori
Includendo l'header *errno.h* viene definita una variabile *errno* dove vengono inseriti i codici di errore
- *strerror(errno)* passando errno questa ci ritorna delle stringhe in linguaggio umano, utili per debbuggare. 
- *perror("Errore")* questa funzione scrive a schermo "Errore: " seguito dalla stringa dell'ultimo errore.
![[gestioneErrori.c]]
- *exit()* passando le costanti *EXIT_SUCCESS* e *EXIT_FAILURE* termina il processo
- *atexit(funzioneDaAvviare)*  questa funzione ci permette di settare degli handler quando accade un exit() - dopo aver richiamato un exit() tutti i atexit() settati vengono richiamati in ordine LIFO
![[gestioneExit.c]]
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
###### Lettura e scrittura sugli stream