          ;contareil numero di volte che compare in memoria il valore 1 e salvare il risultato in memoria

list      dcd     1,24,12,8,10,1,4,21,3,1,5,1
dim       dcd     12
risultato fill    4
costante  equ     1


          mov     r1,#dim
          ldr     r1,[r1]
          mov     r2,#list

ciclo     
          ldr     r4,[r2]
          cmp     r4,#costante
          beq     trovato
back      
          add     r2,r2,#4
          subs    r1,r1,#1
          bgt     ciclo
          b       fine
trovato   
          add     r5,r5,#1
          b       back
fine      
          mov     r8,#risultato
          str     r5,[r8]