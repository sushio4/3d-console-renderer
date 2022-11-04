#pragma once
#include <memory>
#include "Vec4.h"

class Matrix4
{
public:

    Matrix4();
    Matrix4(std::array<Vec4, 4> array);
    Matrix4(Vec4 v0, Vec4 v1, Vec4 v2, Vec4 v3);

    enum Axis{x, y, z};

    static Matrix4 translate(const Vec3& v)
    {
        Vec4 v0(1,0,0, v.x);
        Vec4 v1(0,1,0, v.y);
        Vec4 v2(0,0,1, v.z);
        Vec4 v3(0,0,0, 1);
        return Matrix4(v0, v1, v2, v3);
    }

    static Matrix4 scale(const Vec3& v)
    {
        Vec4 v0(v.x, 0, 0, 0);
        Vec4 v1(0, v.y, 0, 0);
        Vec4 v2(0, 0, v.z, 0);
        Vec4 v3(0, 0, 0, 1);
        return Matrix4(v0, v1, v2, v3);
    }

    static Matrix4 rotate(Axis axis, double angle)
    {
        Vec4 v0 = Vec4(1,0,0,0);
        Vec4 v1 = Vec4(0,1,0,0);
        Vec4 v2 = Vec4(0,0,1,0);
        Vec4 v3 = Vec4(0,0,0,1);
        
        double sina = sin(angle);
        double cosa = cos(angle);

        switch(axis)
        {
        case x:
            v1 = Vec4(0, cosa, -sina, 0);
            v2 = Vec4(0, sina,  cosa, 0);
            break;

        case y:
            v0 = Vec4( cosa, 0, sina, 0);
            v2 = Vec4(-sina, 0, cosa, 0);
            break;

        case z:
            v0 = Vec4(cosa, -sina, 0, 0);
            v1 = Vec4(sina,  cosa, 0, 0);
            break;
        }

        return Matrix4(v0, v1, v2, v3);
    }

    Matrix4 operator*(const Matrix4& rhs) const;
    Vec4 operator*(const Vec4& rhs) const;

private:
    std::array<Vec4, 4> mat;
};