# 1
D. Shift a destra di C ed inserimento del bit di referenziamento R come bit piu significativo.

# 2
b , e (?)

# 3
```
indirizzamento_virtuale = 2^30

offset = 2^30 - 2^22 = 2^8

frame_fisici = 2^20 / 2^8 = 2^12
```

# 4
```
x = 1
s = 1
r = 0
t = 0

x = 1
s = bloccato p1
r = p2
t = bloccato p3

output = 1
```

# 5
1. calcolo offset 10100
7 -> 1 -> 4

2. dimensione
7 -> 1 -> 4 -> 5 -> 10 -> {-1}
`max = 5 * 4kB = 20kB`
`min = 4 * 4kb + 1 = 16kb+1`

# 6

assumendo il primo blocco sia il blocco 1:
$$
\text{numero blocco in cui ricade = } \left \lfloor \frac{\text{offset}}{\text{dimensione blocco}} \right \rfloor +1
$$

x=15kB
- `(15 / 4) + 1 = 3 + 1 = 4 (blocco)` 

y=70KB
- calcolo il numero  il numero blocchi contenuto nel blocco ind. singolo per capire quando parte l'indiretto doppio
	- `4KB/4B = 4096 / 4 = 1024`
	- copre quindi da 11 a 1034
- calcolo blocco
	- `(70kB / 4kB) + 1 = 18 + 1 = 19`


z=2MB

- calcolo blocco 
	`(2^21 / 2^12) + 1 = 2^9 + 1 = 513 blocco`
- ricade nell'indiretto singolo

# 7
```


politica scan
t = 0 {100,50,115,180}
t = 70 {150}
t = 130 {90}


t = 0 [salgo]
	entrano e servo 100
	{50,115,180}
	testina = 100

t = 15 [salgo]
	servo il 115
	{50,180}
	testina = 115

t = 70 [salvo]
	entra il 150
	{50,180, 150}
	testina = 170

t = 80 [salgo]
	servo il 180
	{50,150}
	testina = 180

t = 110 [scendo]
	servo il 150
	{50}
	testina = 150

t = 130 [scendo]
	entra il 90
	{50, 90}
	testina = 130

t = 170 [scendo]
	servo il 90
	{50}
	testina = 90

t = 210
	servo il 50
	{}
	testina = 50
```

l'ordine (100, 115, 180, 150, 90, 50)
