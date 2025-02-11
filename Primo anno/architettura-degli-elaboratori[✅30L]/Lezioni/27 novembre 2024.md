L'area di attivazione in assembly è quella porzione di memoria usata per gestire le chiamate a funzione o le subruoutine, ogni volta che viene chiamata una funzione viene creato un nuovo stack frame in cima allo stack esistente. Lo stack frame contiene:
- i parametri della funzione che devi chiamare
- Le variabili locali
- e il puntatore all'area di attivazione
La codifica numerica di un'istruzione in assembly è il processore attraverso cui le istruzioni di basso livello vengono tradotte in linguaggio binario, ovvero il linguaggio che la CPU può capire. Ogni istruzione corrisponde ad una precisa sequenza di bit. Questa codifica è determinata dall'architettura del processore (CISC o RISC). Nel caso di CPU a 32 bit abbiamo 3 forme di istruzioni:
- **Formato con operandi in registro**
	- Sono quelle istruzione che operando sui registri della CPU, un'esempio è l'istruzione ADD R1,R2 (potrebbe chiedere l'esempio all'esame)
- **Formato con operando immediato** 
	- Sono quelle istruzioni in cui un operando è fornito in modo immediato come la move R1,#5 dove l'operando #5 viene fornito in modo immediato
- **Formato per chiamata**
	- Sono quelle istruzioni in cui il valore immediato è fornito sin da subito (non ci sono esempi immediati)


**Register Transfer notation**: la notazione di trasferimento del registro in assembly è il metodo utilizzato per descrivere il movimento dei dati nei registri della CPU,indica in modo specifico come i valori vengono manipolati i dati nel passaggio da un registro ad un'altro. 
- $R_1 \leftarrow R_2$ è una freccia non un minore uguale
Inoltre viene usato per specificare il funzionamento delle delle operazioni aritmetico-logiche
- $C \leftarrow A + B$


Le **operazioni di scorrimento logico** (LShiftL\LShiftR) permettono di far scorrere i bit di un registro a destra o a sinistra di n posizioni.

Non tutte le architetture hanno le istruzioni per fare le moltiplicazioni e divisioni

CISC e RISC è importante (dettagliatamente a slide 92 pagina 61 di questo [[11_Insieme-di-istruzioni-macchina.pdf]])


Move permette il trasferimento di dati tra registri ed indirizzi di memoria
- Move destinazione, sorgente
- in notazione RTN: destinazione $\leftarrow$ sorgente si legge: "a destinazione assegno il valore contenuto dentro sorgente" 
**Questa istruzione può essere fatta solo nelle CPU CISC** 