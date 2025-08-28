#include <stdio.h>
#include <stddef.h> // Lib for ptrdiff_t

int	main()
{
	int arr[2] = {0, 0};  // Creating an array to ensure that 'a' and 'b' are adjacent in memory (and initializing them it's a good idea)
	int *ptr_a = &arr[0];
	int *ptr_b = &arr[1]; 

	ptrdiff_t dist = ptr_b - ptr_a; // ptrdiff_t is a data type for a ptr diff
	
	*(ptr_b - dist) = 13; // Indirectly modifing the value of a
	printf("Value of a: %d", arr[0]);
}

/* 
NOTE ABOUT ptrdiff_t:

When you subtract two pointers of the same type, the result is an integer value that indicates how many ELEMENTS (not how many bytes) apart the two addresses are in memory. 

ptrdiff_t is the correct type to store this difference because it is PORTABLE and ensures the proper handling of the returned value's size, regardless of the architecture (32-bit, 64-bit, etc.).

NOTE ABOUT INDIRECT MODIFICATION OF A VALUE USING A POINTER:

By subtracting the distance between memory addresses, you move the pointer to indirectly modify the value of a through b.

NOTE ABOUT SECURITY:

I could have used &a and &b in the difference and I could have decleared a = 0 and b = 0. But, even if I'm very likely that the compiler will use adiacent memory cells for a and b, it's still better to use an array to be 100% sure.

*/
