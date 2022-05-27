#include "graphicengine.h"

void Dot::setThreeD2Screen()
{
    screenPosition.x = 400.f + threeDPosition[0][1];
    screenPosition.y = 300.f - threeDPosition[0][2];
    depth = threeDPosition[0][0];
}
void Dot::rotate(float angles[3])
{
    threeDPosition = rotateAroundAxisNew(threeDPosition, angles[0], 'x', 1);
    threeDPosition = rotateAroundAxisNew(threeDPosition, angles[1], 'y', 1);
    threeDPosition = rotateAroundAxisNew(threeDPosition, angles[2], 'z', 1);
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

Quadrilateral::Quadrilateral(Dot dot1, Dot dot2, Dot dot3, Dot dot4, sf::Color color)
{
    vertexes = new Dot [4];
    vertexes[0] = dot1;
    vertexes[1] = dot2;
    vertexes[2] = dot3;
    vertexes[3] = dot4;
    depth = computeDepth();

    sf::VertexArray shape(sf::Quads, 4);
    for (int i = 0;i < 4;i++) {
        shape[i].position = vertexes[i].screenPosition;
        shape[i].color = color;
    }
}

float Quadrilateral::computeDepth()
{
    float sumDepth = 0;
    for (int i = 0;i < 4;i++)
        sumDepth += vertexes[i].depth;
    return sumDepth / 4.0f;
}

Quadrilateral::Quadrilateral()
{
    vertexes = new Dot[4];
    Dot dot1;
    Dot dot2;
    Dot dot3;
    Dot dot4;
    vertexes[0] = dot1;
    vertexes[1] = dot2;
    vertexes[2] = dot3;
    vertexes[3] = dot4;
    depth = computeDepth();
    
    sf::VertexArray shape(sf::Quads, 4);
    for (int i = 0;i < 4;i++) {
        shape[i].position = vertexes[i].screenPosition;
        shape[i].color = sf::Color::White;
    }

}

void Quadrilateral::updatePosition()
{
    for (int i = 0;i < 4;i++)
        shape[i].position = vertexes[i].screenPosition;
    computeDepth();
}

void Quadrilateral::setColor(sf::Color color)
{
    for (int i = 0;i < 4;i++) {
        shape[i].color = color;
    }
}

void Quadrilateral::rotate(float angles[3])
{
    for (int i = 0;i < 4;i++)
        vertexes[i].rotate(angles);
    updatePosition();
}

Qube::Qube(Quadrilateral* quadrilaterals)
{
    edges = new Quadrilateral[6];
    for (int i = 0;i < 6;i++)
        edges[i] = quadrilaterals[i];
}

void Qube::rotate(float angles[3])
{
    for (int i = 0;i < 6;i++)
        edges[i].rotate(angles);
}
