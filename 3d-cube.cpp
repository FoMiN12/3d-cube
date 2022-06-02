#include <iostream>

#include "graphicengine.h"
//#include <string>

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

    sf::RenderWindow window(sf::VideoMode(1100, 700), "Cube window", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);

    //qube

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

    //qube.setSize(size, 150);
    float angularVelocity[3] = { 0.1,0.4,0.8 };

    //interface
    //black background
    Side backgroundRectangle(110, 1010, 680, 590,sf::Color::Black);
    //axisRect
    Side xRectangle(140, 370, 660, 610, sf::Color::Red);
    Side yRectangle(450, 680, 660, 610, sf::Color::Green);
    Side zRectangle(760, 990, 660, 610, sf::Color::Blue);

    Side chooseRectangle(135, 375, 665, 605, sf::Color::White);
    int choosePos = 0;
    bool wasPressed = false;


    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // error...
    }

    sf::Text xSpeedtext;
    xSpeedtext.setFont(font);
    xSpeedtext.setCharacterSize(20);
    xSpeedtext.setFillColor(sf::Color::Black);

    sf::Text ySpeedtext;
    ySpeedtext.setFont(font);
    ySpeedtext.setCharacterSize(20);
    ySpeedtext.setFillColor(sf::Color::Black);

    sf::Text zSpeedtext;
    zSpeedtext.setFont(font);
    zSpeedtext.setCharacterSize(20);
    zSpeedtext.setFillColor(sf::Color::Black);

    xSpeedtext.setPosition(160, 620);
    ySpeedtext.setPosition(470, 620);
    zSpeedtext.setPosition(780, 620);


    sf::Clock clock;
    sf::Time elapsed;

    window.setKeyRepeatEnabled(false);

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
            

        while (window.pollEvent(event)) {
            // check the type of the event...
            switch (event.type) {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                    // key pressed
                case sf::Event::KeyPressed:
                    if (!wasPressed) {
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                            // left key is pressed: move our character
                            if (choosePos != 0) {
                                choosePos -= 1;
                                chooseRectangle.movePositionByX(-310);
                            }
                            else {
                                choosePos = 2;
                                chooseRectangle.movePositionByX(620);
                            }
                        }
                        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                            if (choosePos != 2) {
                                choosePos += 1;
                                chooseRectangle.movePositionByX(310);
                            }
                            else {
                                choosePos = 0;
                                chooseRectangle.movePositionByX(-620);
                            }
                        }
                        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                            angularVelocity[choosePos] += 0.1;
                        }
                        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                            angularVelocity[choosePos] -= 0.1;
                        }
                    }
                    wasPressed = !wasPressed;
                    break;

                    // we don't process other types of events
                default:
                    wasPressed = false;
                    break;
            }
        }
        /*while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
          
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (!wasPressed) {
                wasPressed = !wasPressed;
                // left key is pressed: move our character
                if (choosePos != 0) {
                    choosePos -= 1;
                    chooseRectangle.movePositionByX(-270);
                }
                else {
                    choosePos = 2;
                    chooseRectangle.movePositionByX(540);
                }
            }
        }
        else{
            wasPressed = !wasPressed;
        }*/

        elapsed = clock.restart();

        window.clear(sf::Color::Black);

        // define the position of the triangle's points
        float currentAngularDiv[3] = { angularVelocity[0] * elapsed.asSeconds(), angularVelocity[1] * elapsed.asSeconds(),
                                           angularVelocity[2] * elapsed.asSeconds() };
        for (int i = 0;i < 6;i++) {
            qube.edges[i].rotate(currentAngularDiv);
            qube.edges[i].computeDepth();
        }

        xSpeedtext.setString("Velocity Around X: " + to_string((int)(angularVelocity[0] * 10)));
        ySpeedtext.setString("Velocity Around Y: " + to_string((int)(angularVelocity[1] * 10)));
        zSpeedtext.setString("Velocity Around Z: " + to_string((int)(angularVelocity[2] * 10)));

        // define the color of the triangle's points
        
        qube.updateDrawOrder();
        for (int i = 0;i <6;i++)
        {
            int order = qube.drawOrder[i];
            window.draw(qube.edges[order]);
        }

        window.draw(backgroundRectangle);

        window.draw(chooseRectangle);

        window.draw(xRectangle);
        window.draw(yRectangle);
        window.draw(zRectangle);

        window.draw(xSpeedtext);
        window.draw(ySpeedtext);
        window.draw(zSpeedtext);



        window.display();
    }
    return 0;
}
