#include "util.h"

size_t getSize(const char* str)
{
    const size_t MAX = 10000000;
    size_t i = 0;

    while (str[i++] != '\0')
        if (i == MAX) return 0;

    return i - 1;
}

double lerp(double a, double b, double t)
{
    return a + t * (b - a);
}
