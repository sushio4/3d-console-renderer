#include "Renderer.h"
#include <unistd.h>
#include <math.h>

int main(int argc, char *argv[])
{

	Renderer r;
    double omega = 0.1;
    
    for(double i = 0;; i += omega)
    {
        r.clearFrame();
        Vec3 p1(cos(i), sin(i), 1);
        Vec3 p2(-cos(i), -sin(i), 1);
        r.drawLine(Line(p1,p2));
        r.drawFrame();
        usleep(100000);
    }

    return 0;
}