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
	Side();
	void computeDepth();
	
	void rotate(float[3]);
	void setColor(sf::Color);
	void updateVertices();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		//states.texture = &m_tileset;

		// draw the vertex array
		target.draw(m_vertices, states);
	}

	sf::VertexArray m_vertices;
	//sf::Texture m_tileset;
};

class Qube
{
public:
	Side* edges;
	int drawOrder[6];
	Qube(Side*);
	Qube(Side, Side, Side, Side, Side, Side);

	void rotate(float[3]);

	void updateDrawOrder();


private:

};




#endif