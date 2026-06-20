#ifndef MAT2_H
#define MAT2_H 



#include "Vec2.h"


template <typename T>

class Mat2
{

public:
	Vec2<T> m_c1 = Vec2(T x, T y);
	Vec2<T> m_c2 = Vec2(T x, T y);

	Mat2& add(const Mat2& rhs)
	{
		m_c1 + rhs.m_c1;
		m_c2 + rhs.m_c2;
		return *this;
	}

	Mat2& multiply(const Mat2& rhs)
	{

	}

	//Ax = b

	Vec2 findB(const Mat2& A, const Vec2& x)
	{
		auto x_ = (x.m_x * A.m_c1.m_x) + (x.m_y * A.m_c2.m_x);
		auto y_ = (x.m_y * A.m_c1.m_y) + (x.m_y * A.m_c2.m_y);
		return Vec2<T>(x_, y_);
	}



};



#endif