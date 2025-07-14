
;LOAD	R1,LOC Carica il valore di LOC in R2
;ADD		R2,R1,R1 Fa la somma di R1 ed R1 e salva il risultato in R2
;STORE	R2,LOC Salva il valore di R2 dentro LOC
;MOVE	R3,R2 muove il contenuto di R2 in R3
;Substract	R4,R2,R1 Sottrae R1 ad R3 e salva il risutalto in R4

;Esempio	di codice che somma 2 numeri
;LOAD	A,R1
;LOAD	B,R2
;ADD		R3,R1,R2
;STORE	R3,C

num1 dcd 100
num2 dcd 251

mov  r1,#10
mov  r2,#30
mov r3,r2
add r4,r1,r2
sub r4,r1,r2

;Prendo il puntatore al valore num1 che si trova in memoria
mov r7,#num1
;Prendo il valore puntato da r7 e lo salvo in r5
ldr r5,[r7]

add r9,r5,r1
;Salvo il valore di R9 nella locazione di memoria puntata da R7
str r9,[r7]

;END è praticamante un return



























