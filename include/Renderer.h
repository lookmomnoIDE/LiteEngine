#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "VertexArray.h"
#include "shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"


class Renderer
{

public:

	void Draw(const VertexArray& va, const VertexBuffer& vb, const Shader& shader) const;
	void DrawElements(const VertexArray& va, const VertexBuffer& vb, const IndexBuffer& ib, const Shader& shader) const;
	void Clear();


};
