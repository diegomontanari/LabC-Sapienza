#include <stdio.h>

int main()
{
	int a = 10;
	int b = -1;
	int c;
	int *pa, *pb, *pc;

	pa = &a;
	pb = &b;
	pc = &c;

	*pc = *pa + *pb;
	printf("%d == a + b\n", c);
	return 0;
}
