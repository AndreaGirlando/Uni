### 📘 Derivate delle funzioni elementari

| Funzione \( f(x) \) | Derivata \( f'(x) \)   | Esempio                                                    |
| ------------------- | ---------------------- | ---------------------------------------------------------- |
| $c$                 | $0$                    | $f(x) = 5 \Rightarrow f'(x) = 0$                           |
| $x$                 | $1$                    | $f(x) = x \Rightarrow f'(x) = 1$                           |
| $x^n$               | $n x^{n-1}$            | $f(x) = x^3 \Rightarrow f'(x) = 3x^2$                      |
| $\sqrt{x}$          | $\dfrac{1}{2\sqrt{x}}$ | $f(x) = \sqrt{x} \Rightarrow f'(x) = \dfrac{1}{2\sqrt{x}}$ |
| $\dfrac{1}{x}$      | $-\dfrac{1}{x^2}$      | $f(x) = \dfrac{1}{x} \Rightarrow f'(x) = -\dfrac{1}{x^2}$  |
| $e^x$               | $e^x$                  | $f(x) = e^x \Rightarrow f'(x) = e^x$                       |
| $a^x$               | $a^x \ln a$            | $f(x) = 2^x \Rightarrow f'(x) = 2^x \ln 2$                 |
| $\ln x$             | $\dfrac{1}{x}$         | $f(x) = \ln x \Rightarrow f'(x) = \dfrac{1}{x}$            |
| $\log_a x$          | $\dfrac{1}{x \ln a}$   | $f(x) = \log_2 x \Rightarrow f'(x) = \dfrac{1}{x \ln 2}$   |

---

### 🧮 Derivate delle funzioni trigonometriche

| Funzione \( f(x) \) | Derivata \( f'(x) \)   | Esempio                                                  |
| ------------------- | ---------------------- | -------------------------------------------------------- |
| $\sin x$            | $\cos x$               | $f(x) = \sin x \Rightarrow f'(x) = \cos x$               |
| $\cos x$            | $-\sin x$              | $f(x) = \cos x \Rightarrow f'(x) = -\sin x$              |
| $\tan x$            | $\dfrac{1}{\cos^2 x}$  | $f(x) = \tan x \Rightarrow f'(x) = \dfrac{1}{\cos^2 x}$  |

---
### 🔁 Derivate delle funzioni inverse trigonometriche

| Funzione \( f(x) \) | Derivata \( f'(x) \)         | Esempio                                                           |                  |                                                   |     |                  |
| ------------------- | ---------------------------- | ----------------------------------------------------------------- | ---------------- | ------------------------------------------------- | --- | ---------------- |
| $\arcsin x$         | $\dfrac{1}{\sqrt{1 - x^2}}$  | $f(x) = \arcsin x \Rightarrow f'(x) = \dfrac{1}{\sqrt{1 - x^2}}$  |                  |                                                   |     |                  |
| $\arccos x$         | $-\dfrac{1}{\sqrt{1 - x^2}}$ | $f(x) = \arccos x \Rightarrow f'(x) = -\dfrac{1}{\sqrt{1 - x^2}}$ |                  |                                                   |     |                  |
| $\arctan x$         | $\dfrac{1}{1 + x^2}$         | $f(x) = \arctan x \Rightarrow f'(x) = \dfrac{1}{1 + x^2}$         |                  |                                                   |     |                  |

---

### 🧠 Regole di derivazione

| Regola                              | Formula                                                      | Esempio |
|------------------------------------|--------------------------------------------------------------|---------|
| Lineare                            | $[af(x) + bg(x)]' = a f'(x) + b g'(x)$                       | $f(x) = 2x^2 + 3x \Rightarrow f'(x) = 4x + 3$ |
| Prodotto                           | $[f(x) g(x)]' = f'(x)g(x) + f(x)g'(x)$                       | $f(x) = x \sin x \Rightarrow f'(x) = \sin x + x \cos x$ |
| Quoziente                          | $\left[\dfrac{f(x)}{g(x)}\right]' = \dfrac{f'(x)g(x) - f(x)g'(x)}{g(x)^2}$ | $f(x) = \dfrac{x}{\cos x} \Rightarrow f'(x) = \dfrac{\cos x + x \sin x}{\cos^2 x}$ |
| Composizione (catena)              | $[f(g(x))]' = f'(g(x)) \cdot g'(x)$                          | $f(x) = \sin(x^2) \Rightarrow f'(x) = \cos(x^2) \cdot 2x$ |
