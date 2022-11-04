#include "Line.h"

Line::Line(){}

Line::Line(double x1, double y1, double z1, double x2, double y2, double z2) 
{
    p1 = Vec3(x1, y1, z1);
    p2 = Vec3(x2, y2, z2);
}

Line::Line(const Vec3 &_p1, const Vec3 &_p2)
{
    p1 = Vec3(_p1);
    p2 = Vec3(_p2);
}

Line::Line(const Vec3 &&_p1, const Vec3 &&_p2)
{
    p1 = Vec3(_p1);
    p2 = Vec3(_p2);
}

Vec3 Line::getp1() const { return p1; }

Vec3 Line::getp2() const { return p2; }
