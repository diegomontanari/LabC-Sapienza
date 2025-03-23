#include <stdio.h>
#include <stdlib.h>

int	main()
{	
	int *n = 0; // n è un puntatore, *n è il valore associato.

	printf("Inserisci un numero: ");
	scanf("%d", n);
	
	n = (int *) malloc(*n * sizeof(int));
	if (!n)
		return 1;

	for (int i = 0; i < *n; i++)
	{
		printf("0X%p", n); //Stampa indirizzo
		printf("%d", *n); // Stampa il valore associato
		n++;
	}
	free();
	return 0;
}

/*
È molto meglio dichiarare prima il puntatore e poi assegnargli la memoria con malloc. In questo modo, puoi facilmente usare scanf per leggere un valore direttamente nella memoria allocata dinamicamente.

Esempio corretto
----
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *n;  
    n = (int *) malloc(sizeof(int));  // Allocazione di memoria per un intero

----
Perché è la scelta migliore?
✅ Evitare errori di dereferenziazione: Dichiarando un int normale, perderesti il vantaggio della memoria dinamica.
✅ Facilità d'uso con scanf: Con un puntatore puoi passarlo direttamente senza usare l'operatore &.
✅ Flessibilità: Puoi riallocare la memoria (realloc), cambiare la dimensione o usarla in strutture più complesse.



NOTA: Qui in passato avevo fatto un grave errore. Avevo allocato un blocco di memoria con malloc, ma poi avevo incrementato il puntatore. Quando ho fatto free del puntatore, con l'obiettivo di liberare tutto quel blocco precedentemente allocato, avrei dovuto restituire il puntatore esattamente come era quando ho allocato, non incrementato. Ora ho imparato a liberare con free un puntatore che punta all'identica posizione a cui puntava quando ho allocato con malloc.
*/
