#include <cmath>
#pragma once

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

    double x, y, z;
};

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

    double x, y;
};