          ;Data   la lista [-10,4,23,50,0,40,10,7] trovare il minimo e salvare il risultato in memoria.

list      dcd     10,4,23,50,1,40,10,7
dim       dcd     8
minimo    fill    4

          mov     r1,#dim ; Carico il puntatore alla dimensione in r1
          ldr     r1,[r1] ; Carico la dimensione in r1
          mov     r2,#list; Carico l'indirizzo del primo elemento della list in r2

          ldr     r8,[r2],#4; Inizzializzo r8 con il primo valore della lista e incremento di 4 il puntatore

ciclo     
          ldr     r3,[r2],#4; Prendo il valore successivo della lista lo carico in r2 ed icremento di 4 il puntatore
          cmp     r8,r3 ; Li comparo
          BGT     trovato; Se r8 è più grande di r3 vado in "trovato" senno vado in nextCiclo

nextCiclo 
          SUBS    r1,r1,#1 ;Aggiorno il puntatore togliendo 1
          BGT     ciclo ;Salto a ciclo se r1>0
          b       fine ; Senno salto a fine

trovato   
          mov     r8,r3; prendo il valore di r3 e lo metto in r8 in quando è più piccolo
          b       nextCiclo ; Vado al prossimo ciclo
fine      
          mov     r9,#minimo ; Salvo il puntatore al risultato in r9
          str     r8,[r9] ; Salvo il risultato in memoria