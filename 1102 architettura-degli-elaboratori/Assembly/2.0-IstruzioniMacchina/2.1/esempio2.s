          ;       somma di 1,2,3,4 e li salvo in memoria

lista     dcd     1,2,3,4
dim       dcd     4
risultato fill    4

          mov     r1,#dim
          ldr     r1,[r1] ; Inizzializzo l'indice del ciclo
          mov     r2,#lista
          mov     r4,#0


ciclo     
          ldr     r3,[r2]; Carico il valore puntanto da r2 in r3
          subs    r1,r1,#1; indice ciclo - 1 e setto i bit di controllo
          add     r4,r4,r3; somma parziale
          add     r2,r2,#4; faccio puntare r2 all'elemento successivo
          bgt     ciclo; controllo se il risultato del subs è > 0


          mov     r7,#risultato
          str     r4,[r7]; salvo il risultato in memoria




