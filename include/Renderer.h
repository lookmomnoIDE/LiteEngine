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
#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"


//#include "EntityFactory.h" // TEMPORARY REMOVE AFTER COMMANDS
class GameEngine;
class InputHandler;


class Renderer
{
	unsigned int m_width = 1920;
	unsigned int m_height = 1050; 
	float m_aspectRatio;
	//unsigned int m_RendererID;
	GameEngine* m_game = nullptr;
	Shader* m_shader = nullptr;
	GLFWwindow* m_window = nullptr;
	VertexBuffer* vb = nullptr;
	IndexBuffer* ib = nullptr;
	VertexArray* va = nullptr;
	VertexBufferLayout* layout = nullptr;

public:
	Renderer();
	~Renderer();
	void Init();
	Shader* loadShader(std::string vertex, std::string fragment);
	GLFWwindow* getWindow();
	void Draw(const VertexArray& va, const VertexBuffer& vb) const;
	void DrawElements() const;
	void Square(const Entity e, Vec2<float> pos);
	void fallingSandMemory();
	void CGoLMemory();
	void SwapBuffers();
	void Clear();
	void setViewport(int startx, int starty, int vWidth, int vHeight);
	int getWidth() const;
	int getHeight() const;

	std::vector<unsigned int> genIndicies(unsigned int maxEntities);
	VertexBuffer& getVB();
};

#endif