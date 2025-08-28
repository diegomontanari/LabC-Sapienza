#include <stdio.h>

int main() {
    int i, N, primo = 1, secondo = 1, terzo;

    // Chiediamo all'utente quanti numeri della successione desidera visualizzare
    printf("Quanti numeri della successione vuoi visualizzare? ");
    scanf("%d", &N);

    // Se N è minore o uguale a 0, non c'è nulla da visualizzare
    if (N <= 0) {
        printf("N deve essere un numero positivo maggiore di zero.\n");
        return 1; // Segnaliamo un errore al sistema operativo
    }

    // Visualizziamo i primi due numeri della successione (se N >= 1)
    if (N >= 1)
        printf("%d\n", primo);
    if (N >= 2)
        printf("%d\n", secondo);

    // Calcoliamo e visualizziamo i restanti numeri della successione
    for (i = 2; i < N; i++) {
        terzo = primo + secondo;
        primo = secondo; // scali di uno per passare al N dopo
        secondo = terzo; // idem, se lo fai una volta sola non funziona
        printf("%d\n", terzo);
    }

    return 0;
}
