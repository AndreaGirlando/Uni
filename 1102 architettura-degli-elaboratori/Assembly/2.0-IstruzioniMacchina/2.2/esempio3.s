          ;Data   la lista 1,24,12,8,10,1,4,21,3,1,5,1
          ;contareil numero di volte che compare in memoria
          ;il     valore 1 e salvare il risultato in memoria.

lista     dcd     1,24,12,8,10,1,4,21,3,1,5,1
dim       dcd     12
contatore fill    4
costante  equ     1
          mov     r1,#dim
          ldr     r1,[r1]
          mov     r2,#lista
          mov     r3,#contatore
          mov     r4,#0 ; contatore

ciclo     ldr     r5,[r2],#4
          cmp     r5,#costante ;cmp r5,#1
          beq     sommo
          ;add    r2,r2,#4
tobe      subs    r1,r1,#1
          bgt     ciclo
          str     r4,[r3]
          end


sommo     add     r4,r4,#1
          b       tobe

