**Calcolare il MCD**: Puoi usare l'algoritmo di Euclide.
**Calcolare l'MCM**: Usa la formula sotto.


\[
MCM(a,b) = \frac{|a \cdot b|}{MCD(a,b)}
\]


# Algoritmo di Euclide per il MCD

L'**algoritmo di Euclide** è un metodo efficiente per calcolare il **Massimo Comune Divisore (MCD)** di due numeri interi. Il MCD è il più grande numero che divide entrambi i numeri senza lasciare resto.

## Come funziona l'algoritmo?

L'algoritmo si basa sulla seguente relazione matematica:

\[
MCD(a, b) = MCD(b, a \mod b)
\]

Dove `%` rappresenta l'operatore di resto della divisione. Questo significa che il MCD di due numeri `a` e `b` è lo stesso del MCD tra `b` e il resto della divisione `a % b`.

### Passaggi dell'algoritmo:
1. Se `b` è uguale a `0`, allora `a` è il MCD di `a` e `b`.
2. Altrimenti, calcola il resto della divisione di `a` per `b` (ovvero `a % b`).
3. Sostituisci `a` con `b` e `b` con `a % b`.
4. Ripeti il passo 2 fino a quando `b` diventa `0`.

---

## Esempio di calcolo del MCD tra 48 e 18

1. **Calcola il resto** di `48` diviso `18`:
   \[
   48 \mod 18 = 12
   \]
2. **Calcola il MCD** di `18` e `12`:
   \[
   18 \mod 12 = 6
   \]
3. **Calcola il MCD** di `12` e `6`:
   \[
   12 \mod 6 = 0
   \]
4. Poiché il resto è `0`, il MCD è **6**.

Quindi:
\[
MCD(48, 18) = 6
\]

---

## Implementazione in C

Ecco il codice C per calcolare il **MCD** utilizzando l'algoritmo di Euclide:

```c
#include <stdio.h>

// Funzione per calcolare il MCD usando l'algoritmo di Euclide
int mcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;  // Calcola il resto della divisione
        a = temp;   // Aggiorna a con il valore di b
    }
    return a;  // Quando b è 0, a contiene il MCD
}

int main() {
    int a = 48, b = 18;
    printf("Il MCD di %d e %d è: %d\n", a, b, mcd(a, b));
    return 0;
}
```
