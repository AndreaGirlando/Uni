          ;Eseguire l'operazione 20 + 10 - 15
          ;e      salvare il risultato in memoria,
          ;usando la pila e conservando i vecchi valori
          ;contenuti nei registri.

Na        equ     20
Nb        equ     10
Nc        equ     15
risultato fill    4

          mov     r1,#30
          mov     r2,#23
          mov     r3,#12
          mov     r4,#8
          mov     r5,#10
          mov     r8,#1
          ;stmfd  sp!,{r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12}
          stmfd   sp!,{r1,r2,r0,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12}
          mov     r5,#0 ; clear
          mov     r1,#Na
          mov     r2,#Nb
          add     r5,r5,r1 ; 0 + 20
          add     r5,r5,r2 ; 20 + 10 => r5 = 30
          ;       add r5,r1,r2
          mov     r3,#Nc
          sub     r5,r5,r3 ; 30 - 15 => r5 = 15
          mov     r1,#risultato
          str     r5,[r1]
          ldmfd  sp!, {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12}
          


