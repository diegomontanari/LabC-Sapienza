#include <stdio.h>

int main() 
{
	int num;

	// Chiedi all'utente di inserire il lato del quadrato
	printf("Inserisci il lato del quadrato: ");
	scanf("%d", &num);
	
	// Ciclo per stampare il quadrato
	for (int i = 0; i < num; i++) // for esterno per le righe
	{      
        	for (int j = 0; j < num; j++) // for interno per i caratteri
		{  
            		printf("*");
        	}
        printf("\n");  // Vai a capo dopo ogni riga
	}

	return 0;
}
