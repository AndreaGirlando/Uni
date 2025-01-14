          ;       Data la lista [1,2,3,4,5,6,7,8,9,10]
          ;contare tutti i numeri dispari e
          ;maggiori di 5 e salvare il risultato in memoria.

lista     dcd     1,2,3,4,5,6,7,8,9,10
dim       equ     10
risultato fill    4

          mov     r1,#lista
          mov     r2,#dim
          mov     r3,#0 ; contatore
ciclo     subs    r2,r2,#1
          blt     esci
          ldr     r4,[r1],#4
          ;verifico se è pari
          and     r5,r4,#1
          cmp     r5,#0
          beq     ciclo
          cmp     r4,#5
          ble     ciclo
          add     r3,r3,#1
          b       ciclo
esci      mov     r1,#risultato
          str     r3,[r1]



