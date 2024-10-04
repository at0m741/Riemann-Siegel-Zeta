#include "include.h"

/*
 * The function even returns 1 if n is even and -1 if n is odd.
 * This function is used to determine the sign of the Riemann-Siegel theta function.
*/

int even(int n) {
    return ((n % 2 == 0) * 2 - 1);
}

long double theta(long double t) {
    const long double pi = 3.1415926535897932385L;
    return (t / 2.0L * logl(t / 2.0L / pi) - t / 2.0L - pi / 8.0L + 1.0L / 48.0L / t + 7.0L / 5760.0L / t / t / t);
}

long double evaluate_series(int n, long double z, const long double *coefficients, int length) {
    long double result = 0.0L;
    for (int i = 0; i < length; i++) {
        result += coefficients[i] * powl(z, i);
    }
    return result;
}

long double f_abs(long double a) {
    return fabsl(a);
}

int compare(const void *a, const void *b) {
    Zero *zeroA = (Zero *)a;
    Zero *zeroB = (Zero *)b;
    if (zeroA->t < zeroB->t) return -1;
    if (zeroA->t > zeroB->t) return 1;
    return 0;
}
