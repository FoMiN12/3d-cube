#include "graphicengine.h"

void Dot::set3D2Screen()
{
    m_xScreen = 400.f + coordinates3D[0][1];
    m_yScreen = 300.f - coordinates3D[0][2];
    m_zScreen = coordinates3D[0][0];
}

Dot::Dot(float x, float y, float z)
{
    m_xScreen = 0;
    m_yScreen = 0;
    m_zScreen = 0;
    coordinates3D[0][0] = x;
    coordinates3D[0][1] = y;
    coordinates3D[0][2] = z;
    set3D2Screen();
}

Dot::Dot(float coordinates[1][3])
{
    m_xScreen = 0;
    m_yScreen = 0;
    m_zScreen = 0;
    for (int i = 0; i < 3; i++)
        coordinates3D[0][i] = coordinates[0][i];
    set3D2Screen();
}

Dot::Dot()
{
    m_xScreen = 0;
    m_yScreen = 0;
    m_zScreen = 0;
    coordinates3D[0][0] = 0;
    coordinates3D[0][1] = 0;
    coordinates3D[0][2] = 0;
    set3D2Screen();
}

void Dot::rotate(float angles[3])
{
    float **result = rotateAroundAxisNew(coordinates3D, angles[0], 'x', 1);
    result = rotateAroundAxisNew(result, angles[1], 'y', 1);
    result = rotateAroundAxisNew(result, angles[2], 'z', 1);
    for (int i = 0; i < 3; i++)
        coordinates3D[0][i] = result[0][i];
    delete[] result[0];
    delete[] result;
    set3D2Screen();
}

float Dot::getScreenPosition(char axis)
{
    float result;
    switch (axis) {
        case 'x' :
            result = m_xScreen;
            break;

        case 'y' :
            result = m_yScreen;
            break;

        case 'z' :
            result = m_zScreen;
            break;

        default :
            result = 0;
    }
    return result;
}


float Quadrilateral::computeDepth()
{
    float sumDepth = 0;
    for (int i = 0;i < 4;i++)
        sumDepth += vertexes[i].getScreenPosition('z');
    return sumDepth / 4.0f;
}

Quadrilateral::Quadrilateral(Dot dot1, Dot dot2, Dot dot3, Dot dot4)
{
    vertexes = new Dot[4];
    vertexes[0] = dot1;
    vertexes[1] = dot2;
    vertexes[2] = dot3;
    vertexes[3] = dot4;
    depth = computeDepth();

    /*sf::VertexArray figure(sf::Quads, 4);
    sf::VertexArray shape = figure;
    for (int i = 0;i < 4;i++) {
        shape[i].position = vertexes[i].screenPosition;
        shape[i].color = color;
    }*/
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
    
    //sf::VertexArray shape(sf::Quads, 4);
    //for (int i = 0;i < 4;i++) {
    //    shape[i].position = vertexes[i].screenPosition;
    //    shape[i].color = sf::Color::White;
    //}
}

/*void Quadrilateral::updatePosition()
{
    for (int i = 0;i < 4;i++)
    {
        shape[i].position = vertexes[i].screenPosition;
    }
    computeDepth();
}*/


void Quadrilateral::rotate(float angles[3])
{
    for (int i = 0;i < 4;i++)
        vertexes[i].rotate(angles);
    
}

void Qube::rotate(float angles[3])
{
    for (int i = 0;i < 6;i++)
        edges[i].rotate(angles);
}

Qube::Qube(Quadrilateral* quadrilaterals)
{
    edges = new Quadrilateral[6];
    for (int i = 0;i < 6;i++) {
        edges[i] = quadrilaterals[i];
        drawOrder[i] = i;
    }
}

Qube::Qube(Quadrilateral q1, Quadrilateral q2, Quadrilateral q3, Quadrilateral q4, Quadrilateral q5, Quadrilateral q6 )
{
    edges = new Quadrilateral[6];
    
    edges[0] = q1;
    edges[1] = q2;
    edges[2] = q3;
    edges[3] = q4;
    edges[4] = q5;
    edges[5] = q6;
    for (int i = 0;i < 6;i++) {
        drawOrder[i] = i;
    }
}

void Qube::updateDrawOrder()
{
    float minimum, a;
    for (int i = 0; i < 6; i++) {
        minimum = edges[i].depth;
        for (int j = i + 1;j < 6;j++) {
            a = edges[j].depth;
            if (a < minimum) {
                drawOrder[j] = i;
                drawOrder[i] = j;
                minimum = edges[j].depth;
            }
        }
    }
}

