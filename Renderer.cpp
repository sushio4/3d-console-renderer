#include "Renderer.h"

Renderer::Renderer()
{
    init();
}

void Renderer::clearObjectBuffers()
{
    lineBuffer.clear();
    triangleBuffer.clear();
}

void Renderer::clearAll()
{
    clearFrame();
    clearObjectBuffers();
}

void Renderer::pushTriangle(const Triangle& t)
{
    triangleBuffer.push_back(transform(t, modelMatrix));
}

void Renderer::pushTriangle(const std::vector<Triangle> &ts)
{
    for(Triangle t : ts)
        triangleBuffer.push_back(transform(t, modelMatrix));
}

void Renderer::pushLine(const Line& l)
{
    lineBuffer.push_back(transform(l, modelMatrix));
}

void Renderer::pushLine(const std::vector<Line> &ls)
{
    for(Line l : ls)
        lineBuffer.push_back(transform(l, modelMatrix));
}

void Renderer::renderShapes()
{
    for(int i = 0; i < lineBuffer.size(); i++)
        drawLine(lineBuffer[i]);

    for(int i = 0; i < triangleBuffer.size(); i++)
        drawTriangle(triangleBuffer[i]);
}

void Renderer::pushCube()
{
    Vec3 points[8];

    points[0] = Vec3(-1, -1, -1);
    points[1] = Vec3(1, -1, -1);
    points[2] = Vec3(-1, -1, 1);
    points[3] = Vec3(1, -1, 1);
    points[4] = Vec3(-1, 1, -1);
    points[5] = Vec3(1, 1, -1);
    points[6] = Vec3(-1, 1, 1);
    points[7] = Vec3(1, 1, 1);

    // front face
    pushLine(Line(points[4], points[5]));
    pushLine(Line(points[5], points[1]));
    pushLine(Line(points[1], points[0]));
    pushLine(Line(points[0], points[4]));
    // back face
    pushLine(Line(points[6], points[7]));
    pushLine(Line(points[7], points[3]));
    pushLine(Line(points[3], points[2]));
    pushLine(Line(points[2], points[6]));
    // middle lines
    pushLine(Line(points[4], points[6]));
    pushLine(Line(points[5], points[7]));
    pushLine(Line(points[1], points[3]));
    pushLine(Line(points[0], points[2]));

}