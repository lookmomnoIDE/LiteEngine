#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "VertexArray.h"
#include "shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Entity.h"
#include "EntityMemoryPool.h"


class Renderer
{
	int m_width = 1920;
	int m_height = 1050; 
	float aspectRatio = m_width/m_height;
	double m_xpos, m_ypos;
	Shader* m_shader;
	GLFWwindow* m_window;

public:
	Renderer();
	~Renderer();
	Shader* loadShader(std::string vertex, std::string fragment);
	GLFWwindow* getWindow();
	void Draw(const VertexArray& va, const VertexBuffer& vb) const;
	void DrawElements(const VertexArray& va, const VertexBuffer& vb, const IndexBuffer& ib) const;
	void Square(const Entity e, std::vector<float> pos);
	void Clear();



};
