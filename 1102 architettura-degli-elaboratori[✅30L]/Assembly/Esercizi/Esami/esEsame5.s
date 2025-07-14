          ;Eseguire la divisione 231 / 13 e salvare il risultato e il resto

num1      dcd     231
num2      dcd     13
quoziente fill    4
resto     fill    4

          mov     r1,#num1
          mov     r2,#num2
          ldr     r1,[r1];carico il valore 231 nel registro
          ldr     r2,[r2];carico il valore 13 nel registro

          mov     r4,#0; clear su r4
ciclo     
          cmp     r1,r2; compair tra r1 ed r2
          BLT     fine; se r1 è più piccolo di r2 salto a fine
          subs    r1,r1,r2;sottraggo ad r1 il valore di r2
          add     r4,r4,#1;r4 conta quante volte sottraggo r2 da r1
          BGT     ciclo; continuo il ciclo

fine      
          mov     r8, #quoziente;
          mov     r9, #resto
          str     r4,[r8];salvo il quoziente
          str     r1,[r9];salvo il resto
          END