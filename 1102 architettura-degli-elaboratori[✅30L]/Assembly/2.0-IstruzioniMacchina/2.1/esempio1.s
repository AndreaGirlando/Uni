          ;       esegui 9 + 1 e 9 -1 e salva in memoria

numa      equ     9
numb      equ     1
risultati fill    8

          mov     r1,#numa
          mov     r2,#numb
          add     r3,r1,r2
          sub     r4,r1,r2
          mov     r5,#risultati
          str     r3,[r5]
          str     r4,[r5,#4]



