#pragma once
#include "Vec3.h"

class Vec3;

class Vec4
{
public:
    Vec4();
    Vec4(double _x, double _y, double _z, double _w);
    double magnitude() const;

    Vec4 operator+(const Vec4 &v) const;
    Vec4 operator-(const Vec4 &v) const;
    Vec4 operator-() const;
    operator Vec3() const;
    Vec4 operator*(double s) const;
    double operator[](int index) const;

private:
    double x, y, z, w;
};