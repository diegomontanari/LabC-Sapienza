# Calculation of GCD and lcm (Italian MCD and mcm)

**Calculate GCD**: Use **Euclidean Algorithm**.  
**Calculate LCM**: Use the formula:

![3F7BDE10-990B-4A8F-B0C6-687294794AFA_4_5005_c](https://github.com/user-attachments/assets/5f4f41f1-1c25-4dce-a8a2-ca52f23bb791)


# Euclidean Algorithm for GCD

The **Euclidean Algorithm** efficiently computes the **Greatest Common Divisor (GCD)** of two integers. The GCD is the largest number that divides both integers without a remainder.

## How It Works

It follows this mathematical relation:

![1D9C7759-26D7-441A-9D37-3F700B11052F_4_5005_c](https://github.com/user-attachments/assets/b60d6b2d-eb11-4ef5-9f74-86c438ed1bc1)

where `%` is the remainder operator. The process repeats until `b` becomes `0`, at which point `a` is the GCD.

### Steps:
1. If `b == 0`, return `a` as the GCD.
2. Compute `a % b`.
3. Replace `a` with `b` and `b` with `a % b`.
4. Repeat until `b == 0`.

---

## Example: GCD of 48 and 18

1. \( 48 \mod 18 = 12 \)
2. \( 18 \mod 12 = 6 \)
3. \( 12 \mod 6 = 0 \) → **GCD is 6**.

\[
GCD(48, 18) = 6
\]

