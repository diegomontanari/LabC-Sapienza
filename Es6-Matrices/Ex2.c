#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int rows;
  int cols;
  float **rows_pt;
} Mat;

void mat_free(Mat *m)
{
	
	for (int i = 0; i < m->rows; i++)
	{
		free(m->rows_pt[i]); // libera ogni riga
	}
	
	free(m->rows_pt); // libera l'array di righe
	free(m);          // libera la struct Mat stessa

}


int main()
{
	Mat *m = malloc(sizeof(Mat)); //Alloco la matrice Mat
	if (!m) 
		return NULL;
	
	m->rows = 5; // Il campo rows di m è 5;
	m->cols = 3; // Il campo cols di m è 3;
	
	m->rows_pt = malloc(m->rows * sizeof(float*)); // Alloco 5 puntatori a float
	if (!m->rows_pt)
		return NULL;
	
	for (int i = 0; i < m->rows; i++)
	{
		m->rows_pt[i] = malloc(m->cols * sizeof(float)); // Alloco m->cols float per ogni riga
		if (!m->rows_pt[i])
			return NULL;
	}

}


// A questo punto la memoria è allocata, e puoi accedere agli elementi della matrice
// Usando m->rows_pt[i][j] = valore; dove i è l'indice della riga e j è l'indice della colonna


/*
NOTE: ORDINE DI ALLOCAZIONE/LIBERAZIONE MATRICE:
	- Per allocare: DALL'ESTERNO ALL'INTERNO,
	- Per liberare: DALL'INTERNO ALL'ESTERNO (sennò rischi memory leaks).
*/
