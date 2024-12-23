          ;Sommarei numeri 2,3,4,1 e salvare in memoria
          ;il     risultato

numa      dcd     2,3,4,1
risultato fill    4

          mov     r1,#numa
          ldr     r2,[r1]
          add     r1,r1,#4
          ldr     r3,[r1]
          add     r1,r1,#4
          ldr     r4,[r1]
          add     r1,r1,#4
          ldr     r5,[r1]

          mov     r10,#0 ;clear
          add     r10,r2,r3
          add     r10,r10,r4
          add     r10,r10,r5

          mov     r1,#risultato
          str     r10,[r1]


