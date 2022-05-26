#include "graphicengine.h"

void Dot::setThreeD2Screen()
{
    screenPosition.x = 400.f + threeDPosition[0][1];
    screenPosition.y = 300.f - threeDPosition[0][2];
    depth = threeDPosition[0][0];
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



void StartWindow() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Cube window");

    Dot dot1(200.f, -200.f, -200.f);
    Dot dot2(-200.f, -200.f, -200.f);
    Dot dot3(-200.f, 200.f, -200.f);
    Dot dot4(200.f, 200.f, -200.f);
    Dot dot5(200.f, -200.f, 200.f);
    Dot dot6(-200.f, -200.f, 200.f);
    Dot dot7(-200.f, 200.f, 200.f);
    Dot dot8(200.f, 200.f, 200.f);

    sf::VertexArray triangle(sf::Quads, 4);

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        

        // define the position of the triangle's points
        triangle[0].position = dot1.screenPosition;
        triangle[1].position = dot2.screenPosition;
        triangle[2].position = dot3.screenPosition;
        triangle[3].position = dot4.screenPosition;
        //cout << dot1.screenPosition.y << ' ' << dot2.screenPosition.y << ' ' << dot3.screenPosition.y << ' ';
        // define the color of the triangle's points
        triangle[0].color = sf::Color::Red;
        triangle[1].color = sf::Color::Blue;
        triangle[2].color = sf::Color::Green;
        triangle[3].color = sf::Color::Blue;
        window.draw(triangle);

    

        window.display();
    }
}


