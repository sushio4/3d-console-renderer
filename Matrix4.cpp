#include "Matrix4.h"

Matrix4::Matrix4()
{
    mat[0] = Vec4(1, 0, 0, 0);
    mat[1] = Vec4(0, 1, 0, 0);
    mat[2] = Vec4(0, 0, 1, 0);
    mat[3] = Vec4(0, 0, 0, 1);
}

Matrix4::Matrix4(std::array<Vec4, 4> array)
{
    mat = array;
}

Matrix4::Matrix4(Vec4 v0, Vec4 v1, Vec4 v2, Vec4 v3)
{
    mat[0] = v0;
    mat[1] = v1;
    mat[2] = v2;
    mat[3] = v3;
}

Matrix4 Matrix4::operator*(const Matrix4 &rhs) const
{
    std::array<Vec4, 4> res;
    res[0] = rhs.mat[0] * mat[0][0] + rhs.mat[1] * mat[0][1] + rhs.mat[2] * mat[0][2] + rhs.mat[3] * mat[0][3];
    res[1] = rhs.mat[0] * mat[1][0] + rhs.mat[1] * mat[1][1] + rhs.mat[2] * mat[1][2] + rhs.mat[3] * mat[1][3];
    res[2] = rhs.mat[0] * mat[2][0] + rhs.mat[1] * mat[2][1] + rhs.mat[2] * mat[2][2] + rhs.mat[3] * mat[2][3];
    res[3] = rhs.mat[0] * mat[3][0] + rhs.mat[1] * mat[3][1] + rhs.mat[2] * mat[3][2] + rhs.mat[3] * mat[3][3];
    return Matrix4(res);
}

Vec4 Matrix4::operator*(const Vec4 &rhs) const
{
    return Vec4(mat[0][0] * rhs[0] + mat[0][1] * rhs[1] + mat[0][2] * rhs[2] + mat[0][3] * rhs[3],
                mat[1][0] * rhs[0] + mat[1][1] * rhs[1] + mat[1][2] * rhs[2] + mat[1][3] * rhs[3],
                mat[2][0] * rhs[0] + mat[2][1] * rhs[1] + mat[2][2] * rhs[2] + mat[2][3] * rhs[3],
                mat[3][0] * rhs[0] + mat[3][1] * rhs[1] + mat[3][2] * rhs[2] + mat[3][3] * rhs[3]);
}

Matrix4 Matrix4::rotate(Axis axis, double angle)
{
    Vec4 v0 = Vec4(1, 0, 0, 0);
    Vec4 v1 = Vec4(0, 1, 0, 0);
    Vec4 v2 = Vec4(0, 0, 1, 0);
    Vec4 v3 = Vec4(0, 0, 0, 1);

    double sina = sin(angle);
    double cosa = cos(angle);

    switch (axis)
    {
    case x:
        v1 = Vec4(0, cosa, -sina, 0);
        v2 = Vec4(0, sina, cosa, 0);
        break;

    case y:
        v0 = Vec4(cosa, 0, sina, 0);
        v2 = Vec4(-sina, 0, cosa, 0);
        break;

    case z:
        v0 = Vec4(cosa, -sina, 0, 0);
        v1 = Vec4(sina, cosa, 0, 0);
        break;
    }

    return Matrix4(v0, v1, v2, v3);
}

Matrix4 Matrix4::translate(const Vec3 &v)
{
    Vec4 v0(1, 0, 0, v.x);
    Vec4 v1(0, 1, 0, v.y);
    Vec4 v2(0, 0, 1, v.z);
    Vec4 v3(0, 0, 0, 1);
    return Matrix4(v0, v1, v2, v3);
}

Matrix4 scale(const Vec3 &v)
{
    Vec4 v0(v.x, 0, 0, 0);
    Vec4 v1(0, v.y, 0, 0);
    Vec4 v2(0, 0, v.z, 0);
    Vec4 v3(0, 0, 0, 1);
    return Matrix4(v0, v1, v2, v3);
}
