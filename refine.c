#include "include.h"
#define TOLERANCE 1e-10

long double brent_method(long double (*f)(long double), long double a, long double b, long double tol) {
    long double fa = f(a);
    long double fb = f(b);

    if (fa * fb >= 0) {
        printf("Function does not change sign over the interval\n");
        return -1; 
    }

    long double c = a, fc = fa, s, fs;
    long double d = b - a, e = d;
    
    while (f_abs(b - a) > tol) {
        if (fa != fc && fb != fc) {
            s = a * fb * fc / ((fa - fb) * (fa - fc)) +
                b * fa * fc / ((fb - fa) * (fb - fc)) +
                c * fa * fb / ((fc - fa) * (fc - fb));
        } else {
            s = b - fb * (b - a) / (fb - fa);
        }

        if (!((s > (3 * a + b) / 4 && s < b) ||
              (s < (3 * a + b) / 4 && s > a)) ||
            (f_abs(s - b) >= f_abs(b - c) / 2) ||
            (f_abs(b - c) < tol)) {
            s = (a + b) / 2; 
        }

        fs = f(s);
        d = c; c = b; fc = fb;

        if (fa * fs < 0) {
            b = s;
            fb = fs;
        } else {
            a = s;
            fa = fs;
        }

        if (f_abs(fa) < f_abs(fb)) {
            long double temp = a; a = b; b = temp;
            temp = fa; fa = fb; fb = temp;
        }
    }

    return b; 
}

long double Z_wrapper(long double t) {
    return Z(t, 16);  
}

void refine_zeros(Zero *zeros, int zero_count) {
    for (int i = 0; i < zero_count; i++) {
        long double a = zeros[i].t - 0.001L; 
        long double b = zeros[i].t + 0.001L; 
        zeros[i].t = brent_method(Z_wrapper, a, b, 1e-4);
        zeros[i].z = fabsl(Z(zeros[i].t, 7));
    }
}


void refine_and_group_zeros(Zero *zeros, int zero_count) {

    Zero refined_zeros[zero_count];
    int refined_count = 0;

    int i = 0;
    while (i < zero_count) {
        long double current_t = zeros[i].t;
        long double best_z = zeros[i].z;
        long double best_t = current_t;

        while (i < zero_count && ((long long)(zeros[i].t * 100.0L)) == ((long long)(current_t * 100.0L))) {
            if (zeros[i].z < best_z) {
                best_z = zeros[i].z;
                best_t = zeros[i].t;
            }
            i++;
        }

        refined_zeros[refined_count].t = best_t;
        refined_zeros[refined_count].z = best_z;
        refined_count++;
    }

    for (int j = 0; j < refined_count; j++) {
        print_zero(refined_zeros[j]);
    }
}
