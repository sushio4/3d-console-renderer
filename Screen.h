#include <sys/ioctl.h>
#include <memory>
#include <cstdio>

class Screen
{
public:

    void clearFrame();
    void drawFrame();

    void drawPoint2d(unsigned int x, unsigned int y, unsigned char c);

    virtual void updateWindowSize();

protected:

    std::unique_ptr<char[]> screenBuffer;

    unsigned int bufferSize;

    unsigned int screenWidth, screenHeight;
    
    double aspectRatio = 1;
};