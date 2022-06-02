#include "graphicengine.h"

void Dot::set3D2Screen()
{
    m_xScreen = 550.f + coordinates3D[0][1];
    m_yScreen = 350.f - coordinates3D[0][2];
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

    /*float** result = rotate2default(coordinates3D, 1);
    for (int i = 0; i < 3; i++)
        coordinates3D[0][i] = result[0][i];
    delete[] result[0];
    delete[] result;*/

    set3D2Screen();
}

Dot::Dot(float coordinates[1][3])
{
    m_xScreen = 0;
    m_yScreen = 0;
    m_zScreen = 0;

    /*float** result = rotate2default(coordinates, 1);
    for (int i = 0; i < 3; i++)
        coordinates3D[0][i] = result[0][i];
    delete[] result[0];
    delete[] result;*/

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
    float **result = rotateAroundAxisOld(coordinates3D, angles[0], 'x', 1);
    result = rotateAroundAxisOld(result, angles[1], 'y', 1);
    result = rotateAroundAxisOld(result, angles[2], 'z', 1);

    for (int i = 0; i < 3; i++)
        coordinates3D[0][i] = result[0][i];
    delete[] result[0];
    delete[] result;

    set3D2Screen();
}

void Dot::scale(float multiplier)
{
    for (int i = 0; i < 3; i++)
        coordinates3D[0][i] = coordinates3D[0][i] * multiplier;

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

void Dot::setScreenPosition(float x, float y)
{
    m_xScreen = x;
    m_yScreen = y;
}

void Dot::set3DPosition(float coordinates[1][3])
{
    for (int i = 0;i < 3;i++)
        coordinates3D[0][i] = coordinates[0][i];
    set3D2Screen();
}

void Dot::set3DPosition(float x, float y, float z)
{
    coordinates3D[0][0] = x;
    coordinates3D[0][1] = y;
    coordinates3D[0][2] = z;
    set3D2Screen();
}

void Side::computeDepth()
{
    float sumDepth = 0;
    for (int i = 0;i < 4;i++)
        sumDepth += vertexes[i].getScreenPosition('z');
    depth = sumDepth / 4.0f;
}

Side::Side(Dot dot1, Dot dot2, Dot dot3, Dot dot4)
{
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    setColor(sf::Color::White);

    vertexes = new Dot[4];
    vertexes[0] = dot1;
    vertexes[1] = dot2;
    vertexes[2] = dot3;
    vertexes[3] = dot4;

    updateVertices();

    computeDepth();
}

Side::Side(Dot* dots)
{
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    setColor(sf::Color::White);

    vertexes = dots;

    updateVertices();

    computeDepth();
}

Side::Side()
{
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    setColor(sf::Color::White);

    vertexes = new Dot[4];
    Dot dot1;
    Dot dot2;
    Dot dot3;
    Dot dot4;
    vertexes[0] = dot1;
    vertexes[1] = dot2;
    vertexes[2] = dot3;
    vertexes[3] = dot4;

    updateVertices();

    computeDepth();
}

Side::Side(float x1,float x2,float y1, float y2, sf::Color color)
{
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    setColor(color);

    vertexes = new Dot[4];
    Dot dot1;
    Dot dot2;
    Dot dot3;
    Dot dot4;
    dot1.setScreenPosition(x1, y1);
    dot2.setScreenPosition(x2, y1);
    dot3.setScreenPosition(x2, y2);
    dot4.setScreenPosition(x1, y2);
    vertexes[0] = dot1;
    vertexes[1] = dot2;
    vertexes[2] = dot3;
    vertexes[3] = dot4;

    updateVertices();

    computeDepth();
}

void Side::setColor(sf::Color color)
{
    for (int i = 0;i < 4;i++)
        m_vertices[i].color = color;
}

void Side::rotate(float angles[3])
{
    for (int i = 0;i < 4;i++)
        vertexes[i].rotate(angles);
    updateVertices();
}

void Side::scale(float multiplier)
{
    for (int i = 0;i < 4;i++)
        vertexes[i].scale(multiplier);

    updateVertices();
}

void Side::updateVertices()
{
    for (int i = 0;i < 4;i++) {
        m_vertices[i].position.x = vertexes[i].getScreenPosition('x');
        m_vertices[i].position.y = vertexes[i].getScreenPosition('y');
    }
}

void Qube::rotate(float angles[3])
{
    for (int i = 0;i < 6;i++)
        edges[i].rotate(angles);
}

void Qube::scale(float multiplier)
{
    for (int i = 0;i < 6;i++)
        edges[i].scale(multiplier);
}

void Qube::setSize(float oldSize, float newSize)
{
    float multiplier = newSize / oldSize;
    scale(multiplier);
}

Qube::Qube(Side* sides)
{
    edges = new Side[6];
    for (int i = 0;i < 6;i++) {
        edges[i] = sides[i];
        drawOrder[i] = i;
    }
}

Qube::Qube(Side q1, Side q2, Side q3, Side q4, Side q5, Side q6 )
{
    edges = new Side[6];
    
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
    float arrForSort[6];
    for (int i = 0; i < 6;i++)
        arrForSort[i] = edges[i].depth;

    float minimum, a;
    for (int i = 0; i < 6; i++) {
        minimum = arrForSort[drawOrder[i]];
        for (int j = i + 1;j < 6;j++) {
            a = arrForSort[drawOrder[j]];
            if (a < minimum) { 
                float b = arrForSort[drawOrder[i]]; // создали дополнительную переменную
                arrForSort[drawOrder[i]] = arrForSort[drawOrder[j]]; // меняем местами
                arrForSort[drawOrder[j]] = b;
                int tempI = drawOrder[i];
                drawOrder[i] = drawOrder[j];
                drawOrder[j] = tempI;
            }
        }
    }

    /*for (int i = 0; i < 6; i++)
        cout << edges[drawOrder[i]].depth << ' ';
    cout << endl;
    for (int i = 0; i < 6; i++)
        cout << drawOrder[i] << ' ';
    cout << endl;*/
}

