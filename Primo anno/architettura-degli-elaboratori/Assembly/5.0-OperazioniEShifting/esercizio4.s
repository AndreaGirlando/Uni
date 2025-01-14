       ;       Data la lista [1,2,3,4,5,6,7,8,9,10]
       ;sommare tutti i numeri pari e minori di 8 e
       ;salvare il risultato in memoria.

lista  dcd     1,2,3,4,5,6,7,8,9,10
dim    equ     10
ris    fill    4

       mov     r1,#lista
       mov     r2,#dim
       mov     r3,#0
ciclo  subs    r2,r2,#1
       blt     esci
       ldr     r4,[r1],#4
       and     r5,r4,#1
       cmp     r5,#1
       beq     ciclo
       cmp     r4,#8
       bge     ciclo
       add     r3,r3,r4
       b       ciclo
esci   mov     r1,#ris
       str     r3,[r1]

