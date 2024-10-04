#include "include.h"

int main() {
    long double t1 = LOWER, t2 = UPPER;
    long double t, s;
    int samples = NUMSAMPLES - 1;
    int sampleindex = 0;
    Zero zeros[NUMSAMPLES];
    int zero_count = 0;

    #pragma omp parallel for private(t, s, sampleindex)
    for (sampleindex = 0; sampleindex <= samples; ++sampleindex) {
        t = t1 + 1.0L * sampleindex / samples * (t2 - t1);
        s = f_abs(Z(t, 4));
        if (s < EPSILON && t > 1.0L) {
            #pragma omp critical
            {
                zeros[zero_count].t = t;
                zeros[zero_count].z = s;
                zero_count++;
            }
        }
    }

    qsort(zeros, zero_count, sizeof(Zero), compare);

    refine_and_group_zeros(zeros, zero_count);
	refine_zeros(zeros, zero_count);

    return 0;
}
