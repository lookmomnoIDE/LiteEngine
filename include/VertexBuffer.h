#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>



class VertexBuffer
{
	unsigned int m_RendererID;
public:
	VertexBuffer(const void* data, size_t size);
	~VertexBuffer();

	void Bind() const;
	void unBind() const;
};