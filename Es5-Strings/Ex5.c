#include <stdio.h>
#include <string.h>

// Devo mettere maiuscolo prima lettera di ogni parola e forzare minuscole tutte le altre
char* capitalizer(const char s[])
{
	#include <stdio.h>
#include <ctype.h>

char *capitalizer(const char s[])
{
	int i = 0;
	int newWord = 1; // Flag per sapere se siamo all'inizio di una parola

	while (d[i] != '\0')
	{
        if (isalpha(d[i])) 
	{ 
		if (newWord) 
		{
                	d[i] = toupper(d[i]); // Prima lettera maiuscola
                	newWord = 0;
            	} 
		else 
		{
                	d[i] = tolower(d[i]); // Altre lettere minuscole
            	}
        	else 
		{ 
            		newWord = 1; // Se troviamo uno spazio o un carattere non alfabetico, la prossima sarà una nuova parola
        	}
        	i++;
    	}
}

int main()
{
	const char *test1 = "   DDD Prova pROVA"; 
	const char *test2 = "Farò la GSOC";
	capitalizer(test1);
	capitalizer(test2);
	return (0);
}

/*
NOTE: LE FLAG SONO POTENTISSIME.

Le flag in C sono variabili (di solito int o bool) che servono per tenere traccia di uno stato. In questo caso, la flag newWord ci dice se il prossimo carattere che troviamo deve essere maiuscolo o no.

Come funziona la flag newWord?
📌 Obiettivo: Vogliamo identificare quando inizia una nuova parola per rendere la prima lettera maiuscola e le altre minuscole.

Quando newWord = 1 → significa che il prossimo carattere alfabetico sarà l'inizio di una parola → lo rendiamo maiuscolo.

Quando newWord = 0 → significa che siamo dentro una parola → rendiamo minuscole le lettere successive.

Quando troviamo uno spazio o un simbolo → impostiamo newWord = 1, così quando troviamo la prossima lettera, sappiamo che è una nuova parola.
Perché è utile?
Evita di dover controllare manualmente gli spazi prima di ogni parola.

Semplifica il ciclo: basta scorrere la stringa una volta. (Pensa che se non avessi usato le flag avresti dovuto scorrere la stringa per ogni parola...)

Funziona per qualsiasi testo, indipendentemente da quanti spazi ci siano o se le lettere sono già maiuscole o minuscole.

CONCLUSIONE:

🚀 Le flag sono un trucco potentissimo in C (e in programmazione in generale) perché ti permettono di tenere traccia di uno stato senza dover scrivere codice complicato o usare condizioni annidate.
*/
