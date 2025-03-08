#include <stdio.h>

int	main()
{
	int	num;
	printf("Inserisci un numero");
	scanf("%d", &num);
	for (int i = 0; i <= num - 1; i++) // for per righe
	{
		for (int j = 0; j <= num - 1; j++) // for per singola riga
		{
			
			if ( j == 0 || j == num -1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
