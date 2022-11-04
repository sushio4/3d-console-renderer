#include "Renderer.h"

void Renderer::drawLine(const Line &line)
{
    Vec3 p1 = toScreenCoords(projection(line.getp1()));
    Vec3 p2 = toScreenCoords(projection(line.getp2()));

    //check if its even on the screen
    if( fmax(p1.x, p2.x) < 0 ||
        fmin(p1.x, p2.x) > screenWidth ||
        fmax(p1.y, p2.y) < 0 ||
        fmin(p1.y, p2.y) > screenHeight ||
        fmax(p1.z, p2.z) < 0 ||
        fmin(p1.z, p2.z) > maxZ)
        return;

    int begin, current, end;
    int beginPerp, currPerp, endPerp;
    double beginZ = p1.z, endZ = p2.z;

    bool isp1xGreater = p1.x > p2.x;
    bool isp1yGreater = p1.y > p2.y;

    begin = round(p1.x);
    end = round(p2.x);

    beginPerp = round(p1.y);
    endPerp = round(p2.y);

    bool isxPrimary = fabs(p1.x - p2.x) > fabs(p1.y - p2.y);
    
    double slope = 1;

    int max, maxPerp;

    if(isxPrimary)
    {
        if(begin == end) return;

        slope = (p2.y - p1.y) / (p2.x - p1.x);

        maxPerp = screenHeight;
        max = screenWidth;
    }
    else
    {
        int t = beginPerp;
        beginPerp = begin;
        begin = t;
        
        t = endPerp;
        endPerp = end;
        end = t;

        if(begin == end) return;

        slope = (p2.x - p1.x) / (p2.y - p1.y);

        maxPerp = screenWidth;
        max = screenHeight;
    }

    current = begin;
    currPerp = beginPerp;

    double denominator = 1 / fabs(end - begin);

    do
    {
        int z = lerp(beginZ, endZ, fabs(current - begin) * denominator);

        char c = charFromGradient(z);

        int currentIncrement = 0;

        if(isxPrimary)
        {
            if(depthTest(current, currPerp, z))
                drawPoint2d(current, currPerp, c);

            if(isp1xGreater) currentIncrement--;
                else         currentIncrement++;
        }
        else
        {
            if(depthTest(currPerp, current, z))
                drawPoint2d(currPerp, current, c);

            if(isp1yGreater) currentIncrement--;
                else         currentIncrement++;
        }        

        int increment = (currentIncrement * slope) > 0 ? 1 : -1;
        current += currentIncrement;

        if(fabs((current - begin) * slope - (currPerp - beginPerp + increment)) <
            fabs((current - begin) * slope - (currPerp - beginPerp)))
            currPerp += increment;

    } while(current != end);
    
}

void Renderer::drawTriangle(const Triangle &triangle)
{
    Vec3 p1 = toScreenCoords(projection(triangle.pt1()));
    Vec3 p2 = toScreenCoords(projection(triangle.pt2()));
    Vec3 p3 = toScreenCoords(projection(triangle.pt3()));

    double inverseArea = 1 / Vec2::crossProd(p2 - p1, p3 - p1).magnitude();

    int beginx = fmin(fmin(p1.x, p2.x), p3.x);
    int endx = fmax(fmax(p1.x, p2.x), p3.x);
    int beginy = fmin(fmin(p1.y, p2.y), p3.y);
    int endy = fmax(fmax(p1.y, p2.y), p3.y);

    for(double x = beginx; x <= endx; x++)
    {
        for(double y = beginy; y <= endy; y++)
        {
            if(isInTriangle(Vec2(x, y), Triangle(p1, p2, p3)))
            {
                Vec3 weigths = triangularInterpolation(Vec2(x, y), Triangle(p1, p2, p3), inverseArea);
                double z = p1.z * weigths.x + p2.z * weigths.y + p3.z * weigths.z;

                char c = charFromGradient(z);

                if(depthTest(x, y, z) && z <= maxZ)
                    drawPoint2d(x, y, c);
            }
        }
    }
}

bool Renderer::isInTriangle(const Vec2 &p, const Triangle &t)
{
    Vec3 c1 = Vec3::crossProd(p - t.pt1(), t.pt2() - t.pt1());
    Vec3 c2 = Vec3::crossProd(p - t.pt2(), t.pt3() - t.pt2());
    Vec3 c3 = Vec3::crossProd(p - t.pt3(), t.pt1() - t.pt3());

    return (sign(c1.z) == sign(c2.z)) && (sign(c2.z) == sign(c3.z));
}

Vec3 Renderer::triangularInterpolation(const Vec2 &p, const Triangle &t, double inverseArea)
{
    double a1 = Vec2::crossProd(p - t.pt2(), t.pt3() - t.pt2()).magnitude();
    double a2 = Vec2::crossProd(p - t.pt3(), t.pt1() - t.pt3()).magnitude();
    double a3 = Vec2::crossProd(p - t.pt1(), t.pt2() - t.pt1()).magnitude();

    return Vec3(a1 * inverseArea, a2 * inverseArea, a3 * inverseArea);
}

