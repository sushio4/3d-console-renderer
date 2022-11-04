#pragma once

#include <memory>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <stack>

#include "Line.h"
#include "Triangle.h"
#include "util.h"
#include "Matrix4.h"
#include "Transformations.h"

class Renderer : public Transformations
{
public:

    Renderer();

    void clearObjectBuffers();
    void clearAll();

    void drawLine(const Line &line);
    void drawTriangle(const Triangle &triangle);

    void pushTriangle(const Triangle& t);
    void pushTriangle(const std::vector<Triangle> &ts);
    void pushLine(const Line& l);
    void pushLine(const std::vector<Line> &ls);

    void pushCube();

    void renderShapes();

private:

    Vec3 triangularInterpolation(const Vec2 &p, const Triangle &t, double inverseArea);
    bool isInTriangle(const Vec2 &p, const Triangle &t);

    std::vector<Line> lineBuffer;
    std::vector<Triangle> triangleBuffer;
};