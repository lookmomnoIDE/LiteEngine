#ifndef GEOMETRYCONSTRUCTOR_H
#define GEOMETRYCONSTRUCTOR_H

#include "Quad.h"

class GConstructor
{

public:

	template <typename T>
	static Vec3<T> normalize(Vec2<T> pos, Vec2<T> viewDims)
	{
		return Vec3<T>((pos.m_x/viewDims.m_x) * 2 - 1, 1 - (pos.m_y/viewDims.m_y) * 2, 1);
	}

	template <typename T>
	static Vec2<T> normalize2D(Vec2<T> pos, Vec2<T> viewDims)
	{
		return Vec2<T>((pos.m_x/viewDims.m_x) * 2 - 1, 1 - (pos.m_y/viewDims.m_y) * 2);
	}

	template <typename T>
	static Quad<T> rect(Vec2<T> pos, Vec4<T> color, Vec2<T> dims, std::vector<Vec2<T>> texCoords)
	{
		Quad<T> quad;

	    quad.v0.setVPosition(Vec3<float>((pos.m_x - dims.m_x), pos.m_y - dims.m_y, 1.0f));
	    quad.v1.setVPosition(Vec3<float>((pos.m_x + dims.m_x), pos.m_y - dims.m_y, 1.0f));
	    quad.v2.setVPosition(Vec3<float>((pos.m_x - dims.m_x), pos.m_y + dims.m_y, 1.0f));
	    quad.v3.setVPosition(Vec3<float>((pos.m_x + dims.m_x), pos.m_y + dims.m_y, 1.0f));
	    quad.v0.setVColor(color);
		quad.v1.setVColor(color);
		quad.v2.setVColor(color);
		quad.v3.setVColor(color);
		quad.v0.setVTexCoord(texCoords[0]);
		quad.v1.setVTexCoord(texCoords[1]);
		quad.v2.setVTexCoord(texCoords[2]);
		quad.v3.setVTexCoord(texCoords[3]);

		return quad;
	}	


	template <typename T>
	static Quad<T> rect(Vec3<T> pos, Vec4<T> color, Vec2<T> dims, std::vector<Vec2<T>> texCoords)
	{
		Quad<T> quad;

	    quad.v0.setVPosition(Vec3<float>((pos.m_x - dims.m_x), pos.m_y - dims.m_y, pos.m_z));
	    quad.v1.setVPosition(Vec3<float>((pos.m_x + dims.m_x), pos.m_y - dims.m_y, pos.m_z));
	    quad.v2.setVPosition(Vec3<float>((pos.m_x - dims.m_x), pos.m_y + dims.m_y, pos.m_z));
	    quad.v3.setVPosition(Vec3<float>((pos.m_x + dims.m_x), pos.m_y + dims.m_y, pos.m_z));
	    quad.v0.setVColor(color);
		quad.v1.setVColor(color);
		quad.v2.setVColor(color);
		quad.v3.setVColor(color);
		quad.v0.setVTexCoord(texCoords[0]);
		quad.v1.setVTexCoord(texCoords[1]);
		quad.v2.setVTexCoord(texCoords[2]);
		quad.v3.setVTexCoord(texCoords[3]);

		return quad;
	}	


	template <typename T>
	static Quad<T> square(Vec2<T> pos, Vec4<T> color, float dims)
	{
		Quad<T> quad;

	    quad.v0.setVPosition(Vec3<float>((pos.m_x - dims), pos.m_y - dims, 1.0f));
	    quad.v1.setVPosition(Vec3<float>((pos.m_x + dims), pos.m_y - dims, 1.0f));
	    quad.v2.setVPosition(Vec3<float>((pos.m_x - dims), pos.m_y + dims, 1.0f));
	    quad.v3.setVPosition(Vec3<float>((pos.m_x + dims), pos.m_y + dims, 1.0f));
	    quad.v0.setVColor(color);
		quad.v1.setVColor(color);
		quad.v2.setVColor(color);
		quad.v3.setVColor(color);

		return quad;
	}	

};



#endif