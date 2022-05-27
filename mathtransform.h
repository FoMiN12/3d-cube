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

float transitionMatrix2new[3][3] = { { 0.685663, 0.704416, 0.183480},
									 {-0.707066, 0.704416, -0.0620957},
									 { -0.172987, -0.0871557, 0.981060} };
float transitionMatrix2old[3][3] = { { 0.6856623, -0.7070656, -0.1729874},
									 {0.7044159, 0.7044161, -0.0871557},
									 { 0.1834796, -0.0620953, -0.9810605} };
float** rotate2default(float**, int);
float** rotate2default(float(*)[3], int);

#endif
