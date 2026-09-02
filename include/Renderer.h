#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>
#include <array>
#include <vector> 
#include "tQuad.h"
#include "Quad.h"

//#include "EntityFactory.h" // TEMPORARY REMOVE AFTER COMMANDS
class GameEngine;
class InputHandler;
class assetMan;
class Shader;
class VertexBuffer;
class VertexArray;
class IndexBuffer;
class VertexBufferLayout;
class Renderer
{
	unsigned int m_width = 1920;
	unsigned int m_height = 1050; 
	float m_aspectRatio;
	//unsigned int m_RendererID;
	GameEngine* m_game = nullptr;
	Shader* m_shader = nullptr;
	GLFWwindow* m_window = nullptr;
	assetMan* m_assetMan = nullptr;
	
	unsigned int m_textBufferIndex;
	unsigned int m_quadBufferIndex;
	unsigned int m_tQuadBufferIndex;
	unsigned int m_UIBufferIndex;
	unsigned int m_gridBufferIndex;

	//rewrite
	std::vector<std::unique_ptr<VertexBuffer>> 			m_VertexBuffers;
	std::vector<std::unique_ptr<VertexArray>>  			m_VertexArrays;
	std::vector<std::unique_ptr<IndexBuffer>>  			m_IndexBuffers;
	std::vector<std::unique_ptr<VertexBufferLayout>>	m_Layouts;
	std::vector<unsigned int>							m_quadBuffers;
	unsigned int m_bufferCount = 0;


public:
	Renderer();
	~Renderer();
	void Init();
	Shader* loadShader(std::string vertex, std::string fragment);
	GLFWwindow* getWindow();
	void drawTQuadBuffer();
	void drawQuadBuffer();
	void drawGridBuffer();
	void drawUIBuffer();
	void DrawElements();
	void DrawElements(std::string texture);
	void initUIBuffer(size_t size);
	void addUIBuffer(std::vector<tQuad<float>>& quads);
	void initTQuadBuffer(size_t size);
	void addQuadBufferT(std::vector<tQuad<float>>& quads);
	void initQuadBuffer(size_t size);
	void addQuadBuffer(std::vector<Quad<float>>& quads);
	void initGridBuffer(size_t size);
	void addGridBuffer(std::vector<Quad<float>>& quads);
	void initTextBuffer(size_t maxChars);
	void addTextBuffer(std::vector<float> vertices);
	void updateQuadBufferT(std::vector<tQuad<float>>& quads);
	void updateQuadBuffer(std::vector<Quad<float>>& quads);
	void updateTextBuffer(std::vector<float>& vertices);
	void updateGridBuffer(std::vector<Quad<float>>& vertices);
	void updateUIBuffer(std::vector<tQuad<float>>& vertices);
	void SwapBuffers();
	void Clear();
	void setViewport(int startx, int starty, int vWidth, int vHeight);
	int getWidth() const;
	int getHeight() const;
	std::vector<unsigned int> genIndicies(unsigned int maxEntities);
	unsigned int getBufferCount();
	void drawText(std::string text, float x, float y, std::string fontName, float scale, Color& color);
};

#endif