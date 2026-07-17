#ifndef MAT4X4_H
#define MAT4X4_H

#include <array>
#include "Quaternion.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"

class Mat4x4
{
public:
	std::array<Vec4<float>, 4> m_Matrix;
	Mat4x4(Vec4<float> row1, Vec4<float> row2, Vec4<float> row3, Vec4<float> row4)
	:m_Matrix{{row1, row2, row3, row4}}
	{

	}
	Mat4x4(Vec4<float> diagonal)
	:m_Matrix
	{
    	Vec4<float>{diagonal.m_x, 0, 0, 0},
    	Vec4<float>{0, diagonal.m_y, 0, 0},
    	Vec4<float>{0, 0, diagonal.m_z, 0},
    	Vec4<float>{0, 0, 0, diagonal.m_w}
	}
	{

	}
	Mat4x4(float x = 1, float y = 1, float z = 1, float w = 1)
	:m_Matrix
	{
    	Vec4<float>{x, 0, 0, 0},
    	Vec4<float>{0, y, 0, 0},
    	Vec4<float>{0, 0, z, 0},
    	Vec4<float>{0, 0, 0, w}
	}
	{

	}

	Mat4x4(Quaternion a)
	:m_Matrix
	{
		Vec4<float>{a.quatVector.m_x, -a.quatVector.m_y, -a.quatVector.m_z, -a.quatVector.m_w},
		Vec4<float>{a.quatVector.m_y, a.quatVector.m_x, -a.quatVector.m_w, a.quatVector.m_z},
		Vec4<float>{a.quatVector.m_z, a.quatVector.m_w, a.quatVector.m_x, -a.quatVector.m_y},
		Vec4<float>{a.quatVector.m_w, -a.quatVector.m_z, a.quatVector.m_y, a.quatVector.m_x}
	}
	{

	}

	Mat4x4()

	Vec4<float> dotProduct(Quaternion a, Quaternion b)
	{
		Mat4x4 quaternion = Mat4x4(a);
		Vec4<float> vector = b.quatVector;
		Vec4<float> product = {matrixVectorMultiply(quaternion, vector)};
		return product;
	}

	Vec4<float> QmatrixVectorMultiply(Mat4x4 a, Vec4<float> b)
	{
		Vec4<float> dotProduct = {m_Matrix[0].m_x * b.m_x - m_Matrix[0]. * b.m_y}
		return dotProduct;

		Vec4<float>{a.quatVector.m_x, -a.quatVector.m_y, -a.quatVector.m_z, -a.quatVector.m_w},
		Vec4<float>{a.quatVector.m_y, a.quatVector.m_x, -a.quatVector.m_w, a.quatVector.m_z},
		Vec4<float>{a.quatVector.m_z, a.quatVector.m_w, a.quatVector.m_x, -a.quatVector.m_y},
		Vec4<float>{a.quatVector.m_w, -a.quatVector.m_z, a.quatVector.m_y, a.quatVector.m_x}
	}


};

#endif