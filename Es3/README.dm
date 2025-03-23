I learned from exercise 9 of this practice that when dynamically allocating memory with malloc(), it is essential to keep the pointer in its original position to properly free it with free().

If the pointer is incremented, the reference to the original address returned by malloc() is lost. As a result, when calling free(n), the memory block is not correctly freed, leading to undefined behavior and potential memory leaks.
 
