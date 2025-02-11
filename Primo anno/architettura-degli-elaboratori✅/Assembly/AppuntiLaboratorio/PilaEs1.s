          ;Eseguire l'operazione 20 + 10 - 15
          ;e      salvare il risultato in memoria
          ;usando la pila e conservando i vecchi valori
          ;contenuti nei registri

Na        equ     20
Nb        equ     10
Nc        equ     15
risultato 
          mov     r1,#30
          mov     r2,#23
          mov     r3,#12
          mov     r4,#8
          mov     r5,#10

          mov     r8,#1

          stmfd   sp!, {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12}
          ;guardando la memoria trovi tutti i valori salvati in pila
          ;stmfd  sp!, {r1,r0,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12}
          ;stmfd  sp!, {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12}
          ;Questi 2 comandi generano lo stesso risultato non è importante l'ordine in cui mettiamo i registri
          ;i      registri verrano sempre salva in ordine crescente
          mov     r5,#0;clear

          mov     r1,#Na
          mov     r2,#Nb
          mov     r3,#Nc
          add     r5,r5,r1
          add     r5,r5,r2
          sub     r5,r5,r3