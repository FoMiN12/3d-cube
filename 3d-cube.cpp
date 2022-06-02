#include <iostream>

#include "graphicengine.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    float size = 150;

    cout << "Введите размер куба. Рекомендуется: 150" << endl;

    while (!(cin >> size) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Error!" << endl;
        cout << "Ошибка ввода. Введите коректное значение" << endl;
    }

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Cube window", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);


    Dot* dots = new Dot[8];
    Dot dot1(size, -size, -size);
    Dot dot2(-size, -size, -size);
    Dot dot3(-size, size, -size);
    Dot dot4(size, size, -size);
    Dot dot5(size, -size, size);
    Dot dot6(-size, -size, size);
    Dot dot7(-size, size, size);
    Dot dot8(size, size, size);
    dots[0] = dot1;
    dots[1] = dot2;
    dots[2] = dot3;
    dots[3] = dot4;
    dots[4] = dot5;
    dots[5] = dot6;
    dots[6] = dot7;
    dots[7] = dot8;

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

    Qube qube(edges);


    sf::Clock clock;
    sf::Time elapsed;


    qube.setSize(size, 150);
    float angularVelocity[3] = {0.1,0.4,0.8 };
   

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
        
        // define the color of the triangle's points
        
        qube.updateDrawOrder();
        for (int i = 0;i <6;i++)
        {
            int order = qube.drawOrder[i];
            window.draw(qube.edges[order]);
        }

        window.display();
    }
    return 0;
}
