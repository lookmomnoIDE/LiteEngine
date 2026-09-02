#ifndef TVERTEX_H
#define TVERTEX_H 

#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"
#include "Color.h"


template <typename T>
class tVertex
{

public:
	Vec3<T> Position;
	Color color;
	Vec2<T> texCoords;


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

	Vec2<T>& getVTexCoord()
	{
		return texCoords;
	}

	void setVTexCoord(Vec2<T> t)
	{
		texCoords = t;
	}
};


#endif