#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

double func(double x, int F, double q, int a, int h)
{
    return F/q * (cosh(q/F * x) - cosh((q*a * 0.5 / F))) + h;
}

template<typename T>
double df(T f, double x, double dx, double F, double q, double a, double h)
{
    // df = (16S(h)-S(2h))/15 + O(h^6)
    // S(h) = (4D(h) - D(2h))/3
    // S(2h) = (4D(2h) - D(4h))/3
    // D(h) = (f(x + h) - f(x - h))/2h
    return    (16 * 8 * (f(x + dx, F, q, a, h) - f(x-dx, F, q, a, h) - f(x +2*dx, F, q, a, h) + f(x-2*dx, F, q, a, h))/ (12*dx)
              - 8 * (f(x + 2*dx, F, q, a, h) - f(x-2*dx, F, q, a, h) - f(x +2*2*dx, F, q, a, h) + f(x-2*2*dx, F, q, a, h))/ (12*2 *dx)) / 15;
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
    const int n = 10000;
    double dx = max/n;

    double M = 0.0;
    double T = 0.0;
    double S = 0.0;

    for(int ibin = 0; ibin < n; ibin++)
    {
        double dfuncMiddle = df( func, dx/2 + ibin * dx, dx,F, q, a, h );
        double dfuncTrap0 =  df( func, ibin * dx, dx, F, q, a , h);
        double dfuncTrap1 =  df( func, (ibin + 1) *dx, dx, F, q, a , h);
        M += sqrt(1 + dfuncMiddle * dfuncMiddle)*dx;
        T += ( sqrt(1 + dfuncTrap0 * dfuncTrap0) + sqrt(1 + dfuncTrap1 * dfuncTrap1)) * dx / 2;
    }
    S = (2*M + T)/3;
    
    std::cout<< "M: " << M << "\tT: " << T << "\tS: " << S << std::endl;
    std::ofstream outPut;
    outPut.open("3rd_hw_res.csv");
    outPut << "#M,T,S\n";
    outPut << M << "," << T << "," << S <<"\n";
    outPut.close();

    return 0;
}
