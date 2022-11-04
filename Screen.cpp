#include "Screen.h"

void Screen::updateWindowSize()
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
}

void Screen::drawFrame()
{
    puts(screenBuffer.get());
}

void Screen::clearFrame()
{
    std::fill(screenBuffer.get(), &(screenBuffer.get()[bufferSize - 1]), ' ');
    screenBuffer.get()[bufferSize] = '\0';
}

void Screen::drawPoint2d(unsigned int x,unsigned int y,unsigned char c)
{
    int i = y * screenWidth + x;

    if(i >= bufferSize || i < 0) return;
    
    screenBuffer.get()[i] = c;
}