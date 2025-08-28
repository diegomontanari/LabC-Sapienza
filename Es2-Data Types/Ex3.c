#include <stdio.h>

int	main()
{
	unsigned char	i = 32; // Signed da problemi perché i valori + alti sono negativi e non si arriva mai a 127 quindi loop infinito
	while (i <= 127)
	{
		printf("%c ; %d\n", i, (int)i);
		i++;
	}
	return 0;		
}
/*
NOTE:
unsigned char: range da 0 a 255
signed char: range da -128 a 127

immagina di usare un signed char e di essere a i = 127.
Entri nel ciclo, stampi carattere DEL, incrementi i. 
Ma i ora non vale 128, vale -128, quindi la condizione del while resta vera.
Quindi loop infinito e tanti problemi.
*/
