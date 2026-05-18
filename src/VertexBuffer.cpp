#include "VertexBuffer.h"
#include "GameEngine.h"


VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	m_RendererID = GameEngine::Instance()->getRenderer()->getRID();
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
	//glBufferData static -> dynamic

}
VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_RendererID);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}
void VertexBuffer::unBind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}