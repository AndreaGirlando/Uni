num1   dcd     100
num2   dcd     231
       mov     r1,#10
       mov     r2,#30
       mov     r3,r2
       mov     r2,#3
       add     r4,r1,r2
       sub     r4,r1,r2

       mov     r1,#num1
       ldr     r2,[r1]

       mov     r3,#num2
       ldr     r4,[r3]

       mov     r6,#31
       str     r6,[r1]




