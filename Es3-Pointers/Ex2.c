#include <stdio.h>

int main()
{
    int i = 10;
    int j = -1;
    char *p, *q;

    p = (char*)&i;  // p punta a i
    q = (char*)&j;  // q punta a j

    // Copia byte per byte il valore di i dentro j
    for (size_t k = 0; k < sizeof(int); k++) {
        q[k] = p[k];  // Copia il k-esimo byte
    }

    printf("%d == %d\n", i, j);  // Verifica che i == j
    return 0;
}
