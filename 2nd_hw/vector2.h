#include <iostream>
template<typename T>
class Vector2
{
    public:
        Vector2();
        Vector2(T a, T b);
        void setX(T newX);
        void setY(T newY);
        Vector2<T> operator-(Vector2<T>& a)
        {
            return Vector2<T>(x - a.x, y - a.y);
        };
        Vector2<T> operator+(const Vector2<T>& a)
        {
            return Vector2<T>(x + a.x, y + a.y);
        };
        friend std::ostream& operator<<(std::ostream& stream, const Vector2<T>& a)
        {
            stream << a.x << " " << a.y;
            return stream;
        };
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
void Vector2<T>::setX(T newX)
{
    x = newX;
}
template<typename T>
void Vector2<T>::setY(T newY)
{
    y = newY;
}