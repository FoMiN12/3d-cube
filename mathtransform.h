#ifndef MATHTRANSFORM_H
#define MATHTRANSFORM_H

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>

using namespace std;

float** multiplyMatrices(float**, float**, int, int);
float** multiplyMatrices(float(*)[3], float**, int, int);
float** multiplyMatrices(float**, float(*)[3], int, int);
float** multiplyMatrices(float**, float(*)[1], int, int);
float** multiplyMatrices(float(*)[3], float(*)[3], int, int);
float** multiplyMatrices(float(*)[3], float(*)[1], int, int);

float** rotateAroundAxisOld(float**, float, char, int);
float** rotateAroundAxisOld(float(*)[3], float, char, int);

float** rotateAroundAxisNew(float**, float, char, int);
float** rotateAroundAxisNew(float(*)[3], float, char, int);


float** rotate2default(float**, int);
float** rotate2default(float(*)[3], int);

#endif
