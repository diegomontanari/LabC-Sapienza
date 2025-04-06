## 🧠 Note: How to Dynamically Allocate a Matrix in C (float/int, etc.)

Whenever you're working with a **dynamically allocated matrix in C**, you **must allocate it in two separate steps**:

---

### ✅ Step 1: Allocate the Skeleton

Allocate an array of `float *` — these are the **pointers to each row**:

```c
m->rows_pt = malloc(rows * sizeof(float *));
```

---

### ✅ Step 2: Allocate Each Row

Each row is an array of `float` values (the **actual columns**):

```c
for (int i = 0; i < rows; i++) {
    m->rows_pt[i] = malloc(cols * sizeof(float));
}
```

**Note:** Since in each row we need to allocate **cols elements** (because **each row has the same number of elements as the number of columns**), we multiply  sizeof by cols to allocate enough memory for each row.

---

### 📈 Visual Tip:

> Think of the matrix as a **list of rows** → first you create the list (row pointers), then you fill each row with its values (the columns).

---

### 💣 Important:

If **any `malloc` fails**, make sure to **free all previously allocated memory** to avoid memory leaks!


## Difference Between `Mat` and `Mat2` Matrix Structures in C

When working with matrices in C, memory representation plays a key role in performance and memory management. Here’s the difference between the two structures:

### `Mat` – Matrix as Array of Arrays (Non-Contiguous Memory)
```c
typedef struct {
  int rows;
  int cols;
  float **rows_pt;
} Mat;
```

- Each row is a separate dynamically allocated array.
- `rows_pt` is a pointer to an array of pointers (each pointing to a row).
- **Memory is non-contiguous**: rows may be scattered in memory.
- Easier to access elements as `matrix.rows_pt[i][j]`, but may cause cache inefficiency.

---

### `Mat2` – Matrix as Flat Array (Contiguous Memory)
```c
typedef struct {
  int rows;
  int cols;
  float *element_pt;
} Mat2;
```

- All elements are stored in a **single contiguous block** of memory.
- Elements accessed via index computation: `matrix.element_pt[i * cols + j]`.
- **Better cache performance**, more efficient for numerical operations.
- Ideal when performance and memory locality matter.

---

Use `Mat2` when implementing more advanced or performance-critical operations (`bis` exercises), and `Mat` for simpler or conceptual implementations.

### Matrix Symmetry Check

To verify the symmetry of a matrix, one must compare the elements above the diagonal with those below the diagonal. This is because, for a symmetric matrix, each element above the diagonal must be equal to the corresponding element below the diagonal. This means:

The elements at position 
𝑚[𝑖][𝑗] must be equal to the elements at position 𝑚[𝑗][𝑖] (for 𝑖≠𝑗 , as we do not care about the values on the diagonal).

With j = i + 1, the loop starts comparing only the elements above the main diagonal. This eliminates the need to check the diagonal itself, which is always symmetric. Additionally, it prevents duplicate comparisons.

remember that for a matrix to be symmetrical, there are 2 conditions:
	1) The matrix needs to be square
	2) Every m[i][j] is equal to m[j][i] (with i != j)

## What is the modulus (or norm) of a row?

The modulus or norm of a vector (or a row in a matrix) is defined as the square root of the sum of the squares of its elements. It has nothing to do with the % symbol, which is typically used for the remainder operator in programming languages like C.

So, when we talk about normalizing a row, we mean:

For each row of the matrix, calculate the norm (modulus) of the row as:

norm = √(a₁² + a₂² + ... + aₙ²)

where a₁, a₂, ..., aₙ are the elements of the row.

Then, divide each element of the row by its norm (modulus) so that the sum of the squares of the elements of the normalized row becomes 1.

### Step-by-step example:
Take a generic row with two elements:

{a₁, a₂}

The norm of the row is calculated as:

norm = √(a₁² + a₂²)

Then, to normalize the row, we divide each element of the row by this norm:

normalized row = { a₁ / norm, a₂ / norm }

---

## Why is this important?

Normalizing the rows of a matrix serves several important purposes in various mathematical, computational, and data analysis contexts, particularly in **machine learning**. Here are the key reasons why this operation is useful:

1. **Uniformity of scale across rows**:
   When working with matrices, especially in machine learning contexts, the rows of the matrix (which may represent samples, observations, or data points) may have very different scales. For example, one row might contain numbers in the hundreds, while another contains numbers in the tens. Normalization ensures that each row contributes equally to the calculations, preventing rows with larger values from having a disproportionately large impact.

2. **Preprocessing for machine learning**:
   In machine learning, normalizing rows (or columns, depending on the case) is a common practice. Many machine learning models, such as neural networks or regression models, perform better when the data is normalized. This is because normalization reduces the possibility that variables with larger values will disproportionately influence the model’s training process.

   **Example**: If you're trying to predict an outcome (such as the price of a house) based on features like "size" (which could be in the hundreds of square meters) and "number of rooms" (which might be a much smaller number, say between 1 and 10), the model might "give more importance" to the size simply because it has larger numerical values. Normalizing these features helps avoid this issue.

3. **Numerical optimization**:
   Normalization can improve the numerical stability of various algorithms, particularly those involving the solving of linear systems or optimization techniques (such as gradient descent). Working with normalized data helps avoid issues related to extremely large or small numbers, which could lead to instability in the calculations.

4. **Improved convergence of algorithms**:
   In many machine learning and statistical algorithms, normalizing rows or columns can speed up the convergence of optimization algorithms (like gradient descent). For instance, if you're using gradient descent to optimize an objective function, gradients of normalized variables tend to have similar magnitudes, making the optimization process faster and more stable.

5. **Making data more interpretable**:
   Normalizing data also makes the results easier to interpret. For example, in data analysis or research, it might be helpful to compare rows representing different experiments or observations that are on different scales. Normalization reduces this problem, allowing for a more direct comparison of the relative effects of each variable or element.

6. **Applications in other fields**:
   Normalization is also used in other areas such as:
   - **Computer vision**: When preprocessing images (especially in deep learning), images are often normalized to ensure they have the same range of pixel values.
   - **Signal processing**: To compare signals with different lengths or amplitudes, it's common to normalize them before applying further operations.

### In summary:
Normalizing the rows of a matrix has numerous practical applications, particularly in machine learning, data analysis, and numerical operations. It helps reduce variance between data, improves the numerical stability of algorithms, accelerates convergence, and makes data more interpretable.

## 🧬 Conway's Game of Life

Conway's algorithm, also known as the **"Game of Life,"** is a cellular automaton devised by British mathematician **John Horton Conway** in 1970.  
It is an example of a discrete dynamical system that simulates the evolution of a population of cells on a two-dimensional grid.  
The rules of the game are simple, yet they can produce complex and unpredictable behavior.

### 🧩 Rules of the Game of Life

- **Survival:** A living cell with 2 or 3 neighboring living cells stays alive.  
- **Death by underpopulation:** A living cell with fewer than 2 neighboring living cells dies.  
- **Death by overpopulation:** A living cell with more than 3 neighboring living cells dies.  
- **Birth:** A dead cell with exactly 3 neighboring living cells becomes alive.

