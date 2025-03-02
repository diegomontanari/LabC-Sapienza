#include <stdio.h>

int main()
{
double	numero = 0;
double	somma = 0;
double	media;
int	n_numeri = 0;

printf("Inserisci un numero: (0 per terminare)");
scanf("%lf", &numero);
while (numero != 0)
{

	somma += numero;
	n_numeri++;
	printf("Inserisci un numero: (0 per terminare)");
	scanf("%lf", &numero);
}
media = somma / n_numeri;
printf("%lf", media);
return 0; 
}
