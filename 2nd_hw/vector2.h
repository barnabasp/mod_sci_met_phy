#include <iostream>
template<typename T>
class Vector2
{
    public:
        Vector2();
        Vector2(T a, T b);
        void setX(T newX);
        void setY(T newY);
        double dot(const Vector2<T>& a, const Vector2<T>& b);
        double length(const Vector2<T>& a);
        double sqlength(const Vector2<T>& a);
        Vector2<T> norm(const Vector2<T>& a);

        Vector2<T> operator-(Vector2<T>& a)
        {
            return Vector2<T>(x - a.x, y - a.y);
        };
        Vector2<T> operator+(const Vector2<T>& a)
        {
            return Vector2<T>(x + a.x, y + a.y);
        };
        Vector2<T> operator/=(T a)
        {
            return Vector2<T>(x/a, y/a);
        }
        friend std::ostream& operator<<(std::ostream& stream, const Vector2<T>& a)
        {
            stream << a.x << " " << a.y;
            return stream;
        };
        friend std::istream& operator>>(std::istream& stream, const Vector2<T>& a)
        {
            stream >> a.x;
            stream >> a.y;
            return stream;
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
double dot(const Vector2<T>& a, const Vector2<T>& b)
{
    return a.x * b.y + a.y * b.x;
}
template<typename T>
double length(const Vector2<T>& a)
{
    return sqrt(a.x*a.x + a.y * a.y);
}
template<typename T>
double sqlength(const Vector2<T>& a)
{
    return a.x*a.x + a.y*a.y;
}
template<typename T>
Vector2<T> normalize(const Vector2<T>& a)
{
    return a/Vector2<T>::length(a);
}