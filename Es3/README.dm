```c
void *malloc(size_t size);
void *calloc(size_t num, size_t size);
void *realloc(void *ptr, size_t new_size);
```

### Differences between `malloc`, `calloc`, and `realloc` in one line:
- **`malloc(size)`**: Allocates `size` bytes of uninitialized memory.
- **`calloc(num, size)`**: Allocates `num * size` bytes of memory, initialized to zero. The `c` in `calloc` stands for "clear," indicating that the allocated memory is zero-initialized.
- **`realloc(ptr, new_size)`**: Resizes the memory block pointed to by `ptr`, preserving existing data.







I learned from exercise 9 of this practice that when dynamically allocating memory with malloc(), it is essential to keep the pointer in its original position to properly free it with free().

If the pointer is incremented, the reference to the original address returned by malloc() is lost. As a result, when calling free(n), the memory block is not correctly freed, leading to undefined behavior and potential memory leaks.
 
