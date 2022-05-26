#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include <SFML/Graphics.hpp>
#include "mathtransform.h"
#include <iostream>

using namespace std;

class Dot
{
public:
	Dot(float coordinates[1][3]);

	sf::Vector2f screenPosition;
	float depth;
	float** threeDPosition;
	Dot(float x, float y, float z);
	
	
	void setThreeD2Screen();

private:

	
	

};




void StartWindow();



#endif