#ifndef GRID_H
#define GRID_H

#include <vector>
#include <iostream>

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
	//std::vector<std::vector<unsigned int>> m_nextGrid;
	std::vector<Quad<float>> m_Quads;
	std::vector<unsigned int> m_Neighbors;

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
		//m_nextGrid.resize(m_Row, std::vector<unsigned int>(m_Col, m_DefaultState));
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

	/*Vec2<float> getCenterOfCell(size_t e)
	{
		std::cout << "inside grid center of cell fn" << std::endl;
		std::cout << m_Col << std::endl;
		unsigned int i = (unsigned int)e % m_Col;
		unsigned int j = (unsigned int)e / m_Col;
		std::cout << "col row index" << std::endl;
		float ndcX = (((i * m_CellSize) + (m_CellSize / 2.0f)) / m_vWidth) * 2.0f - 1.0f;
	    float ndcY = 1.0f - (((j * m_CellSize) + (m_CellSize / 2.0f)) / m_vHeight) * 2.0f;
	    std::cout << "ndcs" << std::endl;
		//Vec2<float> pos((((i*m_CellSize)+(m_CellSize/2))/m_vWidth)-1, 1-(((j*m_CellSize)+(m_CellSize/2))/m_vHeight));
		Vec2<float> pos(ndcX, ndcY);
		std::cout << "end of grid center of cell fn" << std::endl;
		return pos;
	}*/


	Vec2<float> getCenterOfCell(Vec2<unsigned int> index)
	{
		unsigned int i = index.m_x;
		unsigned int j = index.m_y;
		float ndcX = (((i * m_CellSize) + (m_CellSize / 2.0f)) / m_vWidth) * 2.0f - 1.0f;
		float ndcY = 1.0f - (((j * m_CellSize) + (m_CellSize / 2.0f)) / m_vHeight) * 2.0f;	    
		std::cout << "ndcs" << std::endl;
		//Vec2<float> pos((((i*m_CellSize)+(m_CellSize/2))/m_vWidth)-1, 1-(((j*m_CellSize)+(m_CellSize/2))/m_vHeight));
		Vec2<float> pos(ndcX, ndcY);
		std::cout << "end of grid center of cell fn" << std::endl;
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

	//Calculates row/col; do not try to set row/col manually 
	void setColRow(unsigned int vWidth, unsigned int vHeight)
	{
		std::cout << "renderer width: " << vWidth << " renderer height: " << vHeight << std::endl;
		m_vWidth = vWidth;
		m_vHeight = vHeight;
		std::cout << "grid width: " << m_vWidth << " grid height: " << m_vHeight << std::endl;
		m_Col = m_vWidth/m_CellSize;
		m_Row = m_vHeight/m_CellSize;
		std::cout << "Col: " << m_Col << " Row: " << m_Row << " CellSize: " << m_CellSize << std::endl;
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

	unsigned int getState(Vec2<unsigned int> index)
	{
		return m_grid[index.m_x][index.m_y];
	}

	void setState(unsigned int row, unsigned int col, unsigned int state)
	{
		m_grid[row][col] = state;
	}


	Vec2<unsigned int> makeIndexToroid(unsigned int row, unsigned int col)
	{
		//These conditionals make the map torodorial.
		if(row > m_Row)
		{
			row = 0;
		}
		else if(row < 0)
		{
			row = m_Row;
		}
		if(col > m_Col)
		{
			col = 0;
		}
		else if(col < 0)
		{
			col = m_Col;
		}
		Vec2<unsigned int> index(row, col);
		return index;
	}

	unsigned int wrap(int v, unsigned int max)
	{
	    return (v % (int)max + (int)max) % (int)max;
	}


	std::vector<unsigned int> countNeighbors()
	{
		m_Neighbors.clear();
		m_Neighbors.reserve(m_Row*m_Col);
		for(unsigned int j = 0; j < m_Row; j++)
		{
			for(unsigned int i = 0; i < m_Col; i++)
			{
				unsigned int state = 0;
				unsigned int neighborCount = 0;
				state = getState(wrap(j+1, m_Row), wrap(i-1, m_Col));			// upper left
				if(state == 1)
				{
					neighborCount++;
					state = 0;
				}
				state = getState(wrap(j+1, m_Row), wrap(i, m_Col));
				if(state == 1)
				{
					neighborCount++;
					state = 0;
				}			// above
				state = getState(wrap(j+1, m_Row), wrap(i+1, m_Col));
				if(state == 1)
				{
					neighborCount++;
					state = 0;
				}			// upper right
				state = getState(wrap(j, m_Row), wrap(i-1, m_Col));
				if(state == 1)
				{
					neighborCount++;
					state = 0;
				}			// left
				state = getState(wrap(j, m_Row), wrap(i+1, m_Col));
				if(state == 1)
				{
					neighborCount++;
					state = 0;
				}			// right
				state = getState(wrap(j-1, m_Row), wrap(i-1, m_Col));
				if(state == 1)
				{
					neighborCount++;
					state = 0;
				}			// lower left
				state = getState(wrap(j-1,m_Row), wrap(i, m_Col));
				if(state == 1)
				{
					neighborCount++;
					state = 0;
				}			// below
				state = getState(wrap(j-1,m_Row), wrap(i+1, m_Col));
				if(state == 1)
				{
					neighborCount++;
					state = 0;
				}			// lower right
				m_Neighbors.push_back(neighborCount);
			}
		}
		return m_Neighbors;
	}

};


#endif
