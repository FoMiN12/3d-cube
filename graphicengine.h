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
	sf::VertexArray shape;
	
	Quadrilateral(Dot, Dot, Dot, Dot, sf::Color);
	Quadrilateral();
	float computeDepth();
	void updatePosition();
	void rotate(float[3]);
	void setColor(sf::Color);

private:

};

class Qube
{
public:
	Quadrilateral *edges;

	Qube(Quadrilateral*);

	void rotate(float[3]);



private:

};



#endif