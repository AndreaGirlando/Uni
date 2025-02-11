          ;Data   la lista 1,24,12,8,10,1,4,21,3,1,5,1
          ;sommarei numeri maggiori (o uguali) di x con x = 10

lista     dcd     1,24,12,8,10,1,4,21,3,1,5,1
dim       dcd     12
risultato fill    4
costante  equ     10

          mov     r1,#dim
          ldr     r1,[r1]
          mov     r2,#lista
          mov     r5,#0 ;somma parziale
ciclo     ldr     r3,[r2],#4
          cmp     r3,#costante
          bge     sommo
tobe      subs    r1,r1,#1
          bgt     ciclo
          mov     r1,#risultato
          str     r5,[r1]
          end


sommo     add     r5,r5,r3
          b       tobe
