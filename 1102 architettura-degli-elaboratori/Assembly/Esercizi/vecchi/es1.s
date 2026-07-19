          ;Sommarei numeri 2,3,4,1 e salvare in memoria il risultato

numeri    dcd     2,3,4,1
dim       dcd     4
risultato fill    4



          mov     r1,#dim
          ldr     r1,[r1]
          mov     r2,#numeri
ciclo     
          ldr     r8,[r2]
          add     r3,r3,r8
          add     r2,r2,#4
          subs    r1,r1,#1
          bgt     ciclo

          mov     r5,#risultato
          str     r3,[r5]





