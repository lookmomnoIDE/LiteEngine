#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include "Renderer.h"

class IndexBuffer
{
	unsigned int m_RendererID;
	unsigned int m_Count;

public:
	IndexBuffer(const unsigned int* data, unsigned int count);

	~IndexBuffer();

	void Bind() const;

	void unBind() const;

	unsigned int GetCount() const;
};