# 🎓 Tutorato Sistemi Operativi A.A. 2024-2025

## 📂 Struttura del Repo

```
├── Esercizio 1
├── Esercizio 2
├── ...
├── Esercizio i
│   ├── *.pdf                     # Per ogni esercizio pdf che propone il questio affrontato (es. testo d'esame)
│   ├── *.txt                     # File necessari per lo svoglimento dell'esercizio 
│   ├── main.c                    # Soluzione
│   └── Soluzione_alt_[COGNOME]/[GitHub Username]   # Soluzioni alternative fornite dagli studenti (Mettere Cognome o l'username di GitHub)
│       ├── Changes.md            # MD per elencare le differenze con la soluzione proposta dal Tutor
│       └── main.c                # Soluzione proposta dallo studente, con lo stesso nome della soluzione proposta dal Tutor
├── Esame-[Data]
├── ...
├── Esame n
├── Slide
│   └── *.pdf                  # Eventuali Slide fornite durante il tutorato
└── README.md                 # Questo file!
````

## 🛠️ Prerequisiti

- **Git** ≥ 2.20  
- **GCC/Clang** per compilare esempi in C  
- Ambiente Linux (consigliato Ubuntu 20.04+ o WSL2)  

---

## ⚙️ Installazione & Avvio

1. **Clona la repo**  
   ```bash
   git clone https://github.com/timeassassinRG/Tutorato-Sistemi-Operativi-2025.git
   cd Tutorato-Sistemi-Operativi-2025
   ````

2. **Naviga nella sezione di tuo interesse**

   ```bash
   cd Esercizio i
   ```

3. **Compila e testa**

   ```bash
   gcc main.c -o main
   ./main
   ```

---

## 🎯 Come Contribuire

1. Fai un *fork* del progetto
2. Crea un nuovo *branch* (`git checkout -b feature/nome-feature`)
3. Aggiungi il tuo materiale o correggi un esercizio
4. Apri una *Pull Request* descrivendo le modifiche

---

Happy studying! 🚀
