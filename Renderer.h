#pragma once

#include <sys/ioctl.h>
#include <memory>
#include <cmath>
#include <stdio.h>

#include "Line.h"
#include "Triangle.h"
#include "util.h"

class Renderer
{
public:

    Renderer();
    void updateWindowSize();

    void clearFrame();
    void drawFrame();

    void drawLine(const Line &line);
    void drawTriangle(const Triangle &triangle);
    void drawPoint2d(unsigned int x, unsigned int y, unsigned char c);


private:

    Vec3 triangularInterpolation(const Vec2 &p, const Triangle &t);
    char charFromGradient(double z);
    bool isInTriangle(const Vec2 &p, const Triangle &t);
    Vec3 projection(const Vec3 &&point);
    Vec3 toScreenCoords(const Vec3 &&point);
    bool depthTest(int x, int y, double z);


    bool testDepth = false;
    bool orthographic = false;

    double aspectRatio = 1;
    double eyeDistance = 1;
    double maxZ = 10;

    unsigned int screenWidth, screenHeight;
    unsigned int bufferSize;

    std::unique_ptr<char> screenBuffer;
    std::unique_ptr<double> depthBuffer;

    const char* gradient = "#$@&?=+!*^;:\"-,'.` ";
    size_t gradientSize;
};