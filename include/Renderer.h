#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "VertexArray.h"
#include "shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Entity.h"
#include "EntityMemoryPool.h"


//#include "EntityFactory.h" // TEMPORARY REMOVE AFTER COMMANDS
class GameEngine;
class InputHandler;


class Renderer
{
	int m_width = 1920;
	int m_height = 1050; 
	float m_aspectRatio;
	unsigned int m_RendererID;
	GameEngine* m_game = nullptr;
	Shader* m_shader = nullptr;
	GLFWwindow* m_window = nullptr;

public:
	Renderer();
	~Renderer();
	void Init();
	Shader* loadShader(std::string vertex, std::string fragment);
	GLFWwindow* getWindow();
	void Draw(const VertexArray& va, const VertexBuffer& vb) const;
	void DrawElements(const VertexArray& va, const VertexBuffer& vb, const IndexBuffer& ib) const;
	void Square(const Entity e, std::vector<float> pos);
	void SwapBuffers();
	void Clear();
	int getWidth() const;
	int getHeight() const;
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	std::vector<double> getMousePosition();
	unsigned int getRID();
};

#endif