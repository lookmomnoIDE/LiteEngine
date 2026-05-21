#include "VertexArray.h"
#include "VertexBuffer.h"


VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_RendererID);
}
VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_RendererID);
}


void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	Bind();
	vb.Bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for(unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)(uintptr_t)offset);
		glEnableVertexAttribArray(i);
		offset += element.count * element.typeSize;
	}
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_RendererID);
}

void VertexArray::unBind() const
{
	glBindVertexArray(0);
}