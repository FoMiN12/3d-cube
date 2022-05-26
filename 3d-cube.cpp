﻿#include <iostream>

#include "mathtransform.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";
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





    delete[] result;
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
