#include "VertexBuffer.h"
#include "GameEngine.h"
#include "Renderer.h"


VertexBuffer::VertexBuffer(const void* data, size_t size)
{
	//std::cout << "Pre renderer ID" << std::endl;
	//m_RendererID = GameEngine::Instance()->getRenderer()->getRID();
	//std::cout << "Renderer ID established" << std::endl;
	glGenBuffers(1, &m_RendererID);
	std::cout << "General Buffers" << std::endl;
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	std::cout << "Binded buffer" << std::endl;
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
	std::cout << "Buffer data / size set." << std::endl;
	//glBufferData static -> dynamic

}
VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}


unsigned int VertexBuffer::getID()
{
	return m_RendererID;	
}

 
void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}
void VertexBuffer::unBind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}