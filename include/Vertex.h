#ifndef VERTEX_H
#define VERTEX_H 

#include "Vec3.h"
#include "Vec4.h"
#include "Color.h"


template <typename T>
class Vertex
{

public:
	Vec3<T> Position;
	Color color;


	Vec3<T>& getVPosition()
	{
		return Position;
	}

	void setVPosition( Vec3<T> p)
	{
		Position = p;
		//return *this;
	}

	Color& getVColor()
	{
		return color;
	}

	void setVColor( Color c)
	{
		color = c;
		//return *this;
	}
};


#endif