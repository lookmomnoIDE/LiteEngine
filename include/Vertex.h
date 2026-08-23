#ifndef VERTEX_H
#define VERTEX_H 

#include "Vec3.h"
#include "Vec4.h"


template <typename T>
class Vertex
{

public:
	Vec3<T> Position;
	Vec4<T> Color;


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
};


#endif