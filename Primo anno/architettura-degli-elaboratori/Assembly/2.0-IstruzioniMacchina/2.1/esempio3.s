          ;Data   la sequenza di numeri 1,2,3,4,5,6,7,8 :
          ;sommarea tutti i numeri la costante 10;
          ;sommarei numeri ottenuti;
          ;salvareil valore della somma in memoria.

lista     dcd     1,2,3,4,5,6,7,8
dim       dcd     8
risultato fill    4
costante  equ     10
          mov     r1,#dim
          ldr     r1,[r1]
          mov     r2,#lista
          mov     r3,#0
ciclo     ldr     r4,[r2]
          add     r4,r4,#costante
          add     r3,r3,r4
          add     r2,r2,#4
          subs    r1,r1,#1
          bgt     ciclo
          mov     r1,#risultato
          str     r3,[r1]


