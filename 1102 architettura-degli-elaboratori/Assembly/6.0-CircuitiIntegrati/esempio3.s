          ;Moltiplicare i numeri 9,3

costanteA equ     9
costanteB equ     3
risultato fill    4

          mov     r3,#0 ; risultato della molti
          mov     r1,#costanteA
          mov     r2,#costanteB

ciclo     subs    r2,r2,#1
          blt     esci
          add     r3,r3,r1
          b       ciclo

esci      mov     r1,#risultato
          str     r3,[r1]


