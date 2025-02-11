       ;Data   la lista [1,2,3,4,5,6,7,8,9,10]
       ;dimezzare tutti gli elementi.

lista  dcd     1,2,3,4,5,6,7,8,9,10
dim    equ     10

       mov     r1,#lista
       mov     r2,#dim

ciclo  subs    r2,r2,#1
       blt     esci
       ldr     r3,[r1]
       lsr     r3,r3,#1
       str     r3,[r1]
       add     r1,r1,#4
       b       ciclo

esci   end
