#include <iostream>
#include <cmath>

double func(double x, int F, double q, int a, int h)
{
    return F/q * (cosh(q/F * x) - cosh((q*a * 0.5 / F)) + h);
}

int main()
{
    int F = 900;
    double q = 1.8;
    int a = 200;
    int h = 35;
    std::cout<<func(1,2,3) << std::endl;
}
