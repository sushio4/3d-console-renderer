#include "Triangle.h"

Triangle::Triangle(const Vec3 (&points)[3]) : p1(points[0]), p2(points[1]), p3(points[2]) {}
Triangle::Triangle(const Vec3 &_p1, const Vec3 &_p2, const Vec3 &_p3) : p1(_p1), p2(_p2), p3(_p3) {}

Vec3 Triangle::pt1() const {return p1;}
Vec3 Triangle::pt2() const {return p2;}
Vec3 Triangle::pt3() const {return p3;}