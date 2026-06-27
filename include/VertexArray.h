#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"



class VertexArray
{

	unsigned int m_RendererID;

public:
	VertexArray();
	VertexArray(const VertexBuffer& vb, const VertexBufferLayout& layout);
	~VertexArray();

	void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

	void Bind() const;

	void unBind() const;
};