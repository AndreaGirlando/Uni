           ;Effettua le due operazioni: 9 + 1 e 9 – 1 e salvare in memoria il risultato

n1         DCD     9
n2         DCD     1
risultato1 FILL    4
risultato2 FILL    4

           mov     r1,#n1
           mov     r2,#n2
           ldr     r1,[r1]
           ldr     r2,[r2]

           add     r5,r1,r2
           sub     r6,r1,r2

           mov     r7,#risultato1
           mov     r8,#risultato2

           str     r5,[r7]
           str     r6,[r8]
