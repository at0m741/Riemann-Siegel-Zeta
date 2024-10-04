#include "include.h"


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
    static const long double coefficients[][MAX_TERMS] = {
        {0.38268343236508977173L, 0.43724046807752044936L, 0.13237657548034352332L, -0.01360502604767418865L, -0.01356762197010358089L, 
         -0.00162372532314446528L, 0.00029705353733379691L, 0.00007943300879521470L, 0.00000046556124614505L, -0.00000143272516309551L, 
         -0.00000010354847112313L, 0.00000001235792708386L, 0.00000000178810838580L, -0.00000000003391414390L, -0.00000000001632663390L, 
         -0.00000000000037851094L, 0.00000000000009327423L, 0.00000000000000522184L, -0.00000000000000033507L, -0.00000000000000003412L, 
         0.00000000000000000058L, 0.00000000000000000015L}, 
        {-0.02682510262837534703L, 0.01378477342635185305L, 0.03849125048223508223L, 0.00987106629906207647L, -0.00331075976085840433L,
         -0.00146478085779541508L, -0.00001320794062487696L, 0.00005922748701847141L, 0.00000598024258537345L, -0.00000096413224561698L, 
         -0.00000018334733722714L, 0.00000000446708756272L, 0.00000000270963508218L, 0.00000000007785288654L, -0.00000000002343762601L, 
         -0.00000000000158301728L, 0.00000000000012119942L, 0.00000000000001458378L},
        {0.00518854283029316849L, 0.00030946583880634746L, -0.01133594107822937338L, 0.00223304574195814477L, 0.00519663740886233021L, 
         0.00034399144076208337L, -0.00059106484274705828L, -0.00010229972547935857L, 0.00002088839221699276L, 0.00000592766549309654L, 
         -0.00000016423838362436L, -0.00000015161199700941L},
        {-0.00133971609071945690L, 0.00374421513637939370L, -0.00133031789193214681L, -0.00226546607654717871L, 0.00095484999985067304L, 
         0.00060100384589636039L, -0.00010128858286776622L, -0.00006865733449299826L, 0.00000059853667915386L, 0.00000333165985123995L, 
         0.00000021919289102435L}
    };

    if (n >= 0 && n <= 3) {
        return evaluate_series(n, z, coefficients[n], MAX_TERMS);
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
    long double ZZ = 0.0L;
    long double R = 0.0L;
    int N = sqrtl(t / (2.0L * pi));
    long double p = sqrtl(t / (2.0L * pi)) - N;
    long double tt = theta(t);

    #pragma omp parallel for reduction(+:ZZ)
    for (int j = 1; j <= N; ++j) {
        ZZ += 1.0L / sqrtl((long double) j) * cosl(fmodl(tt - t * logl((long double) j), 2.0L * pi));
    }
    ZZ *= 2.0L;

    for (int k = 0; k <= n; ++k) {
        R += C(k, 2.0L * p - 1.0L) * powl(2.0L * pi / t, ((long double)k) * 0.5L);
    }

    R = even(N - 1) * powl(2.0L * pi / t, 0.25L) * R;
    return (ZZ + R) * 0.1L;
}
