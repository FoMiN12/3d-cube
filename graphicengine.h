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
	void rotate(float, char);

private:

	

};






#endif