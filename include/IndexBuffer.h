#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
//#include "Renderer.h"

class IndexBuffer
{
	unsigned int m_RendererID;
	unsigned int m_Count;

public:
	IndexBuffer(const std::vector<unsigned int>* data, size_t count);

	~IndexBuffer();

	void Bind() const;

	void unBind() const;

	unsigned int GetCount() const;
};