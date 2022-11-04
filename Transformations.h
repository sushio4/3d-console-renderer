#include <stack>
#include "util.h"
#include "Screen.h"
#include "Vec3.h"
#include "Matrix4.h"
#include "Line.h"
#include "Triangle.h"

class Transformations : public Screen
{
public:

    Transformations();

    Vec3 projection(const Vec3 &&point);
    Vec3 toScreenCoords(const Vec3 &&point);

    void init();

    void enableDepthTest();
    void disableDepthTest();
    void enableOrtho();
    void disableOrtho();

    bool setEyeDistance(double dist);

    Line transform(const Line& line, const Matrix4& matrix);
    Triangle transform(const Triangle& triangle, const Matrix4& matrix);

    //override
    void clearFrame();
    void updateWindowSize();
    
    Matrix4 modelMatrix;
    

protected:

    bool depthTest(int x, int y, double z);
    char charFromGradient(double z);

    std::unique_ptr<double[]> depthBuffer;

    std::stack<Matrix4> modelMatrixStack;

    bool orthographic = false;
    bool testDepth = false;

    double eyeDistance = 1;
    double maxZ = INT32_MAX;

    const char* gradient = "@#$&?=+!*^;:\"-,'.`";
    size_t gradientSize;
};