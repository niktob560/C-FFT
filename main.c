#include <stdio.h>
#include <stdint.h>
#include <complex.h>
#include <math.h>

#define M_PI 3.141592653589793
#define M_E 2.718281828459045

#define NN 2200
#define FS 22000.0

double sig1(const uint32_t n)
{
    return cos((2 * M_PI * 1400.0 * n) / FS + (M_PI / 4)) + 2 * cos(((2 * M_PI * 10000.0 * n) / FS) + (M_PI / 2)) + cos(((2 * M_PI * 14000.0 * n) / FS) + (M_PI / 2));
}

complex double Wn(const uint32_t N)
{
    return cexp(-2 * M_PI * I / N);
}

complex double Xm(const uint32_t m)
{
    complex double ret = 0,
                   ret2 = 0;
    uint32_t n;
    complex double Wn2m = cpow(Wn(NN / 2), m),
                   Wnm = cpow(Wn(NN), m);
    for (n = 0; n < NN / 2; n++)
    {
        ret += sig1(2 * n) * cpow(Wn2m, n);
    }
    for (n = 0; n < NN / 2; n++)
    {
        ret2 += sig1(2 * n + 1) * cpow(Wn2m, n);
    }
    ret2 *= Wnm;

    return ret + ret2;
}

int main()
{
    uint32_t i;
    complex double x;
    for (i = 0; i < NN; i++)
    {
        x = Xm(i);
        printf("%f %f\n", i * FS / NN, 2 * cabs(x) / NN);
    }
    return 0;
}