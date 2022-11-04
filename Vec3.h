#pragma once
#include <cmath>
#include "Vec2.h"
#include "Vec4.h"

class Vec4;
class Vec2;

class Vec3
{
public:
    Vec3();
    Vec3(double _x, double _y, double _z);

    double magnitude() const;

    static Vec3 dotProd(const Vec3 &v1, const Vec3 &v2);
    static Vec3 crossProd(const Vec3 &v1, const Vec3 &v2);

    Vec3 operator+(const Vec3 &v) const;
    Vec3 operator-(const Vec3 &v) const;
    Vec3 operator-() const;
    operator Vec2() const;
    operator Vec4() const;
    double operator[](int index) const;

    double x, y, z;
};
