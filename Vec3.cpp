#include "Vec3.h"

Vec3::Vec3()
{
    x = y = z = 0;
}

Vec3::Vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

double Vec3::magnitude() const
{
    return sqrt(x * x + y * y + z * z);
}

Vec3 Vec3::dotProd(const Vec3 &v1, const Vec3 &v2)
{
    return Vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

Vec3 Vec3::crossProd(const Vec3 &v1, const Vec3 &v2)
{
    return Vec3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

Vec3 Vec3::operator+(const Vec3 &v) const 
{
    return Vec3(x + v.x, y + v.y, z + v.z);
}

Vec3 Vec3::operator-(const Vec3 &v) const 
{
    return Vec3(x - v.x, y - v.y, z - v.z);
}

Vec3 Vec3::operator-() const 
{
    return Vec3(-x, -y, -z);
}

Vec3::operator Vec2() const
{
    return Vec2(x,y);
}

Vec3::operator Vec4() const
{
    return Vec4(x, y, z, 1);
}

double Vec3::operator[](int index) const
{
    switch (index)
    {
    case 0:
        return x;
        break;
    case 1:
        return y;
        break;
    case 2:
        return z;
        break;
    
    default:
        return NAN;
        break;
    }
}