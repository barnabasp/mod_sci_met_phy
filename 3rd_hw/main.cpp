#include <iostream>
#include <cmath>

double func(double x, int F, double q, int a, int h)
{
    return F/q * (cosh(q/F * x) - cosh((q*a * 0.5 / F)) + h);
}

template<typename T>
double df(T f, double x, double dx, double F, double q, double a, double h)
{
    // df = (16S(h)-S(2h))/15 + O(h^6)
    // S(h) = (4D(h) - D(2h))/3
    // S(2h) = (4D(2h) - D(4h))/3
    // D(h) = (f(x + h) - f(x - h))/2h
    return (16 * ( 4 * (f(x + dx, F, q, a, h) - f(x - dx, F, q, a, h)) - (f(x + 2*dx, F, q, a, h) - f(x - 2*dx,F, q, a, h)))
                - 1 * (4 * (f(x + 2*dx, F, q, a, h) - f(x - 2*dx,F, q, a, h)) - (f(x + 4*dx, F, q, a, h) - f(x - 4*dx,F, q, a, h))))/15 ;
}

int main()
{
    //Starting values
    const int F = 900;
    const double q = 1.8;
    const int a = 200;
    const int h = 35;
    //Limits and n
    const double min = 0.0;
    const double max = 200.0;
    const int n = 1000;
    return 0;
}
