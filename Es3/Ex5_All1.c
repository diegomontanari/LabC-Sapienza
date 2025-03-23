#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *n = malloc(sizeof(int)); // It is not necessary to do the casting before malloc because the type of the variable to which the pointer is assigned is already declared as int*. The implicit cast happens automatically.
    int *min = malloc(sizeof(int));
    *min = -1; // Default value: -1 indicates that no positive number has been processed yet.

    printf("Insert a number (0 to stop): ");
    scanf("%d", n); // ⚠️ Warning: Do not write scanf("%d", &n); because n is already a pointer, and &n would be a double pointer (int**).

    while (*n != 0)
    {
        if (*n < 0) {
            printf("The number needs to be positive, try again: ");
        } else {
            // Se è il primo numero positivo, aggiorna min.
            if (*min < 0)
                *min = *n;
            // Altrimenti, se il nuovo numero è minore del corrente minimo, aggiorna min.
            else if (*n < *min)
                *min = *n;
        }
        
        printf("Insert a number (0 to stop): ");
        scanf("%d", n);
    }

    if (*min < 0) {
        printf("No positive numbers were entered.\n");
    } else {
        printf("The minimum number is: %d\n", *min);
    }

    free(n);
    free(min);
    return 0;
}

