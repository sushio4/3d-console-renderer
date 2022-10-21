#include "Point.h"

class Triangle
{
public:
    Triangle(const Vec3 &_p1, const Vec3 &_p2, const Vec3 &_p3);
    Triangle(Vec3 &&_p1, Vec3 &&_p2, Vec3 &&_p3);
    Triangle(const Vec3 (&points)[3]);
    Triangle(Vec3 (&&points)[3]);

    Vec3 pt1() const;
    Vec3 pt2() const;
    Vec3 pt3() const;

private:
    Vec3 p1, p2, p3;
};