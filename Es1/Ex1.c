#include <stdio.h>

int     main()
{
double	x;
double	a;
double	b;

printf("Inserisci a");
scanf("%lf", &a);
printf("Inserisci b");
scanf("%lf", &b);
if (a == 0)
{
        printf("Errore: Divisione per zero non permessa!\n");
        return 1;  // Esci con errore
}
x = -b / a;
printf("%lf", x);
return 0;
}
