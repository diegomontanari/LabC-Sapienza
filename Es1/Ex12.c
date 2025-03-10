#include <stdio.h>
#include <math.h>

double sqrt_newton(double x) {
    if (x < 0) {
        printf("Errore: il numero non può essere negativo.\n");
        return -1; // Errore per numero negativo
    }

    double Rn = x; // Impostiamo R0 = x
    double Rn_1 = Rn; // Variabile per tenere traccia della iterazione precedente
    double epsilon = 0.000001; // Precisione desiderata

    while (fabs(Rn - Rn_1) > epsilon) // fabs sta per "floating-point absolute value" e restituisce il valore assoluto di un numero in virgola mobile qualunque sia il tipo (float, double o long double). abs fa lo stesso per gli int, ma non va bene per long e long long (in quel caso usi labs e llabs). Disuguaglianza di genere (tipo)...
    {
        Rn_1 = Rn;
        Rn = (Rn_1 + x / Rn_1) / 2; // Formula di Newton
    }

    return Rn;
}

int main() {
    double x;
    printf("Inserisci un numero per calcolare la sua radice quadrata: ");
    scanf("%lf", &x);

    double result = sqrt_newton(x);

    if (result != -1) {
        printf("La radice quadrata di %.6f è circa: %.6f\n", x, result);
    }

    return 0;
}
