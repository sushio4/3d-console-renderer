#pragma once
#include "Point.h"

class Line
{
public:
    Line();
    Line(const Vec3 &_p1, const Vec3 &_p2);
    Line(const Vec3 &&_p1, const Vec3 &&_p2);
    Line(const double _x1, double _y1, double _z1, double _x2, double _y2, double _z2);
    Line(const double (&&points)[]);
    Vec3 getp1() const;
    Vec3 getp2() const;

private:
    Vec3 p1, p2;
};