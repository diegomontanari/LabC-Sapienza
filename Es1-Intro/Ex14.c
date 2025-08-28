#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funzione per verificare se due numeri contengono le stesse cifre
int is_permutation(int num, int original_digits[]) {
    int digits[10] = {0};  // Array per contare le cifre da 0 a 9
    while (num > 0) {
        digits[num % 10]++;  // Conta la cifra corrente
        num /= 10;
    }
    
    // Controlliamo se i conteggi corrispondono all'originale
    for (int i = 0; i < 10; i++) {
        if (digits[i] != original_digits[i]) return 0;
    }
    return 1;
}

// Funzione ricorsiva per generare tutte le permutazioni delle cifre
void generate_permutations(char* str, int l, int r) {
    if (l == r) {  // Se la permutazione è completa
        int num = atoi(str);  // Converte la permutazione in numero
        
        // Conta le cifre del numero originale per confrontarle con i multipli
        int original_digits[10] = {0};
        for (size_t i = 0; i < strlen(str); i++) {  // Modifica qui a 'size_t'
            original_digits[str[i] - '0']++;
        }

        // Controlliamo i multipli 2x, 3x, 4x, 5x, 6x
        int valid = 1;
        for (int i = 2; i <= 6; i++) {
            if (!is_permutation(num * i, original_digits)) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            printf("Il più piccolo numero straordinario è: %d\n", num);
            exit(0);  // Termina il programma appena troviamo il numero
        }
    } else {
        for (int i = l; i <= r; i++) {
            // Scambia i caratteri
            char temp = str[l];
            str[l] = str[i];
            str[i] = temp;
            
            generate_permutations(str, l + 1, r);  // Chiamata ricorsiva
            
            // Ripristina l'ordine originale (backtracking)
            temp = str[l];
            str[l] = str[i];
            str[i] = temp;
        }
    }
}

int main() {
    char digits[] = "124578";  // Cifre consentite
    int n = strlen(digits);

    generate_permutations(digits, 0, n - 1);  // Genera e verifica le permutazioni

    return 0;
}
