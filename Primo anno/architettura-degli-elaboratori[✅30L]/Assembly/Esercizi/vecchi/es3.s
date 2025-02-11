          ;Data   la sequenza di numeri 1,2,3,4,5,6,7,8 :
          ;       I. sommare a tutti i numeri la costante 10
          ;       II. sommare i numeri ottenuti
          ;       III. salvare il valore della somma in memoria.


list      dcd     1,2,3,4,5,6,7,8
dim       dcd     8
risultato fill    4
costante  equ     10


          mov     r1,#dim
          ldr     r1,[r1]
          mov     r2,#list
ciclo     
          ldr     r5,[r2]
          add     r2,r2,#4
          add     r5,r5,#costante
          add     r3,r3,r5
          subs    r1,r1,#1
          bgt     ciclo

          mov     r8,#risultato
          str     r3,[r8]