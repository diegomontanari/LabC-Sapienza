#include <stdio.h>

int main() 
{
    char c;    
    short s;   
    int i;
    long l;    
    float f;   
    double d;
    long double ld;

    printf("Dimensione di char: %zu byte\n", sizeof(c));
    printf("Dimensione di short: %zu byte\n", sizeof(s));
    printf("Dimensione di int: %zu byte\n", sizeof(i));
    printf("Dimensione di long: %zu byte\n", sizeof(l));
    printf("Dimensione di float: %zu byte\n", sizeof(f));
    printf("Dimensione di double: %zu byte\n", sizeof(d));
    printf("Dimensione di long double: %zu byte\n", sizeof(ld));

    return 0;
}

/*
'zu' è il modificatore di formato per stampare un valore di tipo 'size_t', che
      rappresenta la dimensione di un oggetto in memoria. La dimensione di 'size_t' dipende
      dall'architettura del sistema (4 byte su sistemi a 32 bit e 8 byte su sistemi a 64 bit).
*/
