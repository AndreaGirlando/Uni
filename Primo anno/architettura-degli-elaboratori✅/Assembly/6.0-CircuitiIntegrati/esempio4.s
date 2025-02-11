          ;       Eseguire la divisione 231 / 13
          ;e      salvare il risultato e il resto

costanteA equ     231
costanteB equ     13
risultato fill    8

          mov     r1,#costanteA
          mov     r2,#costanteB
          mov     r3,#risultato
          mov     r4,#0
ciclo     cmp     r1,r2 ;231 e 13
          blt     esci
          subs    r1,r1,r2
          add     r4,r4,#1
          b       ciclo

esci      str     r4,[r3]
          str     r1,[r3,#4]


