          ;Moltiplicare i numeri 9,3

num1      dcd     9
num2      dcd     3
risultato fill    4

          mov     r1,#num1
          mov     r2,#num2
          ldr     r1,[r1];carico il valore di num1 nel registro
          ldr     r2,[r2];carico il valore di num1 nel registro

          mov     r5,#0; clear su r5
ciclo     

          add     r5,r5,r1;sommo su r1 su r5, lo faccio r2 volte

          subs    r2,r2,#1; riduco di uno il valore del contatore
          bgt     ciclo; salto se il valore di r2>0

          mov     r9,#risultato
          str     r5,[r9]; se non salto ho finito e quindi salvo il valore in memoria