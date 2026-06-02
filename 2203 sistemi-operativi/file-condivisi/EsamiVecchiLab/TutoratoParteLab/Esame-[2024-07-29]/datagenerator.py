import random

N_KEY = 5
N_CRYPT = 20
TEXTS = [
    "MESSAGGIO DI PROVA",
    "CIAO MONDO",
    "PASSWORD TOP SECRET",
    "MATEMATICA E INFORMATICA",
    "UNIVERSITA DI CATANIA",
    "TESTO MOLTO LUNGO PER TESTARE ALGORITMO"
]

ord = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

output = []
for _ in range(N_KEY):
    v = list(ord)
    random.shuffle(v)
    output.append(v)

with open("keys.text", "w") as fp:
    fp.write('\n'.join([''.join(x) for x in output])+"\n")


with open(f"ciphertext.text", "w") as fp:
    for m, text in enumerate(TEXTS):
        i = random.randint(0, N_KEY-1)
        key = {l: x for l, x in zip(list(ord), output[i])}

        crit = ''.join([key.get(x, x) for x in text])
        fp.write(f"{i}:{crit}\n")

with open(f"ciphertext.text", "r") as fp:
    for line in fp.readlines():
        index = int(line.split(':')[0])
        text = line.split(':')[1]
        key = {x: l for l, x in zip(list(ord), output[index])}
        dec = ''.join([key.get(x, x) for x in text])
        print(dec+"\n")
        pass
