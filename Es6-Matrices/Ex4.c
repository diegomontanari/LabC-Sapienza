#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	int rows;
	int cols;
	float **rows_pt;
}	Mat;

bool mat_is_symmetric(Mat *m)
{
	// Una matrice per essere simmetrica deve essere quadrata
	if (m->rows != m-> cols)
		return false;
	//  Una matrice è simmetrica se ogni elemento m_ij è uguale all'elemento m_ji
	for (int i = 0; i < m->rows; i++) {
    		for (int j = i + 1; j < m->cols; j++) {  // Confrontiamo solo sopra la diagonale
        		if (m->rows_pt[i][j] != m->rows_pt[j][i]) {
            			return false;  // Se troviamo una differenza, la matrice non è simmetrica
			}
		}
	}
  	return true;
}

int main()
{
	Mat *m = malloc(sizeof(Mat)); //Alloco la struttura Mat
	
	m->rows = 4; // (*m).rows = valore (Non va dichiarato con tipo e può essere direttamente assegnato perché è un campo non una variabile
	m->cols = 4; // RICORDA: la simmetrica implica non solo che ogni ij = ji, ma anche che la matrice sia QUADRATA.  
	
	m->rows_pt = malloc(m->rows * sizeof(float*)); // Alloco m->rows float pointers (Quindi alloco i float* alle righe, quindi alloco le righe)
	
	int counter = 1;
	for (int i = 0; i < m->rows; i++) {
		m->rows_pt[i] = malloc(m->cols * sizeof(float)); // Alloco ogni singola riga
		for (int j = 0; j < m->cols; j++) {
			m->rows_pt[i][j] = counter++; //Funziona perché a diff. di ++counter prima assegna il valore e poi lo incrementa. 
		}
	}

	mat_is_symmetric(m); // Dato che dobbiamo passare alla funzione un Mat *m dobbiamo passare m, passare *m passerebbe solo Mat che non va bene
	if (mat_is_symmetric(m)) 
	{
        	printf("La matrice è simmetrica.\n");
    	} 
	else 
	{
        	printf("La matrice NON è simmetrica.\n");
    	}

	// Libero la memoria
	for (int i = 0; i < m->rows; i++) {
        free(m->rows_pt[i]);
    	}
    	free(m->rows_pt);
   	free(m);

	return 0;
}
