#include <stdio.h>

int	main()
{
	int	N;
	
	printf("Inserisci un numero N > 0: ");
	scanf("%d", &N);

	if (N <= 0)
	{
		printf("ERRORE!");
		return 1;
	}
	
	for (int riga = 1; riga <= N; riga++) // Stampa righe fino a riga <= N
	{
		for (int numero = 1; numero <= riga; numero++) // Non lo sapevo ma i contatori dei cicli devono essere inizializzati nel for, fuori non va bene 
			printf("%d", numero);
		printf("\n");
	}
	return 0;
}
