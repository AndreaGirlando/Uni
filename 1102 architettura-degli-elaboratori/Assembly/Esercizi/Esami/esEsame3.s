          ;Data   la lista [1,2,3,4,5,6,7,8,9,10,11,12,13] contare tutti i numeri minori di 5, pari a 5 e maggiori di 5.


list      dcd     1,2,3,4,5,6,7,8,9,10,11,12,13
dim       dcd     13
risultato fill    12
const     EQU     5


          mov     r1,#dim
          ldr     r1,[r1] ; carico il valore della dimension in r1
          mov     r2,#list ; carico il puntatore al primo valore della lista in r2
ciclo     
          ldr     r3,[r2] ; prendo il valore puntatoto da r2 e lo carico in r3
          cmp     r3,#const; lo confronto con la constante
          BEQ     countEQ;Se più piccolo vado a count
          BGT     countGT;Se più grando vado a count
          BLT     countLT;Se uguale alla costante vado a count

countEQ   
          add     r8,r8,#1; aggiungo 1 al counter dei numeri trovati
          b       nextCiclo
countGT   
          add     r9,r9,#1; aggiungo 1 al counter dei numeri trovati
          b       nextCiclo
countLT   
          add     r10,r10,#1; aggiungo 1 al counter dei numeri trovati

nextCiclo 
          add     r2,r2,#4;faccio puntare r2 all'elemento successivo della lista
          SUBS    r1,r1,#1;decremento di 1 il contatore
          BGT     ciclo; vado a ciclo se il contatore è maggiore di 0


          mov     r11,#risultato
          str     r8,[r11]; salvo il risultato in memoria
          str     r9,[r11,#4]; salvo il risultato in memoria
          str     r10,[r11,#8]; salvo il risultato in memoria