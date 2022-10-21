#include "Renderer.h"

Renderer::Renderer()
{
    gradientSize = getSize(gradient);
    maxZ = 3 * gradientSize;

    updateWindowSize();
}

void Renderer::updateWindowSize()
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    screenWidth = w.ws_col;
    screenHeight = w.ws_row;

    aspectRatio = (double)screenWidth/(double)screenHeight;
    bufferSize = screenHeight * screenWidth;

    screenBuffer.reset(new char[bufferSize + 1]);
    std::fill(screenBuffer.get(), &screenBuffer.get()[bufferSize - 1], ' ');
    screenBuffer.get()[bufferSize] = '\0';

    depthBuffer.reset(new double[bufferSize]);
    std::fill(depthBuffer.get(), &depthBuffer.get()[bufferSize - 1], maxZ);
}

void Renderer::drawFrame()
{
    puts(screenBuffer.get());
}

void Renderer::clearFrame()
{
    std::fill(screenBuffer.get(), &screenBuffer.get()[bufferSize - 1], ' ');
    screenBuffer.get()[bufferSize] = '\0';
    
    std::fill(depthBuffer.get(), &depthBuffer.get()[bufferSize - 1], maxZ);
}

void Renderer::drawPoint2d(unsigned int x,unsigned int y,unsigned char c)
{
    int i = y * screenWidth + x;

    if(i >= bufferSize || i < 0) return;
    
    screenBuffer.get()[i] = c;
}

Vec3 Renderer::projection(const Vec3 &&point)
{
    if(!orthographic) return point;

    double coefficient = eyeDistance / (point.z + eyeDistance);
    
    return Vec3(point.x * coefficient, point.y * coefficient, point.z);
}

Vec3 Renderer::toScreenCoords(const Vec3 &&point)
{
    double x = point.x * screenWidth / aspectRatio + screenWidth / 2;
    double y = (point.y + 1) * screenHeight / 2;

    return Vec3(round(x), round(y), point.z);
}

bool Renderer::depthTest(int x, int y, double z)
{
    return z <= depthBuffer.get()[y*screenWidth + x] || !testDepth;
}

char Renderer::charFromGradient(double z)
{
    char c = ' ';
    if(z <= maxZ && z >= 0) c = gradient[(int)(z / 3)];

    return c;
} 