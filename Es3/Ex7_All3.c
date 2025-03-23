#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Allocazione dinamica della memoria
    double *p = (double *)malloc(sizeof(double)); //Allocando direttamente dal puntatore e facendo scanf sul puntatore evito di dover inizializzare la variabile a cui i puntatori punterebbero (non devo passare per la variabile)
    char *p2 = (char *)malloc(sizeof(char));

    // Controllo se l'allocazione è riuscita
    if (p == NULL || p2 == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return 1; // Esce con errore
    }

    printf("Inserisci un numero: ");
    scanf("%lf", p);

    printf("Inserisci un carattere: ");
    scanf(" %c", p2); // Spazio prima di %c per evitare problemi con newline

    // Loop finché l'input non è valido
    while (*p2 != 'c' && *p2 != 'f' && *p2 != 'k')
    {
        printf("Errore, inserisci 'c', 'f' o 'k' in minuscolo\n");
        printf("Inserisci un carattere: ");
        scanf(" %c", p2);
    }

    // Conversioni di temperatura
    if (*p2 == 'c')
    {
        printf("K: %lf\n", *p + 273.15);
        printf("F: %lf\n", (*p * 9 / 5) + 32);
    }
    else if (*p2 == 'f')
    {
        printf("K: %lf\n", (*p - 32) * 5 / 9 + 273.15);
        printf("C: %lf\n", (*p - 32) * 5 / 9);
    }
    else if (*p2 == 'k')
    {
        printf("C: %lf\n", *p - 273.15);
        printf("F: %lf\n", (*p - 273.15) * 9 / 5 + 32);
    }

    // Liberiamo la memoria allocata
    free(p);
    free(p2);

    return 0;
}

