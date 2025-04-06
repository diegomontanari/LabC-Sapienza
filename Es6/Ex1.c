#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
  int rows; // Numero di righe
  int cols; // Numero di colonne 
  float **rows_pt; // Array di array (le righe)
} Mat;

Mat* mat_alloc(int rows, int cols) {
    // 1. Allocazione della struttura Mat
    Mat *m = malloc(sizeof(Mat)); // Dichiaro e alloco *m come puntatore alla struct
    if (m == NULL) {
        return NULL;  // Errore di allocazione
    }
    
    // 2. Inizializzazione dei campi rows e cols
    m->rows = rows;  // Inizializzo il campo (*m).rows = rows (ovvero alloco il numero di righe (non le righe!!))
    m->cols = cols; // Idem
    
    // 3. Allocazione dell'array di puntatori alle righe 
    m->rows_pt = malloc(rows * sizeof(float *)); // Alloco (*m).rows = malloc (righe * puntatore a righe) dato che m->rows è un array di array (ovvero un array di array)
    if (m->rows_pt == NULL) {
        free(m);
        return NULL;
    }
    
    // 4. Allocazione di ogni riga (un array di float di dimensione cols)
    for (int i = 0; i < rows; i++) {
        m->rows_pt[i] = malloc(cols * sizeof(float)); // (m*).rows_pt (ovvero la singola riga) viene allocata
        if (m->rows_pt[i] == NULL) {
            // Se fallisce l'allocazione di una riga, libero tutto quello già allocato
            for (int j = 0; j < i; j++) {
                free(m->rows_pt[j]);
            }
            free(m->rows_pt);
            free(m);
            return NULL;
        }
    }
    
    return m;
}
