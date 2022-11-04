#include "Matrix4.h"

Matrix4::Matrix4()
{
    mat[0] = Vec4(1,0,0,0);
    mat[1] = Vec4(0,1,0,0);
    mat[2] = Vec4(0,0,1,0);
    mat[3] = Vec4(0,0,0,1);
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

Matrix4 Matrix4::operator*(const Matrix4& rhs) const
{
    std::array<Vec4, 4> res;
    res[0] = rhs.mat[0] * mat[0][0] + rhs.mat[1] * mat[0][1] + rhs.mat[2] * mat[0][2] + rhs.mat[3] * mat[0][3];
    res[1] = rhs.mat[0] * mat[1][0] + rhs.mat[1] * mat[1][1] + rhs.mat[2] * mat[1][2] + rhs.mat[3] * mat[1][3];
    res[2] = rhs.mat[0] * mat[2][0] + rhs.mat[1] * mat[2][1] + rhs.mat[2] * mat[2][2] + rhs.mat[3] * mat[2][3];
    res[3] = rhs.mat[0] * mat[3][0] + rhs.mat[1] * mat[3][1] + rhs.mat[2] * mat[3][2] + rhs.mat[3] * mat[3][3];
    return Matrix4(res);
}

Vec4 Matrix4::operator*(const Vec4& rhs) const
{
    return Vec4(mat[0][0] * rhs[0] + mat[0][1] * rhs[1] + mat[0][2] * rhs[2] + mat[0][3] * rhs[3],
                mat[1][0] * rhs[0] + mat[1][1] * rhs[1] + mat[1][2] * rhs[2] + mat[1][3] * rhs[3],
                mat[2][0] * rhs[0] + mat[2][1] * rhs[1] + mat[2][2] * rhs[2] + mat[2][3] * rhs[3],
                mat[3][0] * rhs[0] + mat[3][1] * rhs[1] + mat[3][2] * rhs[2] + mat[3][3] * rhs[3]);
}