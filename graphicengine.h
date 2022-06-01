#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include <SFML/Graphics.hpp>
#include "mathtransform.h"
#include <iostream>

using namespace std;

class Dot
{
public:
	Dot(float x, float y, float z);
	Dot(float coordinates[1][3]);
	Dot();

	void set3D2Screen();
	void rotate(float[3]);
	float getScreenPosition(char);

private:
	float coordinates3D[1][3];

	float m_xScreen;
	float m_yScreen;
	float m_zScreen;
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