#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mocking_spongebob(const char s[], int step) {
    int len = strlen(s);
    char *d = malloc(len + 1);  // Allocazione memoria per la nuova stringa
    if (d == NULL) {
        printf("Errore di allocazione della memoria!\n");
        return NULL;  // Gestione errore allocazione
    }
    
    int count = 0;  // Contatore per tenere traccia di ogni 'step' caratteri (esclusi gli spazi)
    int j = 0;      // Indice per la nuova stringa
    
    // Scorri tutta la stringa di input
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            // Gli spazi vengono copiati ma non contati per lo step
            d[j++] = s[i];
        } else {
            // Incrementa il contatore solo per caratteri non spazio
            count++;
            
            if (count == step) {
                // Ogni 'step' caratteri (esclusi gli spazi), converti in maiuscolo se è minuscolo
                if (s[i] >= 'a' && s[i] <= 'z') {
                    d[j++] = s[i] - 32;  // Conversione in maiuscola
                } else {
                    d[j++] = s[i];  // Se già maiuscolo o altro carattere, lascialo invariato
                }
                count = 0;  // Resetta il contatore
            } else {
                // Caratteri normali, copiati senza modifiche
                d[j++] = s[i];
            }
        }
    }
    
    d[j] = '\0';  // Aggiungi il terminatore di stringa
    return d;     // Restituisci la nuova stringa
}

int main() {
    const char s[] = "Charles Leclerc e Max Verstappen";
    int step = 3;
    char *result = mocking_spongebob(s, step);

    if (result != NULL) {
        printf("Risultato: %s\n", result);
        free(result);  // Non dimenticare di liberare la memoria
    }

    return 0;
}

/* This was an error I made:

Ex4.c:33:9: error: address of stack memory associated with local variable 'd' returned [-Werror,-Wreturn-stack-address]
   33 |         return d;

Explanation: The array d is a local variable, and local variables are stored on the stack. Returning the address of a local variable (like d) is dangerous because that memory is deallocated when the function returns, leaving you with a dangling pointer. This is why you're seeing this error.

Fix: You need to dynamically allocate memory for d or change the logic so that you don't return the address of a local variable. One approach could be to allocate memory dynamically using malloc or to use s directly without needing d.
*/

// NOTA: RICORDATI SEMPRE QUESTO CONCETTO (COME CREARE ARRAY FUORI DAL MAIN)
// 1. Gli array statici dichiarati con `[]` vengono allocati nello **stack** e sono visibili solo all'interno della funzione in cui sono dichiarati.
//    Una volta che la funzione termina, l'array viene distrutto e non puoi più accedervi, portando a **dangling pointers** (puntatori non validi).
//    Usa gli array statici solo se la dimensione è conosciuta a priori e se non hai bisogno di conservarli fuori dalla funzione.
//    
// 2. Gli array dinamici creati con `malloc` vengono allocati nell'**heap** e rimangono validi finché non li liberi esplicitamente con `free()`.
//    Gli array dinamici sono utili quando la loro dimensione deve essere determinata durante l'esecuzione, oppure quando l'array deve essere accessibile
//    al di fuori della funzione in cui è stato creato.
//    Se hai bisogno di conservare l'array anche dopo l'uscita dalla funzione, usa sempre `malloc` per evitare problemi di memoria e accesso.

// Quindi, se devi creare un array fuori dal main, devi sempre usare la memoria dinamica per evitare dangling pointers.

/* 
NOTA: Per una conversione più robusta dei caratteri tra maiuscolo e minuscolo,
si può utilizzare la libreria standard <ctype.h> che fornisce le seguenti funzioni:


  Prototipi: int toupper(int c);  int tolower(int c);

Questo approccio funziona correttamente anche con set di caratteri estesi e
non si limita solo ai caratteri ASCII standard. (Per questo dico che è più "robusta" della conversione con -32).

Tuttavia, non esiste una funzione built-in C per convertire un'intera stringa, per cui ti serve un ciclo per farlo.
*/
