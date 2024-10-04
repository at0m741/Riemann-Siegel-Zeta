#include "include.h"



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
