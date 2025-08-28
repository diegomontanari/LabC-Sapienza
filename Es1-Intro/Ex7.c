#include <stdio.h>
#include <limits.h>

int	main()
{
	int	num;
	int	min = INT_MAX;

	printf("Inserisci un numero, premi 0 per terminare: ");
	scanf("%d", &num);
	while (num != 0)
	{
		if (num <= min)
			min = num;
		printf("Inserisci un numero, premi 0 per terminare: ");
		scanf("%d", &num);
	}
	printf("Minimo: %d", min);
	return 0; 
}
