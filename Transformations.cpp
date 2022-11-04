#include "Transformations.h"

Transformations::Transformations()
{
    init();
}

void Transformations::init()
{
    gradientSize = getSize(gradient);
    maxZ = 3 * gradientSize;

    updateWindowSize();
}

void Transformations::updateWindowSize()
{
    Screen::updateWindowSize();

    depthBuffer.reset(new double[bufferSize]);
    std::fill(depthBuffer.get(), &depthBuffer.get()[bufferSize - 1], maxZ);
}

void Transformations::clearFrame()
{
    Screen::clearFrame();

    std::fill(depthBuffer.get(), &depthBuffer.get()[bufferSize - 1], maxZ);
}

Vec3 Transformations::projection(const Vec3 &&point)
{
    if (!orthographic)
        return point;

    double coefficient = eyeDistance / (point.z + eyeDistance);

    return Vec3(point.x * coefficient, point.y * coefficient, point.z);
}

Vec3 Transformations::toScreenCoords(const Vec3 &&point)
{
    double x = point.x * screenWidth / aspectRatio + screenWidth / 2;
    double y = (point.y + 1) * screenHeight / 2;

    return Vec3(round(x), round(y), point.z);
}

bool Transformations::depthTest(int x, int y, double z)
{
    if (!testDepth)
        return true;

    if (z > maxZ || x < 0 || y < 0 || x > screenWidth || y > screenHeight)
        return false;

    double destZ = depthBuffer[y * screenWidth + x];
    depthBuffer[y * screenWidth + x] = fmin(z, destZ);

    return z <= destZ;
}

char Transformations::charFromGradient(double z)
{
    char c = ' ';
    if (z <= maxZ && z >= 0)
        c = gradient[(int)(z / 3)];

    return c;
}

void Transformations::enableDepthTest()
{
    testDepth = true;
}

void Transformations::disableDepthTest()
{
    testDepth = false;
}

void Transformations::enableOrtho()
{
    orthographic = true;
}

void Transformations::disableOrtho()
{
    orthographic = false;
}

bool Transformations::setEyeDistance(double dist)
{
    if (dist <= 0)
        return false;

    eyeDistance = dist;
    return true;
}

Line Transformations::transform(const Line &line, const Matrix4 &matrix)
{
    Vec3 p1 = (Vec3)(matrix * (Vec4)line.getp1());
    Vec3 p2 = (Vec3)(matrix * (Vec4)line.getp2());

    return Line(p1, p2);
}

Triangle Transformations::transform(const Triangle &triangle, const Matrix4& matrix)
{
    Vec3 p1 = (Vec3)(matrix * (Vec4)triangle.pt1());
    Vec3 p2 = (Vec3)(matrix * (Vec4)triangle.pt2());
    Vec3 p3 = (Vec3)(matrix * (Vec4)triangle.pt3());
    
    return Triangle(p1, p2, p3);
}