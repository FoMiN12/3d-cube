#include <iostream>

#include "graphicengine.h"

using namespace std;

int main()
{
    
    /*cout << "Hello World!\n";
    float a[1][3] = { 5,5,5};
    float b[3][1] = { {1.1},{2.1},{3.1} };
    float c[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            c[i][j] = i + j;
    }
    
    float oldDot1[1][3] = { 5, 5, 5 };
    float** result = rotate2default(oldDot1, 1);
    for (int i = 0; i < 1; i++)
        for (int j = 0; j < 3;j++)
            cout << result[i][j] << " ";

    delete[] result;*/
    
    /*float a1[1][3] = {1,0,0};
    float a2[1][3] = { 0,1,0 };
    float  a3[1][3] = { 0,0,1 };
    float** e1 = rotate2default(a1, 1);
    float** e2 = rotate2default(a2, 1);
    float** e3 = rotate2default(a3, 1);

    for (int i = 0;i < 3;i++) {
        cout << e3[0][i] << endl;
    }*/
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Cube window", sf::Style::Default, settings);
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

    sf::VertexArray triangle(sf::Quads, 4);
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Blue;
    triangle[2].color = sf::Color::Green;
    triangle[3].color = sf::Color::Blue;


    sf::Clock clock;
    sf::Time elapsed;

    float angularVelocity[3] = { 0.2,0.2,0.2 };

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
        for (int i = 0;i < 4;i++)
        {
            dots[i].rotate(elapsed.asSeconds() * angularVelocity[2], 'z');
            triangle[i].position = dots[i].screenPosition;
        }

        //cout << dot1.screenPosition.y << ' ' << dot2.screenPosition.y << ' ' << dot3.screenPosition.y << ' ';
        // define the color of the triangle's points
        
        window.draw(triangle);

        window.display();
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
