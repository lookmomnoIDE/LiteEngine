#ifndef TVERTEX_H
#define TVERTEX_H 

#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"


template <typename T>
class tVertex
{

public:
	Vec3<T> Position;
	Vec4<T> Color;
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

	Vec4<T>& getVColor()
	{
		return Color;
	}

	void setVColor( Vec4<T> c)
	{
		Color = c;
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