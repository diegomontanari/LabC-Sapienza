#include <stdio.h>
#include <math.h>

int	main() 
{
	short s;
	int i;
	long l;
	float f;
	double d;

	printf("Inserisci il valore short: ");
	scanf("%hd", &s);
	printf("Inserisci il valore int: ");
	scanf("%d", &i);
	printf("Inserisci il valore long: ");
	scanf("%ld", &l);
	printf("Inserisci il valore float: ");
	scanf("%f", &f);
	printf("Inserisci il valore double: ");
	scanf("%lf", &d);

	printf("1. s + 10 * l = %ld\n", s + 10 * l); // Ricorda che lo specificatore di formato dipende dal RISULTATO dell'operazione, ovvero dal tipo di dato che ha maggiore precisione (per capirci, il tipo di dato più grande) (es: short * long long int vuole %lld)
	printf("2. (s + i) * l = %ld\n", (s + i) * l);
	printf("3. (s + i) * l + f = %.2f\n", (s + i) * l + f); // %.2f significa che sto approssimando il float a due cifre decimali 
	printf("4. s / f + sin(f) = %.2f\n", s / f + sin(f));	
	printf("5. l + 1.5 * f = %.2f\n", l + 1.5 * f);
	printf("6. i < 10 = %d\n", i < 10); // Stampa 1 se vero, 0 se falso
	printf("7. d * 3.14159 = %.5lf\n", d * 3.14159);

	return 0;
}
