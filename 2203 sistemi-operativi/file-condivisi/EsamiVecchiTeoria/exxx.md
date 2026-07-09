![[Pasted image 20240701155121.png]]
```
1000 0000 0000 0000

- crea A 6 blocchi
1000 0000 0000 0000 => 1111 1110 0000 0000
				        --- ---

- crea B 5 blocchi
1111 1110 0000 0000 => 1111 1111 1111 0000
						       - ----

- cancella A
1111 1111 1111 0000 => 1000 0001 1111 0000

- crea C da 8
1000 0001 1111 0000 => 1111 1111 1111 1100
						--- ---       --

- cancella B
1111 1111 1111 1100 => 1111 1110 0000 1100
                               - ----

```

![[Pasted image 20240701161315.png]]

```
spazio indirizzamento virtuale = 2^30
pagina = 22 bit
fisico = 20 bit

30 - 22 = 8 (dimensione pagina)

20 - 8 = 12 => 2^12 (numero frame fisici)
```

![[Pasted image 20240701162754.png]]
```
S = 0
	p1 bloccato
R = 0
	
T = 0
	p3 bloccato

x = 1 [output finale]
```

![[Pasted image 20240701170741.png]]

$$
\text{overhead}=\frac{\text{esecuzione kernel}}{\text{tempo totale}}
$$

```
5/55 = 0,009 * 100 = 9
```

![[Pasted image 20240702190941.png]]

```
diretti: 12 * 1kb = 12kb = 2^11
indiretto singolo:
	punto ad un blocco (blocco indiretto singolo) della grandezza 1kb = 2^10
	calcolo numero blocchi contenuti nell' indiretto: 2^10/2^5 = 2^5

	totale = 1kb * 32 = 2^15
indiretto doppio:
	totale = (2^15)^2 = 2^30


final = sum(...)
```



