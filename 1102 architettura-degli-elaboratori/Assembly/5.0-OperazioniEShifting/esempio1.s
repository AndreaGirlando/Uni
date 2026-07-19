lista  dcd     10,4,1,34,5

       mov     r1,#10
       mov     r2,#41
       and     r3,r1,r2
       orr     r4,r1,r2
       eor     r5,r1,r2
       lsl     r6,r1,#3
       lsr     r7,r1,#3
       asr     r8,r1,#3
       mov     r1,#-10
       asr     r9,r1,#3
       ror     r10,r1,#3
       mov     r1,#lista
       ldrb    r2,[r1,#1]
       mov     r2,#32
       strb    r2,[r1,#2]