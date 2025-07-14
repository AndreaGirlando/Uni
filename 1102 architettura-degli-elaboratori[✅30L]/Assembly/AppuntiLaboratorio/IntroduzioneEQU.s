		;Posso	inserire tutti questi valori nella memoria
num1		dcd		1,2,3,4,5,6,7,8
num2		equ		31 ;Dichiarazione di una constante praticamente un define
num3		dcd		41
		
		
		mov		r1,#num2
		mov		r2,#num3
		ldr		r3,[r2]
		end ;il programma finisce qui
