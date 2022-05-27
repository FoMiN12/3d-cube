#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include <SFML/Graphics.hpp>
#include "mathtransform.h"
#include <iostream>

using namespace std;

class Dot
{
public:
	sf::Vector2f screenPosition;
	float depth;
	float** threeDPosition;

	Dot(float coordinates[1][3]);
	Dot(float x, float y, float z);
	Dot();


	void setThreeD2Screen();
	void rotate(float[3]);

private:

};

class Quadrilateral
{
public:
	Dot* vertexes;
	float depth;
	
	Quadrilateral(Dot, Dot, Dot, Dot);
	Quadrilateral();
	float computeDepth();
	
	void rotate(float[3]);
	void setColor(sf::Color);

private:

};

class Qube
{
public:
	Quadrilateral* edges;
	int drawOrder[6];
	Qube(Quadrilateral*);
	Qube(Quadrilateral, Quadrilateral, Quadrilateral, Quadrilateral, Quadrilateral, Quadrilateral);

	void rotate(float[3]);

	void updateDrawOrder();


private:

};




#endif