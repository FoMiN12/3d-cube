#include <iostream>

#include "graphicengine.h"

using namespace std;

int main()
{
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Cube window", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);
    Dot* dots = new Dot[8];
    Dot dot1(200.f, -200.f, -200.f);
    Dot dot2(-200.f, -200.f, -200.f);
    Dot dot3(-200.f, 200.f, -200.f);
    Dot dot4(200.f, 200.f, -200.f);
    Dot dot5(200.f, -200.f, 200.f);
    Dot dot6(-200.f, -200.f, 200.f);
    Dot dot7(-200.f, 200.f, 200.f);
    Dot dot8(200.f, 200.f, 200.f);
    dots[0] = dot1;
    dots[1] = dot2;
    dots[2] = dot3;
    dots[3] = dot4;
    dots[4] = dot5;
    dots[5] = dot6;
    dots[6] = dot7;
    dots[7] = dot8;
   cout << dot1.getScreenPosition('x') << " ";
    cout << dot7.getScreenPosition('x') << endl;

    Side edge1(dot1, dot2, dot3, dot4);
    Side edge2(dot1, dot2, dot6, dot5);
    Side edge3(dot2, dot3, dot7, dot6);
    Side edge4(dot3, dot4, dot8, dot7);
    Side edge5(dot1, dot5, dot8, dot4);
    Side edge6(dot5, dot6, dot7, dot8);

    Side* edges = new Side[6];
    edges[0] = edge1;
    edges[1] = edge2;
    edges[2] = edge3;
    edges[3] = edge4;
    edges[4] = edge5;
    edges[5] = edge6;

    edges[0].setColor(sf::Color::Cyan);
    edges[1].setColor(sf::Color::Green);
    edges[2].setColor(sf::Color::Magenta);
    edges[3].setColor(sf::Color::Red);
    edges[4].setColor(sf::Color::White);
    edges[5].setColor(sf::Color::Yellow);

    //for (int i = 0;i < 6;i++)
    //    cout << edges[i].vertexes[0].getScreenPosition('x') << ' ';
   // cout << endl;

    Qube qube(edges);


    //for (int i = 0;i < 6;i++)
    //    cout << qube.edges[i].vertexes[0].getScreenPosition('x') << ' ';
    //cout << endl;
    
    /*sf::VertexArray side1(sf::Quads, 4);
    sf::VertexArray side2(sf::Quads, 4);
    sf::VertexArray side3(sf::Quads, 4);
    sf::VertexArray side4(sf::Quads, 4);
    sf::VertexArray side5(sf::Quads, 4);
    sf::VertexArray side6(sf::Quads, 4);

    for (int i = 0; i < 4; i++)
        side1[i].color = sf::Color::Blue;
    for (int i = 0; i < 4; i++)
        side2[i].color = sf::Color::Cyan;
    for (int i = 0; i < 4; i++)
        side3[i].color = sf::Color::Green;
    for (int i = 0; i < 4; i++)
        side4[i].color = sf::Color::Magenta;
    for (int i = 0; i < 4; i++)
        side5[i].color = sf::Color::Red;
    for (int i = 0; i < 4; i++)
        side6[i].color = sf::Color::White;*/

    //for (int i = 0; i < 0; i++) {
   // cout << side1[0].position.x << endl;

    //}
    /*sf::VertexArray triangle(sf::Quads, 4);
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Blue;
    triangle[2].color = sf::Color::Green;
    triangle[3].color = sf::Color::Cyan;*/


    sf::Clock clock;
    sf::Time elapsed;

    float angularVelocity[3] = {0.8,0.8,0.8 };
   

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        elapsed = clock.restart();

        window.clear(sf::Color::Black);

        // define the position of the triangle's points
        float currentAngularDiv[3] = { angularVelocity[0] * elapsed.asSeconds(), angularVelocity[1] * elapsed.asSeconds(),
                                           angularVelocity[2] * elapsed.asSeconds() };
        for (int i = 0;i < 6;i++) {
            qube.edges[i].rotate(currentAngularDiv);
            qube.edges[i].computeDepth();
        }
           
            
        
        /*for (int i = 0; i < 4; i++) {
            side1[i].position.x = qube.edges[0].vertexes[i].getScreenPosition('x');
            side1[i].position.y = qube.edges[0].vertexes[i].getScreenPosition('y');
        }
        for (int i = 0; i < 4; i++) {
            side2[i].position.x = qube.edges[0].vertexes[i].getScreenPosition('x');
            side2[i].position.y = qube.edges[0].vertexes[i].getScreenPosition('y');
        }
        for (int i = 0; i < 4; i++) {
            side3[i].position.x = qube.edges[0].vertexes[i].getScreenPosition('x');
            side3[i].position.y = qube.edges[0].vertexes[i].getScreenPosition('y');
        }
        for (int i = 0; i < 4; i++) {
            side4[i].position.x = qube.edges[0].vertexes[i].getScreenPosition('x');
            side4[i].position.y = qube.edges[0].vertexes[i].getScreenPosition('y');
        }
        for (int i = 0; i < 4; i++) {
            side5[i].position.x = qube.edges[0].vertexes[i].getScreenPosition('x');
            side5[i].position.y = qube.edges[0].vertexes[i].getScreenPosition('y');
        }
        for (int i = 0; i < 4; i++) {
            side6[i].position.x = qube.edges[0].vertexes[i].getScreenPosition('x');
            side6[i].position.y = qube.edges[0].vertexes[i].getScreenPosition('y');
        }*/


        
        //cout << dot1.screenPosition.y << ' ' << dot2.screenPosition.y << ' ' << dot3.screenPosition.y << ' ';
        // define the color of the triangle's points
        
        qube.updateDrawOrder();
        for (int i = 0;i <6;i++)
        {
            int order = qube.drawOrder[i];
            window.draw(qube.edges[order]);
        }
        //window.draw(triangle);

        window.display();
    }
    return 0;
}
