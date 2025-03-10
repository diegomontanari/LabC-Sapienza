# Calculation of GCD and lcm (Italian MCD and mcm)

**Calculate GCD**: Use **Euclidean Algorithm**.  
**Calculate LCM**: Use the formula:

![3F7BDE10-990B-4A8F-B0C6-687294794AFA_4_5005_c](https://github.com/user-attachments/assets/5f4f41f1-1c25-4dce-a8a2-ca52f23bb791)


### Euclidean Algorithm for GCD

The **Euclidean Algorithm** efficiently computes the **Greatest Common Divisor (GCD)** of two integers. The GCD is the largest number that divides both integers without a remainder.

#### How It Works

It follows this mathematical relation:

![1D9C7759-26D7-441A-9D37-3F700B11052F_4_5005_c](https://github.com/user-attachments/assets/b60d6b2d-eb11-4ef5-9f74-86c438ed1bc1)

where `%` is the remainder operator. The process repeats until `b` becomes `0`, at which point `a` is the GCD.

### Steps:
1. If `b == 0`, return `a` as the GCD.
2. Compute `a % b`.
3. Replace `a` with `b` and `b` with `a % b`.
4. Repeat until `b == 0`.

---

### Example: GCD of 48 and 18

1. \( 48 \mod 18 = 12 \)
2. \( 18 \mod 12 = 6 \)
3. \( 12 \mod 6 = 0 \) → **GCD is 6**.

\[
GCD(48, 18) = 6
\]



# Square Roots Using Newton's Iterative Method

Newton's method finds a single root of a function \( f(x) \) starting from an initial guess of the root. This method converges very quickly to the solution, requiring only a few operations per iteration and is computationally easy to implement (which is why it is used in various libraries, including the C Standard Library). It is based on the iteration expressed as:

![1FDF1BE4-1B26-4528-8DF2-00F8A1000FDE_4_5005_c](https://github.com/user-attachments/assets/2852e5a9-399e-4738-b1fc-fc38c2186322)

To find the square root of a number \( z \), two specific functions are widely used:

![6273A2B1-341B-4D43-A614-E233E5D95E7D_4_5005_c](https://github.com/user-attachments/assets/42ca18ab-430f-4dcd-8393-f472fc5f6de5) and: ![3BBDC5E1-3ED7-428C-A3F1-A2635E7E57E8_4_5005_c](https://github.com/user-attachments/assets/ed02a2a5-2619-46b7-b719-de0d3691ee69)

**Babylonian method (the first method):**

- Fast and converges quickly.
- Involves a division in each iteration, which can be more costly when dealing with very large integers.

**Alternative method:**

-Avoids division and uses only multiplications.
-Faster for very large numbers, especially on hardware where division is slower than multiplication.

In the case of very large integers, the version that uses only multiplications (without division) can be more advantageous.

In general, it is true that division is more computationally expensive than multiplication, especially when working with very large integers.
