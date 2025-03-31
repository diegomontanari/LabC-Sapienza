#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getIndx(const char *str, int **idxs, int *dim) {
    *dim = strlen(str); // Determina la lunghezza della stringa
    *idxs = (int *)malloc((*dim) * sizeof(int)); // Alloca memoria per gli indici

    if (*idxs == NULL) { // Controllo che la malloc sia andata a buon fine
        printf("Errore di allocazione memoria.\n");
        exit(1);
    }

    for (int i = 0; i < *dim; i++) {
        (*idxs)[i] = i; // Popola l'array con gli indici della stringa
    }
}

void print_chars(const char s[], const int idxs[], int dim) {
    int len = strlen(s);
    for (int i = 0; i < dim; i++) {
        if (idxs[i] >= 0 && idxs[i] < len) {
            printf("%c", s[idxs[i]]);
        }
    }
    printf("\n");
}

int main() {
    char str[100]; // Array per la stringa di input
    int *idxs;
    int dim;

    printf("Inserisci una stringa: ");
    scanf("%99s", str); // Legge una stringa evitando overflow

    getIndx(str, &idxs, &dim); // Genera gli indici automaticamente
    print_chars(str, idxs, dim); // Stampa i caratteri usando gli indici generati

    free(idxs); // Libera la memoria allocata dinamicamente
    return 0;
}

/*
Note: I created the indxs array myself even if the assignment required me to use const int idxs[] . I did this as I wanted to make the exercise more difficoult.*/
