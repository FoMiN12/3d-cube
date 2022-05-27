#include "graphicengine.h"

void Dot::setThreeD2Screen()
{
    screenPosition.x = 400.f + threeDPosition[0][1];
    screenPosition.y = 300.f - threeDPosition[0][2];
    depth = threeDPosition[0][0];
}
void Dot::rotate(float angle, char axis)
{
    threeDPosition = rotateAroundAxisNew(threeDPosition, angle, axis, 1);
    setThreeD2Screen();
}
Dot::Dot(float coordinates[1][3])
{
    /*threeDPosition = new float*;
    threeDPosition[0] = new float[3];
    for (int i = 0; i < 3;i++) {
        threeDPosition[0][i] = coordinates[0][i];
    }*/
    threeDPosition = rotate2default(coordinates, 1);
    setThreeD2Screen();
}

Dot::Dot(float x, float y, float z)
{
    float coordinates[1][3] = { x,y,z };
    threeDPosition = rotate2default(coordinates, 1);
    /*threeDPosition = new float*;
    threeDPosition[0] = new float[3];

    threeDPosition[0][0] = x;
    threeDPosition[0][1] = y;
    threeDPosition[0][2] = z;*/

    setThreeD2Screen();
}

Dot::Dot()
{
    float coordinates[1][3] = { 0,0,0 };
    threeDPosition = rotate2default(coordinates, 1);
    setThreeD2Screen();
}




