         ;ricercadi una sottostringa di caratteri ASCII
TSTRING  DCB     0x43, 0x49, 0x41, 0x4F, 0x20, 0x43, 0x41, 0x52, 0x4C, 0x41, 0x21, 0x21
SUBSTR   DCB     0x43, 0x49, 0x41, 0x4F ;https://www.rapidtables.com/convert/number/ascii-to-hex.html
NR       EQU     12 ;n
NRSUB    EQU     4 ;m
RESULT   FILL    4
         MOV     R2, #TSTRING ;puntatore alla lista T
         MOV     R3, #SUBSTR ;puntatore alla lista P
         MOV     R10, #RESULT ;puntatore al risultato
         MOV     R4, #NR ;preleva il numero totale di caratteri in T
         MOV     R5, #NRSUB ;preleva il numero totale dei caratteri in P

         SUB     R4, R4, R5 ;n - m
         ADD     R4, R2, R4 ;indirizzo di T
         ADD     R5, R3, R5 ;indirizzo di P

         ;       Serve per reinizzializzare le variabili quando il confronto non le trova
CICLO1   MOV     R6, R2 ;tramite R6 scandisco la stringa T
         MOV     R7, R3 ;tramite R7 scandisco la stringa P


         ;confronto una coppia di caratteri
CICLO2   LDRB    R8, [R6],#1
         LDRB    R9, [R7],#1
         CMP     R8, R9
         BNE     NOTEQUAL ;effettuo il salto se R8 e R9 sono diversi
         ;fine   confronto
         CMP     R5, R7 ;proseguo fino a quando non arrivo all'ultimo byte, ovvero R5
         BGT     CICLO2 ;Controllo se R5 è un indirizzo più grande di quello che si trova in R7
         STR     R2, [R10] ;immagazzina il risultato
         B       FATTO


NOTEQUAL ADD     R2, R2, #1
         CMP     R4, R2
         BGE     CICLO1
         MOV     R8, #-1 ;scrivo -1 per indicare che non ho trovato nessuna corrispondenza
         STR     R8, [R10]


FATTO    END

