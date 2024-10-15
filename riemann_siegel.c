#include "include.h"
#include <math.h>

/*
 * The function C computes the Riemann-Siegel series C(n, z) for n = 0, 1, 2, 3.
 * The Riemann-Siegel series is a polynomial series of the form
 * C(n, z) = a[0] + a[1] * z + a[2] * z^2 + ... + a[n] * z^n
 * where a[0], a[1], ..., a[n] are the coefficients of the series.
 * The coefficients of the Riemann-Siegel series are stored in the array coefficients.
 * The function evaluate_series is used to evaluate the series at the point z.
 * The function returns the value of the series at the point z.
*/


long double C(int n, long double z) {
    long double z2 = z * z;
    long double z4 = z2 * z2;
    long double z6 = z4 * z2;
    long double z8 = z4 * z4;

    if (n == 0) {
        return (0.38268343236508977173L +
                0.43724046807752044936L * z2 +
                0.13237657548034352332L * z4 -
                0.01360502604767418865L * z6 -
                0.01356762197010358089L * z8 -
                0.00162372532314446528L * powl(z, 10.0L) +
                0.00029705353733379691L * powl(z, 12.0L) +
                0.00007943300879521470L * powl(z, 14.0L) +
                0.00000046556124614505L * powl(z, 16.0L) -
                0.00000143272516309551L * powl(z, 18.0L) -
                0.00000010354847112313L * powl(z, 20.0L) +
                0.00000001235792708386L * powl(z, 22.0L) +
                0.00000000178810838580L * powl(z, 24.0L) -
                0.00000000003391414390L * powl(z, 26.0L) -
                0.00000000001632663390L * powl(z, 28.0L) -
                0.00000000000037851093L * powl(z, 30.0L) +
                0.00000000000009327423L * powl(z, 32.0L) +
                0.00000000000000522184L * powl(z, 34.0L) -
                0.00000000000000033507L * powl(z, 36.0L) -
                0.00000000000000003412L * powl(z, 38.0L) +
                0.00000000000000000058L * powl(z, 40.0L) +
                0.00000000000000000015L * powl(z, 42.0L));
    }
    else if (n == 1) {
        return (-0.02682510262837534703L * z +
                0.01378477342635185305L * z2 * z +
                0.03849125048223508223L * z4 * z +
                0.00987106629906207647L * z6 * z -
                0.00331075976085840433L * powl(z, 9.0L) -
                0.00146478085779541508L * powl(z, 11.0L) -
                0.00001320794062487696L * powl(z, 13.0L) +
                0.00005922748701847141L * powl(z, 15.0L) +
                0.00000598024258537345L * powl(z, 17.0L) -
                0.00000096413224561698L * powl(z, 19.0L) -
                0.00000018334733722714L * powl(z, 21.0L) +
                0.00000000446708756272L * powl(z, 23.0L) +
                0.00000000270963508218L * powl(z, 25.0L) +
                0.00000000007785288654L * powl(z, 27.0L) -
                0.00000000002343762601L * powl(z, 29.0L) -
                0.00000000000158301728L * powl(z, 31.0L) +
                0.00000000000012119942L * powl(z, 33.0L) +
                0.00000000000001458378L * powl(z, 35.0L) -
                0.00000000000000028786L * powl(z, 37.0L) -
                0.00000000000000008663L * powl(z, 39.0L) -
                0.00000000000000000084L * powl(z, 41.0L) +
                0.00000000000000000036L * powl(z, 43.0L));
    }
    else if (n == 2) {
        return (0.00518854283029316849L +
                0.00030946583880634746L * z2 -
                0.01133594107822937338L * z4 +
                0.00223304574195814477L * z6 +
                0.00519663740886233021L * z8 +
                0.00034399144076208337L * powl(z, 10.0L) -
                0.00059106484274705828L * powl(z, 12.0L) -
                0.00010229972547935857L * powl(z, 14.0L) +
                0.00002088839221699276L * powl(z, 16.0L) +
                0.00000592766549309654L * powl(z, 18.0L) -
                0.00000016423838362436L * powl(z, 20.0L) -
                0.00000015161199700941L * powl(z, 22.0L) -
                0.00000000590780369821L * powl(z, 24.0L) +
                0.00000000209115148595L * powl(z, 26.0L) +
                0.00000000017815649583L * powl(z, 28.0L) -
                0.00000000001616407246L * powl(z, 30.0L) -
                0.00000000000238069625L * powl(z, 32.0L) +
                0.00000000000005398265L * powl(z, 34.0L) +
                0.00000000000001975014L * powl(z, 36.0L) +
                0.00000000000000023333L * powl(z, 38.0L) -
                0.00000000000000011188L * powl(z, 40.0L));
    }
    else if (n == 3) {
        return (-0.00133971609071945690L * z +
                0.00374421513637939370L * z2 * z -
                0.00133031789193214681L * z4 * z -
                0.00226546607654717871L * z6 * z +
                0.00095484999985067304L * powl(z, 9.0L) +
                0.00060100384589636039L * powl(z, 11.0L) -
                0.00010128858286776622L * powl(z, 13.0L) -
                0.00006865733449299826L * powl(z, 15.0L) +
                0.00000059853667915386L * powl(z, 17.0L) +
                0.00000333165985123995L * powl(z, 19.0L));
    }

    return 0.0L;
}


/*
 * The function Z computes the Riemann-Siegel Z function for a given value of t.
 * The Riemann-Siegel Z function is given by
 * Z(t) = 2 * sum(j = 1 to N) 1 / sqrt(j) * cos(theta(t) - t * log(j))
 * where N = sqrt(t / 2 * pi) and theta(t) is the Riemann-Siegel theta function.
 * The function also computes the Riemann-Siegel R function, which is given by
 * R(t) = sum(k = 0 to n) C(k, 2 * p - 1) * (2 * pi / t)^(k / 2)
 * where C(k, z) is the Riemann-Siegel series and p = sqrt(t / 2 * pi) - N.
 * The function returns the value of the Riemann-Siegel Z function at the point t.
*/



long double Z(long double t, int n) {

    const long double pi = 3.1415926535897932385L;
    const long double two_pi = 2.0L * pi;  
    long double ZZ = 0.0L, R = 0.0L, p, tt, sqrt_term, log_term, cos_term;
    int j, k, N;
    
    sqrt_term = sqrtl(t / two_pi);  
    N = (int) sqrt_term;  
    p = sqrt_term - (long double) N;  
    tt = theta(t); 

    long double sqrt_j, cos_val;
    for (j = 1; j <= N; ++j) {
        sqrt_j = 1.0L / sqrtl((long double)j); 
        log_term = tt - t * logl((long double)j); 
        cos_val = cosl(fmodl(log_term, two_pi)); 
        ZZ += sqrt_j * cos_val;  
    }
    ZZ *= 2.0L;  

    long double pow_term, C_val;
    long double pow_two_pi_t = sqrtl(two_pi / t);  
    for (k = 0; k <= n; ++k) {
        pow_term = powl(two_pi / t, ((long double)k) * 0.5L);  
        C_val = C(k, 2.0L * p - 1.0L); 
        R += C_val * pow_term;  
    }

    R *= even(N - 1) * powl(two_pi / t, 0.25L);

    // Return final result
    return ZZ + R;
}

