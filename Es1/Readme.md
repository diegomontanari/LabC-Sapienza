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

To find the square root of a number \( z \), these two specific functions are widely used:

![6273A2B1-341B-4D43-A614-E233E5D95E7D_4_5005_c](https://github.com/user-attachments/assets/42ca18ab-430f-4dcd-8393-f472fc5f6de5) ![3BBDC5E1-3ED7-428C-A3F1-A2635E7E57E8_4_5005_c](https://github.com/user-attachments/assets/ed02a2a5-2619-46b7-b719-de0d3691ee69)

**Babylonian method (1st one):**

- **Fast and converges quickly**.
- Involves a division in each iteration, which can be more **costly when dealing with very large integers**.

**Alternative method (2nd one):**

- Avoids division and uses only multiplications.
-**Faster for very large numbers**, especially on hardware where division is slower than multiplication.

In the case of very large integers, the version that uses only multiplications (without division) can be more advantageous.

In general, it is true that division is more computationally expensive than multiplication, especially when working with very large integers, however, the actual effectiveness also depends on the specific hardware architecture used for the calculations.

**Example of the Babylonian method:**

![5E86C0F8-9A8B-4197-8A53-21F3CAC1EBC1](https://github.com/user-attachments/assets/f09ec5cd-63a0-4207-b008-c049c1646a3e)
![85DCA0B9-8ED4-435C-A824-BF9F7E932AAF](https://github.com/user-attachments/assets/e95a9493-ebc5-4374-8d68-a5ffb16cf0f3)
![CD589EBC-C673-4437-9E21-488DF9BBA710](https://github.com/user-attachments/assets/a956e5f2-504e-49ed-aaa2-a6098667299b)
![65C68697-798A-48AB-BEF5-D201269BF32E](https://github.com/user-attachments/assets/0dbe3051-4e27-49ad-9014-e0845686730b)

