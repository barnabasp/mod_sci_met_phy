#include <iostream>
template<typename T>
class Vector2
{
    public:
        Vector2();
        Vector2(T a, T b);
        T x;
        T y;
        Vector2<T> operator+=( Vector2<T> const& a)
        {
            x += a.x;
            y += a.y;
            return *this;
        }
        Vector2<T> operator-=(Vector2<T> const& a)
        {
            x -= a.x;
            y -= a.y;
            return *this;
        }
        Vector2<T> operator*=(T const& a)
        {
            x *= a;
            y *= a;
            return *this;
        }
        Vector2<T> operator/=(T const& a)
        {
            x /= a;
            y /= a;
            return *this;
        }
        friend std::ostream& operator<<(std::ostream& stream, Vector2<T> const& a)
        {
            stream << a.x << " " << a.y;
            return stream;
        };
        friend std::istream& operator>>(std::istream& stream, Vector2<T> const& a)
        {
            stream >> a.x;
            stream >> a.y;
            return stream;
        }
     private:
};
template<typename T>
Vector2<T>::Vector2(T a, T b)
{
    x = a;
    y = b;
}
template<typename T>
Vector2<T> operator-(Vector2<T> const& a, Vector2<T> const& b)
{
    return Vector2<T>(a.x - b.x, a.y - b.y);
}
template<typename T>
Vector2<T> operator+(Vector2<T> const& a, Vector2<T> const& b)
{
    return Vector2<T>(a.x + b.x, a.y + b.y);
}
template<typename T>
Vector2<T> operator*(T const& c, Vector2<T> const& a)
{
    return Vector2<T>(c * a.x, c * a.y);
}
template<typename T>
Vector2<T> operator*(Vector2<T> const& a, T const& c)
{
    return Vector2<T>(c * a.x, c * a.y);
}
template<typename T>
Vector2<T> operator/(Vector2<T> const& a, T const& c)
{
    return Vector2<T>(a.x / c, a.y / c);
}
template<typename T>
T dot(Vector2<T> const& a, Vector2<T> const& b)
{
    return (a.x * b.y + a.y * b.x);
}
template<typename T>
double sqlength(Vector2<T> const& a)
{
    return dot(a, a);
}
template<typename T>
double length(Vector2<T> const& a)
{
    return sqrt(sqlength(a,a));
}
template<typename T>
Vector2<double> normalize(Vector2<T> const& a)
{
    return Vector2<double>(a.x / length(a), a.y / length(a));
}