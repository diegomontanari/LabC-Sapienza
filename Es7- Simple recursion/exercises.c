// ric.1
int sum_tail(int n, int acc)
{
	if (n <= 0)
		return acc;
	return sum_tail(n - 1, acc + n);
}

// ric.2
int sum_of_squares(int n) {
    if (n == 0) return 0;
    if (n % 2 == 0)
        return n * n + sum_of_squares(n - 1);
    else
        return n * 2 + sum_of_squares(n - 1);
} // This is not tail-recursiove but works

// ric_arr.1
float product(float vec[], int n)
{
    if (n == 0) // Caso base
        return 1
    else
        return (vec[n-1] * product(vec, n-1))
}

// 
void vec_integral(float* v, int n)
{

}

che scrive in ogni elemento dell’array v[i] la somma di tutti gli elementi che lo precedono da 0 a i-1.




// Esercizio ric_str.1

int length(char * s)
{
    if (!*s) return 0;
    else return (1 + length(++s)); // Pre-increment works ; s + 1 works ; but s++ does NOT work (due to infinite recursion)
}



