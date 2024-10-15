# Riemann-Siegle-Zeta
This project computes the non-trivial zeros of the Riemann Zeta function using the **Riemann-Siegel formula**. The code leverages OpenMP for parallel computation and AVX2 for optimized performance, making it suitable for large-scale computations.

## Overview

The Riemann Zeta function, denoted as ζ(s), is one of the most important functions in number theory. Its zeros play a significant role in understanding the distribution of prime numbers. The **non-trivial zeros** of ζ(s) are located in the critical strip where the real part of s is between 0 and 1. The **Riemann Hypothesis** conjectures that all non-trivial zeros lie on the critical line, where Re(s) = 1/2.

The **Riemann-Siegel formula** is used in this project to compute the values of ζ(1/2 + it), for real values of t. This formula is efficient for computing values of ζ(s) at large heights on the critical line.

### Riemann-Siegel Formula

The Riemann-Siegel formula is an approximation for the zeta function on the critical line. For large values of `t`, it can be written as:
```math
Z(t) \approx 2 \sum_{n=1}^{N} \frac{1}{n^{1/2}} \cos\left( \theta(t) - t \log(n) \right)
```
