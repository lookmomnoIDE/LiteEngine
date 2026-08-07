#ifndef QMATH_H
#define QMATH_H

class QMath
{
public:
	Vec4<float> doRotation(Vec4<float> quat, Vec4<float> normalVector)
	{

	}

	Vec4<float> dotProduct(Vec4<float> leftQuat, Vec4<float> rightQuat)
	{
		Vec4<float> product = {leftQuat.m_x}
	}

	Vec4<float> multiplyQuaternions(Vec4<float> leftQuat, Vec4<float> rightQuat)
	{
		float a = leftQuat.m_x, b = leftQuat.m_y, c = leftQuat.m_z, d = leftQuat.m_w, e = rightQuat.m_x, f = rightQuat.m_y, g = rightQuat.m_z, h = rightQuat.m_w;
		Vec4<float> product = {a*e - b*f - c*g - d*h, a*f + b*e + c*h - d*g, a*g - b*h + c*e + d*f, a*h + b*g - c*f +d*e};
		return product;
	}
};

#endif