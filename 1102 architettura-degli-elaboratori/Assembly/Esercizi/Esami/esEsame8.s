           ;Data   la sequenza di numeri 1,2,3,4,5,6,7,8 :
           ;sommarei numeri di posizione pari
           ;sommarei numeri di posizione dispari
           ;salvarei due risultati in memoria

list       dcd     1,2,3,4,5,6,7,8
dim        dcd     8
res1       fill    4
res2       fill    4


           mov     r1,#dim
           ldr     r1,[r1]
           mov     r2,#list

           mov     r7,#0 ; registro contatore
           mov     r8,#0 ;registro somma parziale pari
           mov     r9,#0 ;registro somma parziale dispari

ciclo      
           and     r4,r7,#1; faccio un and tra l'indice dell'array e 1
           cmp     r4,#0; compair di r4 con 0
           beq     addPari; salto a addPari se i 2 numeri sono uguali
           b       addDispari; salto a addDispari se i 2 numeri sono diversi

addPari    
           ldr     r5,[r2]; carico il valore puntato da r2 in r5
           add     r8,r8,r5; faccio la somma parziale
           b       nextCiclo; vado al ciclo successivo

addDispari 
           ldr     r5,[r2]; carico il valore puntato da r2 in r5
           add     r9,r9,r5; faccio la somma parziale
           b       nextCiclo; vado al ciclo successivo

nextCiclo  
           add     r2,r2,#4; faccio puntare r2 all'elemento successivo
           add     r7,r7,#1; aumento l'indice della lista
           subs    r1,r1,#1; decremento il contatore del ciclo
           bgt     ciclo; salto a ciclo


fine       
           mov     r1,#res1
           mov     r2,#res2
           str     r8,[r1]; salvo il valore in memoria
           str     r9,[r2]; salvo il valore in memoria




