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
	unsigned int m_vWidth, m_vHeight;
	std::vector<std::vector<unsigned int>> m_grid;	//m_Row, std::vector<unsigned int>(m_Col, m_DefaultState)
	std::vector<Quad<float>> m_Quads;

public:

	Grid()
	{

	}

	Grid(unsigned int vWidth, unsigned int vHeight, unsigned int size, unsigned int lineWidth, unsigned int state)
	:m_CellSize(size), m_LineWidth(lineWidth), m_DefaultState(state), m_vWidth(vWidth), m_vHeight(vHeight)
	{
		m_Col = vWidth/m_CellSize;
		m_Row = vHeight/m_CellSize;
		m_grid.resize(m_Row, std::vector<unsigned int>(m_Col, m_DefaultState));
		//fabGridLines();
	}

	//Fabricate grid vertices to deliver to the renderer. 
	std::vector<Quad<float>> fabGridLines() 
	{
		
		float hw = (m_LineWidth / 2.0f) / (float)m_vWidth;
		float hh = (m_LineWidth / 2.0f) / (float)m_vHeight;
		//float aspect = ((float)m_vHeight/(float)m_vWidth);

		// Vertical lines (X axis sweep)
		for (float i = 0; i <= m_Col; i++)
		{
		    float x = (i/ (float)m_Col) * 2.0f - 1.0f;           // NDC: -1 to 1
		                    // half-width in NDC
		    Quad<float> lineX;

		    lineX.v0.setVPosition(Vec3<float>((x - hw), -1.0f - hh, 1.0f));
		    lineX.v1.setVPosition(Vec3<float>((x + hw), -1.0f - hh, 1.0f));
		    lineX.v2.setVPosition(Vec3<float>((x - hw),  1.0f + hh, 1.0f));
		    lineX.v3.setVPosition(Vec3<float>((x + hw),  1.0f + hh, 1.0f));
		    lineX.v0.setVColor(Vec4<float>(0.0f, 0.0f, 0.0f, 1.0f));
			lineX.v1.setVColor(Vec4<float>(0.0f, 0.0f, 0.0f, 1.0f));
			lineX.v2.setVColor(Vec4<float>(0.0f, 0.0f, 0.0f, 1.0f));
			lineX.v3.setVColor(Vec4<float>(0.0f, 0.0f, 0.0f, 1.0f));
		    m_Quads.push_back(lineX);
		}

		// Horizontal lines (Y axis sweep)
		for (float j = 0; j <= m_Row; j++)
		{
		    float y = (j / (float)m_Row) * 2.0f - 1.0f;
		    
		    Quad<float> lineY;

		    lineY.v0.setVPosition(Vec3<float>((-1.0f - hw), y - hh, 1.0f));
		    lineY.v1.setVPosition(Vec3<float>(( 1.0f + hw), y - hh, 1.0f));
		    lineY.v2.setVPosition(Vec3<float>((-1.0f - hw), y + hh, 1.0f));
		    lineY.v3.setVPosition(Vec3<float>(( 1.0f + hw), y + hh, 1.0f));
		    lineY.v0.setVColor(Vec4<float>(0.0f, 0.0f, 0.0f, 1.0f));
			lineY.v1.setVColor(Vec4<float>(0.0f, 0.0f, 0.0f, 1.0f));
			lineY.v2.setVColor(Vec4<float>(0.0f, 0.0f, 0.0f, 1.0f));
			lineY.v3.setVColor(Vec4<float>(0.0f, 0.0f, 0.0f, 1.0f));
		    m_Quads.push_back(lineY);
		}
		return m_Quads;
	}
	
	std::vector<Quad<float>> getGridLines()
	{
		return m_Quads;
	}

	Vec2<float> getCenterOfCell(size_t e)
	{
		unsigned int i = (unsigned int)e % m_Col;
		unsigned int j = (unsigned int)e / m_Col;
	
		float ndcX = (((i * m_CellSize) + (m_CellSize / 2.0f)) / m_vWidth) * 2.0f - 1.0f;
	    float ndcY = 1.0f - (((j * m_CellSize) + (m_CellSize / 2.0f)) / m_vHeight) * 2.0f;

		//Vec2<float> pos((((i*m_CellSize)+(m_CellSize/2))/m_vWidth)-1, 1-(((j*m_CellSize)+(m_CellSize/2))/m_vHeight));
		Vec2<float> pos(ndcX, ndcY);
		return pos;
	}

	unsigned int getCellSize()
	{
		return m_CellSize;
	}

	unsigned int getCols()
	{
		return m_Col;
	}

	unsigned int getRows()
	{
		return m_Row;
	}

	unsigned int getLineWidth()
	{
		return m_LineWidth;
	}

	unsigned int getDefaultState()
	{
		return m_DefaultState;
	}

	unsigned int getWidth()
	{
		return m_vWidth;
	}

	unsigned int getHeight()
	{
		return m_vHeight;
	}

	void setCellSize(unsigned int size)
	{
		m_CellSize = size;
	}

	void setColRow(unsigned int vWidth, unsigned int vHeight)
	{
		m_vWidth = vWidth;
		m_vHeight = vHeight;
		m_Col = m_vWidth/m_CellSize;
		m_Row = m_vHeight/m_CellSize;
		m_grid.resize(m_Row, std::vector<unsigned int>(m_Col, m_DefaultState));
	}

	void setLineWidth(unsigned int lineWidth)
	{
		m_LineWidth = lineWidth;
	}

	void setDefaultState(unsigned int state)
	{
		m_DefaultState = state;
	}

	unsigned int getState(unsigned int row, unsigned int col)
	{
		return m_grid[row][col];
	}
};


#endif
