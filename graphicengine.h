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
	void scale(float);

	float getScreenPosition(char);
	void setScreenPosition(float, float);

	void set3DPosition(float, float, float);
	void set3DPosition(float(*)[3]);

private:
	float coordinates3D[1][3];

	float m_xScreen;
	float m_yScreen;
	float m_zScreen;
};

class Side : public sf::Drawable, public sf::Transformable
{
public:
	Dot* vertexes;
	float depth;
	
	Side(Dot, Dot, Dot, Dot);
	Side(Dot*);
	Side(float, float, float, float, sf::Color);
	Side();
	void computeDepth();
	
	void movePositionByX(float);
	void rotate(float[3]);
	void scale(float);

	void setColor(sf::Color);
	void updateVertices();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();

		// draw the vertex array
		target.draw(m_vertices, states);
	}

	sf::VertexArray m_vertices;
};

class Qube
{
public:
	Side* edges;
	int drawOrder[6];
	Qube(Side*);
	Qube(Side, Side, Side, Side, Side, Side);

	void rotate(float[3]);
	void scale(float);
	void setSize(float, float);

	void updateDrawOrder();


private:

};




#endif