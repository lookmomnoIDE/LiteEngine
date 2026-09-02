#include "VertexArray.h"
#include "VertexBuffer.h"
#include <glad/glad.h>


void l_checkError(std::string message)
{
	GLenum err = glGetError();
	if (err != GL_NO_ERROR)
	{
		std::cout << "GL Error in DrawElements: " << err << std::endl;
	}
	std::cout << message << std::endl;
}


VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_VAO);
}


VertexArray::VertexArray(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	glGenVertexArrays(1, &m_VAO);
	addBuffer(vb, layout);
}


VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_VAO);
}

////ERRROR BEGINS HERRRRRE LOGGING OFF
void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
	Bind();
	vb.Bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for(unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		l_checkError("before attrib");
		glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)(uintptr_t)offset);
		l_checkError("after attrib");
		glEnableVertexAttribArray(i);
		l_checkError("after enable");
		offset += element.count * element.typeSize;
	}
}


unsigned int VertexArray::getID()
{
	return m_VAO;
}


void VertexArray::Bind() const
{
	glBindVertexArray(m_VAO);
}

void VertexArray::unBind() const
{
	glBindVertexArray(0);
}
