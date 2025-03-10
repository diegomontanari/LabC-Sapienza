#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int	M;
	int	N;
	int	C;

	printf("Inserisca un numero M (max): ");
	scanf("%d", &M);
	printf("Inserisca un numero N (min): ");
	scanf("%d", &N);

	if (M - N <= 0)
	{
		printf("ERRORE! Scegli un M maggiore di N");
		return 1;
	}
	C = rand() % (M - N + 1) + N;
	printf("Il numero casuale nell'intervallo è: %d", C);
	return 0;
}
