#include <iostream>
/*
Newton iterator based on: https://en.wikipedia.org/wiki/Newton%27s_method

*/
template<typename F, typename D, typename X>
//F type of function
//D type of derivative 
//X type of initial guess
X newtonIt(F f, D df, X x0)
{
    X x1 = x0 - f(x0)/df(x0);
    return x1;
}
double func(double x)
{
    return x*x - 612.0;
}
double df(double x)
{
    return 2.0*x;
}
int main() {
    double x0 = 10.0;
    double test = newtonIt(func,df,x0);
    std::cout << test;
    return 0;
}