#include "VertexBufferLayout.h"

template <typename T> inline GLenum GLType();
template <> inline GLenum GLType<float>()         { return GL_FLOAT; }
template <> inline GLenum GLType<unsigned int>()  { return GL_UNSIGNED_INT; }
template <> inline GLenum GLType<unsigned char>() { return GL_UNSIGNED_BYTE; }

VertexBufferLayout::VertexBufferLayout(){}
VertexBufferLayout::~VertexBufferLayout(){}


const std::vector<VertexBufferLayout::VertexBufferElement>& VertexBufferLayout::GetElements() const 
{
	return m_Elements;
}


unsigned int VertexBufferLayout::GetStride() const 
{
	return m_Stride;
}

// Push specializations
template <>
void VertexBufferLayout::Push<float>(unsigned int count)
{
    m_Elements.push_back({GLType<float>(), count, GL_FALSE, sizeof(float)});
    m_Stride += count * sizeof(float);
}

template <>
void VertexBufferLayout::Push<unsigned int>(unsigned int count)
{
    m_Elements.push_back({GLType<unsigned int>(), count, GL_FALSE, sizeof(unsigned int)});
    m_Stride += count * sizeof(unsigned int);
}

template <>
void VertexBufferLayout::Push<unsigned char>(unsigned int count)
{
    m_Elements.push_back({GLType<unsigned char>(), count, GL_FALSE, sizeof(unsigned char)});
    m_Stride += count * sizeof(unsigned char);
}


