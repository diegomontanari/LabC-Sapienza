#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    float **rows_pt;
} Mat;

void mat_print(Mat *m)
{
	for (int r = 0; r < m->rows; r++) { 
		for (int c = 0; c < m->cols; c++) {
			printf("%f ", m->rows_pt[r][c]); // NOTE: m[i][j] is ofc WRONG as you need to access the matrix (2d array) but m is the pointer TO the stuct m, which is not a 2d array, just a pointer. m->rows_pt , instead, it is a 2d array so I can access it. 

		}
		printf("\n");
	}
}

int main()
{
        Mat *m = malloc(sizeof(Mat)); //Alloco la matrice Mat
        if (!m)
                return 1;

        m->rows = 5; // Il campo rows di m è 5;
        m->cols = 3; // Il campo cols di m è 3;

        m->rows_pt = malloc(m->rows * sizeof(float*)); // Alloco 5 puntatori a float
        if (!m->rows_pt)
                return 1;

        for (int i = 0; i < m->rows; i++)
        {
                m->rows_pt[i] = malloc(m->cols * sizeof(float)); // Alloco m->cols float per ogni riga
                if (!m->rows_pt[i])
                        return 1;
        }
	 // Inizializzare la matrice con dei valori (ad esempio, 0.0)
        for (int i = 0; i < m->rows; i++) {
                for (int j = 0; j < m->cols; j++) {
                        m->rows_pt[i][j] = 0; // Inizializzo la matrice con valori esemplificativi
                }
	}
	
	mat_print(m);
	
	// Liberare la memoria allocata
        for (int i = 0; i < m->rows; i++) {
                free(m->rows_pt[i]);
        }
        free(m->rows_pt);
        free(m);
	
	return (0);

}

/* NOTE: no NULL nel main
	- Non si può fare return NULL nel main per ovvie ragioni, usa return 1;
*/
