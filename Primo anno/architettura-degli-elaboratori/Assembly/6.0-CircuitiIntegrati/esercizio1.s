          ;Data   la lista [10,20,12,12,5,1,5,1]
          ;contaretutti i numeri diversi da 1 e 10.


lista     dcd     10,20,12,12,5,1,5,1
dim       equ     8
risultato fill    4
costante1 equ     1
costante2 equ     10
          mov     r1,#lista
          mov     r2,#dim
          mov     r3,#risultato
          mov     r5,#0
ciclo     subs    r2,r2,#1
          blt     esci
          ldr     r4,[r1],#4
          cmp     r4,#costante1
          beq     ciclo
          cmp     r4,#costante2
          beq     ciclo
          add     r5,r5,#1
          b       ciclo

esci      str     r5,[r3]

