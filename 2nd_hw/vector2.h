#include <iostream>
template<typename T>
class Vector2
{
    public:
        Vector2();
        Vector2(T a, T b);
        void setX(T newX);
        void setY(T newY);
        T getX();
        T getY();
        void func(T a);
        Vector2<T> asd(Vector2<T> const& a, Vector2<T> const& b)
        {
            return Vector2<T>(a.getX() + b.getX(), a.getY() + b.getY());
        }
     private:
        T x;
        T y;
};
template<typename T>
Vector2<T>::Vector2(T a, T b)
{
    x = a;
    y = b;
}
template<typename T>
T Vector2<T>::getX()
{
    return x;
}
template<typename T>
T Vector2<T>::getY()
{
    return y;
}
template<typename T>
void Vector2<T>::setX(T newX)
{
    x = newX;
}
template<typename T>
void Vector2<T>::setY(T newY)
{
    y = newY;
}
template<typename T>
void Vector2<T>::func(T a)
{
    std::cout << "TEST: " << a << std::endl;
}