          ;Data   la lista [30,10,23,1,17,8,19,10]
          ;sommaretutti i numeri compresi tra 10 e 20.

lista     dcd     30,10,23,1,17,8,19,10
dim       dcd     8
risultato fill    4
costanteA equ     10
costanteB equ     20
          mov     r1,#lista
          mov     r2,#dim
          ldr     r2,[r2]
          mov     r3,#0
ciclo     subs    r2,r2,#1
          blt     esci
          ldr     r5,[r1],#4
          cmp     r5,#costanteA
          blt     ciclo
          cmp     r5,#costanteB
          bgt     ciclo
          add     r3,r3,r5
          b       ciclo
esci      mov     r6,#risultato
          str     r3,[r6]


