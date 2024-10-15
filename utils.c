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
    long double half_t = t / 2.0L;
    long double inv_t = 1.0L / t;  
    long double log_term = logl(half_t / pi);  

    return (half_t * (log_term - 1.0L) - pi / 8.0L + inv_t / 48.0L + 7.0L * inv_t * inv_t * inv_t / 5760.0L);
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
