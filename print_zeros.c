#include "include.h"

void print_zero(Zero z) {
    FILE *f = fopen("zeta.txt", "a");
	if (f == NULL) {
		printf("error opening file\n");
		exit(1);
	}
    if (z.t < 10.0) {
        fprintf(f, "%.6Lf\t%.6LE\n", z.t, z.z);
    } else if (z.t < 100.0) {
        fprintf(f, "%.5Lf\t%.5LE\n", z.t, z.z);
    } else if (z.t < 1000.0) {
        fprintf(f, "%.4Lf\t%.4LE\n", z.t, z.z);
    } else {
        fprintf(f, "%.3Lf\t%.3LE\n", z.t, z.z);
    }
    printf("t = %.6Lf, z = %.6LE\n", z.t, z.z);
    fclose(f);
}
