#ifndef INCLUDE_H
#define INCLUDE_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define LOWER 0
#define UPPER 1000
#define NUMSAMPLES 215000
#define EPSILON 0.09E-2
#define REFINEMENT_STEPS 19
#define MAX_TERMS 26


typedef struct {
    long double t;
    long double z;
} __attribute__((aligned(16))) Zero;

long double C(int n, long double z);
long double Z(long double t, int n);
long double f_abs(long double a); 
int compare(const void *a, const void *b);
void refine_zeros(Zero *zeros, int zero_count);
void refine_and_group_zeros(Zero *zeros, int zero_count);
void print_zero(Zero z);
int even(int n);
long double theta(long double t);
long double evaluate_series(int n, long double z, const long double *coefficients, int length);


#endif
