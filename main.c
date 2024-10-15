#include "include.h"

long double find_zero(long double t_left, long double t_right, int max_iterations, long double tolerance) {
    long double mid, f_left, f_mid;
    f_left = Z(t_left, 4);

    for (int i = 0; i < max_iterations; i++) {
        mid = (t_left + t_right) / 2.0L;
        f_mid = Z(mid, 4);

        if (fabsl(f_mid) < tolerance) {
            return mid;
        }

        if ((f_left * f_mid) < 0.0L) {
            t_right = mid;
        } else {
            t_left = mid;
            f_left = f_mid;
        }
    }
    return mid;
}

int main() {
    long double t1 = LOWER, t2 = UPPER;
    long double t, s;
    int samples = NUMSAMPLES - 1;
    int sampleindex = 0;
    Zero zeros[NUMSAMPLES];
    int zero_count = 0;

    #pragma omp parallel for private(t, s, sampleindex)	schedule(dynamic)
    for (sampleindex = 0; sampleindex <= samples; ++sampleindex) {
        t = t1 + 1.0L * sampleindex / samples * (t2 - t1);
        s = f_abs(Z(t, 10));
        if (s < EPSILON && t > 1.0L) {
			#pragma omp critical
			{
                zeros[zero_count].t = t;
                zeros[zero_count].z = s;
                zero_count++;
			}
        }
    }
	samples *= 2;

    qsort(zeros, zero_count, sizeof(Zero), compare);

    refine_and_group_zeros(zeros, zero_count);
	refine_zeros(zeros, zero_count);

    return 0;
}
