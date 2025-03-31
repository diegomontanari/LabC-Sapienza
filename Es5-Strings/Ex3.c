#include <stdlib.h>
#include <string.h>

char* invert_string(const char s[]) {
    int n = strlen(s);
    // Alloca memoria per la stringa invertita, includendo il terminatore nullo
    char *d = malloc((n + 1) * sizeof(char));
    if (d == NULL) {
        return NULL; // Gestione dell'errore di allocazione
    }
    
    // Copia i caratteri in ordine inverso
    for (int i = 0; i < n; i++) {
        d[i] = s[n - 1 - i];
    }
    
    // Aggiungi il terminatore di stringa
    d[n] = '\0';
    return d;
}

