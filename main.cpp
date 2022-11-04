#include "Renderer.h"
#include <unistd.h>
#include <math.h>


int main(int argc, char *argv[])
{
    Renderer r;

    r.enableDepthTest();
    r.enableOrtho();
    r.setEyeDistance(10);

    double omega = 0.1;

    for (double i = 0;; i += omega)
    {
        r.clearFrame();
        r.clearObjectBuffers();

        r.modelMatrix = Matrix4::translate(Vec3(0,0,6)) * Matrix4::rotate(Matrix4::Axis::x, 0.3) *  Matrix4::rotate(Matrix4::Axis::y, i);

        r.pushCube();
        r.renderShapes();

        r.drawFrame();
        usleep(100000);
    }

    return 0;
}