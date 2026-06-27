#pragma once

#include <vector>
#include <glad/glad.h>



class VertexBufferLayout
{
public:


	struct VertexBufferElement
	{
		unsigned int type;
		unsigned int count;
		bool normalized = false;
		unsigned int typeSize;
	};

private:

	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride = 0;

public:


	VertexBufferLayout();
	~VertexBufferLayout();

	
	template <typename T> VertexBufferLayout* Push(unsigned int count);


	const std::vector<VertexBufferElement>& GetElements() const;
	unsigned int GetStride() const;
};

