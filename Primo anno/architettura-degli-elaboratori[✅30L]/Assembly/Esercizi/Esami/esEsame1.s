          ;Data   la lista [10,20,12,12,5,1,5,1] contare tutti i numeri diversi da 1 e 10.

list      dcd     10,20,12,12,5,1,5,1
dim       dcd     8
risultato fill    4
const1     EQU     10
const1     EQU     1


          mov     r1,#dim
          ldr     r1,[r1]
          mov     r2,#list
          mov     r3,#0
Ciclo     
          ldr     r8,[r2]
          cmp     r8,#const1; confronto se r8 è uguale alla constante1
          BEQ     NextCiclo ; Se sono uguali vado al ciclo successivo
          cmp     r8,#const1; confronto se r8 è uguale alla constante2
          BEQ     NextCiclo ; Se sono uguali vado al ciclo successivo
          add     r3,r3,#1  ; Se arrivo in questo punto il numero è diverso da 10 e 1
NextCiclo      
          add     r2,r2,#4 ; Punto all'elemento successivo della lista
          subs    r1,r1,#1 ; Decremento il contatore di uno
          BGT     Ciclo ; Salto a ciclo se r1 è maggiore di 0

          mov     r4,#risultato
          str     r3,[r4]



