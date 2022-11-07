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

    static Matrix4 translate(const Vec3& v);
    static Matrix4 scale(const Vec3& v);
    static Matrix4 rotate(Axis axis, double angle);

    Matrix4 operator*(const Matrix4& rhs) const;
    Vec4 operator*(const Vec4& rhs) const;

private:
    std::array<Vec4, 4> mat;
};