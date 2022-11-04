#include "Vec4.h"

Vec4::Vec4()
{
    x = y = z = w = 0;
}

Vec4::Vec4(double _x, double _y, double _z, double _w) : x(_x), y(_y), z(_z), w(_w) {}

double Vec4::magnitude() const
{
    return sqrt(x*x + y*y + z*z + w*w);
}

Vec4 Vec4::operator+(const Vec4 &v) const 
{
    return Vec4(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vec4 Vec4::operator-(const Vec4 &v) const 
{
    return Vec4(x - v.x, y - v.y, z - v.z, w - v.w);
}

Vec4 Vec4::operator-() const 
{
    return Vec4(-x, -y, -z, -w);
}

Vec4::operator Vec3() const
{
    return Vec3(x, y, z);
}

Vec4 Vec4::operator*(double s) const
{
    return Vec4(s*x, s*y, s*z, s*w);
}

double Vec4::operator[](int index) const
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
    case 3:
        return w;
        break;
    
    default:
        return NAN;
        break;
    }
}