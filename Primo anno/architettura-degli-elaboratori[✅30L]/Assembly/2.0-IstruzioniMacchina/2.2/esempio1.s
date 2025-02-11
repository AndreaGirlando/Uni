          ;Supponiamo che tre studenti abbiamo eseguito 3 prove
          ;ognuna con voto da 18 a 30.
          ;Sommarei voti ottenuti dagli studenti per ogni
          ;prova  e salvare il risultato in memoria.
          ;Lista: 1,20,20,20, 2,18,30,27, 3,22,26,28

lista     dcd     1,20,20,20, 2,18,30,27, 3,22,26,28
risultati fill    12
numero    dcd     3

          mov     r1,#lista
          mov     r2,#numero
          ldr     r2,[r2]
          mov     r10,#risultati
          mov     r6,#0 ;voto 1
          mov     r7,#0 ;voto 2
          mov     r8,#0 ;voto 3

ciclo     add     r1,r1,#4
          ldr     r3,[r1]
          add     r6,r6,r3
          add     r1,r1,#4
          ldr     r3,[r1]
          add     r7,r7,r3
          add     r1,r1,#4
          ldr     r3,[r1]
          add     r8,r8,r3
          add     r1,r1,#4
          subs    r2,r2,#1
          bgt     ciclo
          str     r6,[r10]
          str     r7,[r10,#4]
          str     r8,[r10,#8]




