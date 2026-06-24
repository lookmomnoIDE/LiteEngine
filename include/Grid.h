#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Vec2.h"
#include "Vec3.h"
#include "Quad.h"


class Grid {
public:
	unsigned int m_Col;
	unsigned int m_Row;
	unsigned int m_CellSize;
	unsigned int m_LineWidth;
	unsigned int m_DefaultState = 0;
	std::vector<std::vector<unsigned int>> grid;	//m_Row, std::vector<unsigned int>(m_Col, m_DefaultState)
	std::vector<Quad<float>> m_Quads;

public:

	Grid(unsigned int vWidth, unsigned int vHeight, unsigned int size, unsigned int lineWidth, unsigned int state)
	:m_CellSize(size), m_LineWidth(lineWidth), m_DefaultState(state)
	{
		m_Col = vWidth/m_CellSize;
		m_Row = vHeight/m_CellSize;
		grid.resize(m_Row, std::vector<unsigned int>(m_Col, m_DefaultState));
		fabGridLines();
	}

	//Fabricate grid vertices to deliver to the renderer. 
	std::vector<Quad<float>> fabGridLines() 
	{
		for(float i = 0; i <= m_Row; i++)
		{
			Quad<float> lineX;
			lineX.v0.setVPosition(Vec3<float>((i*m_CellSize-m_LineWidth), 1, 1));
			lineX.v1.setVPosition(Vec3<float>((i*m_CellSize+m_LineWidth), 1, 1));
			lineX.v2.setVPosition(Vec3<float>((i*m_CellSize-m_LineWidth), -1, 1));
			lineX.v3.setVPosition(Vec3<float>((i*m_CellSize+m_LineWidth), -1, 1));

			lineX.v0.setVColor(Vec4<float>(255.0f, 255.0f, 255.0f, 255.0f));
			lineX.v1.setVColor(Vec4<float>(255.0f, 255.0f, 255.0f, 255.0f));
			lineX.v2.setVColor(Vec4<float>(255.0f, 255.0f, 255.0f, 255.0f));
			lineX.v3.setVColor(Vec4<float>(255.0f, 255.0f, 255.0f, 255.0f));

			m_Quads.push_back(lineX);
		}
		for(float j = 0; j<= m_Col; j++)
		{
			Quad<float> lineY;
			lineY.v0.setVPosition(Vec3<float>( -1,(j*m_CellSize-m_LineWidth), 1));
			lineY.v1.setVPosition(Vec3<float>( -1,(j*m_CellSize+m_LineWidth), 1));
			lineY.v2.setVPosition(Vec3<float>( 1,(j*m_CellSize-m_LineWidth), 1));
			lineY.v3.setVPosition(Vec3<float>( 1,(j*m_CellSize+m_LineWidth), 1));

			lineY.v0.setVColor(Vec4<float>(255.0f, 255.0f, 255.0f, 255.0f));
			lineY.v1.setVColor(Vec4<float>(255.0f, 255.0f, 255.0f, 255.0f));
			lineY.v2.setVColor(Vec4<float>(255.0f, 255.0f, 255.0f, 255.0f));
			lineY.v3.setVColor(Vec4<float>(255.0f, 255.0f, 255.0f, 255.0f));
			m_Quads.push_back(lineY);
		}
		return m_Quads;
	}
	std::vector<Quad<float>> getGridLines()
	{
		return m_Quads;
	}





};


#endif