#include "Vec2.h"

Vec2::Vec2()
{
    x = y = 0;
}

Vec2::Vec2(double _x, double _y) : x(_x), y(_y) {}

double Vec2::magnitude() const 
{
    return sqrt(x * x + y * y);
}

Vec2 Vec2::dotProd(const Vec2 &v1, const Vec2 &v2)
{
    return Vec2(v1.x * v2.x, v1.y * v2.y);
}

Vec3 Vec2::crossProd(const Vec2 &v1, const Vec2 &v2)
{
    return Vec3::crossProd((Vec3)v1, (Vec3)v2);
}

Vec2 Vec2::operator+(const Vec2 &v) const 
{
    return Vec2(x + v.x, y + v.y);
}

Vec2 Vec2::operator-(const Vec2 &v) const 
{
    return Vec2(x - v.x, y - v.y);
}

Vec2 Vec2::operator-() const 
{
    return Vec2(-x, -y);
}

Vec2::operator Vec3() const
{
    return Vec3(x, y, 0);
}

double Vec2::operator[](int index) const
{
    switch (index)
    {
    case 0:
        return x;
        break;
    case 1:
        return y;
        break;
    
    default:
        return NAN;
        break;
    }
}