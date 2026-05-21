#include "IndexBuffer.h"
#include "GameEngine.h"


IndexBuffer::IndexBuffer(const std::vector<unsigned int>* data, size_t count)
	: m_Count(count)
{
	//std::cout << "IB prerenderer ID" << std::endl;
	//m_RendererID = GameEngine::Instance()->getRenderer()->getRID();
	//std::cout << "IB renderer ID established: " << m_RendererID << std::endl;
	glGenBuffers(1, &m_RendererID);
	std::cout << "IB genBuffers" << std::endl;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	std::cout << "IB Bind buffer" << std::endl;
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data->data(), GL_DYNAMIC_DRAW);
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
