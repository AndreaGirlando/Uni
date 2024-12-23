          ;Sommarei numeri 2,3,4,1 e salvare in memoria
          ;il     risultato

numa      dcd     2
numb      dcd     3
numc      dcd     4
numd      dcd     1
risultato fill    4

          ;       leggiamo i dati dalla memoria
          mov     r1,#numa
          ldr     r1,[r1]
          mov     r2,#numb
          ldr     r2,[r2]
          mov     r3,#numc
          ldr     r3,[r3]
          mov     r4,#numd
          ldr     r4,[r4]

          ;sommiamo i dati
          mov     r5,#0
          add     r5,r5,r1
          add     r5,r5,r2
          add     r5,r5,r3
          add     r5,r5,r4

          ;risultato fill 4
          ;salviamo il risultato in memoria
          mov     r9,#risultato
          str     r5,[r9]
