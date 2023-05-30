#include <stdio.h>

int
main (void)
{
    const long long int a = 1;
    const long int b = 2;
    const int c = 3;
    const short int d = 4;
    const char e = 5;
    const unsigned long long int f = 6;
    const unsigned long int g = 7;
    const unsigned int h = 8;
    const unsigned short int i = 9;
    const unsigned char j = 10;
    const float k = 11.0;
    const double l = 12.0;
    const long double m = 13.0;

    //printf("a = %lld e' %d byte\n", a, sizeof(a));
    printf("b = %ld e' %d byte\n", b, sizeof(b));
    printf("c = %d e' %d byte\n", c, sizeof(c));
    printf("d = %hd e' %d byte\n", d, sizeof(d));
    printf("e = %d e' %d byte\n", e, sizeof(e));
    //printf("f = %llu e' %d byte\n", f, sizeof(f));
    printf("g = %lu e' %d byte\n", g, sizeof(g));
    printf("h = %u e' %d byte\n", h, sizeof(h));
    printf("i = %hu e' %d byte\n", i, sizeof(i));
    printf("j = %u e' %d byte\n", j, sizeof(j));
    printf("k = %f e' %d byte\n", k, sizeof(k));
    printf("l = %lf e' %d byte\n", l, sizeof(l));
    //printf("m = %Lf e' %d byte\n", m, sizeof(m));

    return (0);
}