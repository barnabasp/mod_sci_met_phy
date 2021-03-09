#include <iostream>
/*
Newton iterator based on: https://en.wikipedia.org/wiki/Newton%27s_method

*/
bool stopIterate(double x1, double x0, double tol);
template<typename F, typename D, typename X, typename T, typename E>
//F type of function
//D type of derivative 
//X type of initial guess
//E type of precision (epsilon) for derivative
//T type of tolerance (accuracy)
X newtonIt(F f, D df, X x0, T tol, E eps)
{
    //newton iterator itself
    X x1 = x0 - f(x0)/df(x0);
    while(stopIterate(x1,x0,tol))
    {
        //if derivative is too small, stop ()
        if(abs(df(x0)) < eps) break;
        x0 = x1;
        x1 = x0 - f(x0)/df(x0);
    }
    return x1;
}
//Function to stop the iteration if difference is less than tolerance
bool stopIterate(double x1, double x0, double tol)
{
    return abs(x1-x0) > tol;
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
    double test = newtonIt(func,df,x0,1e-7,1e-15);
    std::cout.precision(25);
    std::cout << test << std::endl;
    double diff = test - 24.738633753705963298928;
    std::cout << diff << std::endl;
    return 0;
}