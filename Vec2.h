#pragma once
#include <cmath>
#include "Vec3.h"

class Vec3;

class Vec2
{
public:
    Vec2();
    Vec2(double _x, double _y);
    double magnitude() const;

    static Vec2 dotProd(const Vec2 &v1, const Vec2 &v2);
    static Vec3 crossProd(const Vec2 &v1, const Vec2 &v2);

    Vec2 operator+(const Vec2 &v) const;
    Vec2 operator-(const Vec2 &v) const;
    Vec2 operator-() const;
    operator Vec3() const;
    double operator[](int index) const;

    double x, y;
};