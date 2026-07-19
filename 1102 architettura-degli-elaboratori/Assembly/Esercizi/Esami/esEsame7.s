          ;Data   la lista [-10,4,23,50,0,40,10,7] sommare i numeri pari e salvare il risultato in memoria.

list      dcd     -10,4,23,50,0,40,10,7
dim       dcd     8
risultato dcd     4

          mov     r1,#dim
          ldr     r1,[r1]
          mov     r2,#list

          mov     r9,#0; clear su r9
ciclo     
          ldr     r3,[r2] ; prendo il valore puntato da r2 e lo carico in r3
          and     r4,r3,#1 ; faccio un and tra r3 e 1 se è pari in r4 avro 0
          cmp     r4,#0 ; comparo r4 con 0
          BEQ     somma ; vado a somma se sono uguali
nextCiclo 
          add     r2,r2,#4;faccio puntare r2 all'elemento successivo
          subs    r1,r1,#1;decremento r1
          BGT     ciclo; continuo il ciclo se r1 > 0
          b       fine; senno salto alla fine
somma     
          add     r9,r9,r3 ;sommo r3 alla somma parziale
          b       nextCiclo; vado al prossimo ciclo

fine      
          mov     r10,#risultato
          str     r9,[r10]; salvo il risultato in memoria