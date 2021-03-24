#include "vector2.h"

using namespace std;

int main()
{
    Vector2<int> v1(6,3);
    Vector2<int> v2(2,5);

    //Testing functions:
    cout << v1 << endl;
    cout << v2 << endl;
    int c = 5;
    v1+=v2;
    cout << "v1+=v2\t" << v1 << endl;
    v1-=v2;
    cout << "v1-=v2\t" << v1 << endl;
    v1*=10;
    cout << "v1*=10\t" <<  v1 << endl;
    v1/=10;
    cout << "v1/=10\t" << v1 << endl;
    //since we don't know exactly what's the type, best to use auto
    auto sum = v1 + v2;
    cout << "v1 + v2\t" << sum << endl;
    auto delta = v1 - v2;
    cout << "v1 - v2\t" << delta << endl;
    auto sMultiR = v1 * c;
    cout << "v1 * c\t" << sMultiR << endl;
    auto sMultiL = c * v1;
    cout << "c * v1\t" << sMultiL << endl;
    auto div = v1 / c;
    cout << "v1 / c\t" << div << endl;
    auto dotProd = dot(v1,v2);
    cout << "dot product v1, v2\t" << dotProd << endl;
    //double here, because vector is int, rounding
    double len = length(v1);
    cout << "length of v1\t" << len << endl;
    auto norm = normalize(v1);
    cout << "normalization of v1\t" << norm << endl;

    
}
