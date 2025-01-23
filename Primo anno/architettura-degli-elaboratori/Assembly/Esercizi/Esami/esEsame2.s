          ;Data   la lista [30,10,23,1,17,8,19,10] sommare tutti i numeri compresi tra 10 e 20.


list      dcd     30,10,23,1,17,8,19,10
dim       dcd     8
risultato fill    4
const1    equ     10
const2    equ     20

          mov     r1,#dim
          ldr     r1,[r1]
          mov     r2,#list

ciclo     
          ldr     r5,[r2]
          cmp     r5,#const1
          BLT     nextCiclo
          cmp     r5,#const2
          BGT     nextCiclo
          add     r8,r8,r5

nextCiclo 
          add     r2,r2,#4
          SUBS    r1,r1,#1
          BGT     ciclo

          mov     r9,#risultato
          str     r8,[r9]
