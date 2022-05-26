#ifndef MATHTRANSFORM_H
#define MATHTRANSFORM_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

float** multiplyMatrices(float**, float**, int, int);
float** multiplyMatrices(float(*)[3], float**, int, int);
float** multiplyMatrices(float**, float(*)[3], int, int);
float** multiplyMatrices(float**, float(*)[1], int, int);
float** multiplyMatrices(float(*)[3], float(*)[3], int, int);
float** multiplyMatrices(float(*)[3], float(*)[1], int, int);

float** rotateAroundAxis(float**, float, char, int);
float** rotateAroundAxis(float(*)[3], float, char, int);

#endif
