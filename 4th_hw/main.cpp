#include <iostream>
#include <fstream>  
#include <cmath>
#include <vector>

//main function
double f(double y)
{
    return 1 + y*y;
}
//Newton
template<typename F>
std::vector<double> Newton(F f, double dt, int t1, double y_0)
{
    std::vector<double> res(t1);
    res[0] = y_0;
    for(int iTime = 1; iTime < t1; iTime++)
    {
        res[iTime] = res[iTime - 1] + dt * f(res[iTime - 1]);
    }
    return res;
};
template<typename F>
std::vector<double> RK4(F f, double dt, int t1, double y_0)
{
    std::vector<double> res(t1);
    res[0] = y_0;
    double prev;
    double k1, k2, k3, k4;
    for(int iTime = 1; iTime < t1; iTime++)
    {
        prev = res[iTime - 1];
        k1 = f(prev);
        k2 = f(prev + dt * k1 / 2.0);
        k3 = f(prev + dt * k2 / 2.0);
        k4 = f(prev + dt * k3);
        res[iTime] = prev + dt * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        //std::cout << "k1: " << k1 << "\tk2: " << k2 << "\tk3: " << k3 << "\tk4: " << k4 << std::endl;
        //std::cout<<res[iTime] << std::endl;
    }
    return res;
}
std::vector<double> Analytic(double dt, int t1, double y_0)
{
    std::vector<double> res(t1);
    res[0] = y_0;
    for(int iTime = 1; iTime < t1; iTime++)
    {
        res[iTime] = tan(iTime * dt);
    }
    return res;
}
int main()
{
    double dt = 1e-4;
    double t1 = 10000;
    double y_0 = 0.0;
    
    std::vector< std::vector<double> > res;
    std::ofstream outPut;

    outPut.open("4th_hw_res.csv");
    res.resize(3, std::vector<double>(t1, 0));
    res[0] = Newton(f, dt, t1, y_0);
    res[1] = RK4(f, dt, t1, y_0);
    res[2] = Analytic(dt, t1, y_0);
    outPut << "#Newton,RK4,Analytical\n";
    for(int i; i < t1; i++)
    {
        outPut<<res[0][i] << ","<< res[1][i] << "," << res[2][i] << std::endl;
    }
    outPut.close();

    return 0;
}
