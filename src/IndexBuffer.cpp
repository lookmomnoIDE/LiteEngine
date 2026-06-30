#include "IndexBuffer.h"
#include "GameEngine.h"



IndexBuffer::IndexBuffer(const unsigned int* data, size_t count)
	: m_Count(count)
{
	glGenBuffers(1, &m_RendererID);
	std::cout << "IB genBuffers" << std::endl;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	std::cout << "IB Bind buffer" << std::endl;
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(unsigned int), data, GL_DYNAMIC_DRAW);
	std::cout << "IB buffer data set" << std::endl;
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void IndexBuffer::unBind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int IndexBuffer::GetCount() const
{
	return m_Count;
}
