**Calculate GCD**: Use **Euclidean Algorithm**.  
**Calculate LCM**: Use the formula:

\[
LCM(a,b) = \frac{|a \cdot b|}{GCD(a,b)}
\]

# Euclidean Algorithm for GCD

The **Euclidean Algorithm** efficiently computes the **Greatest Common Divisor (GCD)** of two integers. The GCD is the largest number that divides both integers without a remainder.

## How It Works

It follows this mathematical relation:

\[
GCD(a, b) = GCD(b, a \mod b)
\]

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

