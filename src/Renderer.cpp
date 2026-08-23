#include "Renderer.h"
#include "GameEngine.h"
#include "InputHandler.h"
#include "Vertex.h"
#include "Quad.h"
#include "grid.h"


#include <iostream>

Renderer::Renderer()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	m_window = glfwCreateWindow(m_width, m_height, "LiteEngine", NULL, NULL);
	if (m_window == NULL)
	{
		std::cout << "ERROR: " << "GLFW window failed!" << std::endl;
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window!");
	}
	glfwMakeContextCurrent(m_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "ERROR: " << "Glad failed!" << std::endl;
		throw std::runtime_error("ERROR: Failed to initialize GLAD!");
	}

	//INIT SCREEN DIMENSIONS
	int winWidth, winHeight;
	glfwGetWindowSize(m_window, &winWidth, &winHeight);
	m_width = winWidth;
	m_height = winHeight;
	m_aspectRatio = (float)m_height/(float)m_width;
	std::cout << m_aspectRatio << std::endl;
	m_game = GameEngine::Instance();


	glViewport(0, 0, m_width, m_height);
	m_shader = new Shader("../src/shaders/cool.vert", "../src/shaders/beans.frag");
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	m_assetMan = m_game->getAssetMan();
	std::cout << "loading texture" << std::endl;
	m_assetMan->addTexture("default", "C:/projects/LiteEngineV003/res/textures/default.png");
	std::cout << "texture loaded" << std::endl;
	//m_shader->setInt("texture0", 0);

}

Renderer::~Renderer()
{
	delete m_shader;
	delete vb;
	delete ib;
	delete va;
	delete layout;
	glfwTerminate();
}

void Renderer::Init()
{
	
}

Shader* Renderer::loadShader(std::string vertex, std::string fragment)
{
	delete m_shader;
	m_shader = new Shader(vertex.c_str(), fragment.c_str());
	m_shader->use();
	return m_shader; 
}

GLFWwindow* Renderer::getWindow()
{
	return m_window;
}

void Renderer::Draw(const VertexArray& va, const VertexBuffer& vb) const
{
	m_shader->use();
	va.Bind();
	vb.Bind();
	glDrawArrays(GL_TRIANGLES, 0, sizeof(vb));
}

/*
void Renderer::DrawElements() const
{
	m_shader->use();
	va->Bind();
	vb->Bind();
	ib->Bind();
	glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_INT, 0);
}*/

void Renderer::DrawElements() const 
{
	m_shader->use();
	for (auto i = 0; i < m_bufferCount; i++)
	{
		auto va = m_VertexArrays[i].get();
		va->Bind();
		//auto vb = m_VertexBuffers[i].get();
		//vb->Bind();
		auto ib = m_IndexBuffers[i].get();
		ib->Bind();
		auto count = ib->GetCount();
		//std::cout << "Drawing " << count << " indices" << std::endl;
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
		GLenum err = glGetError();
		if (err != GL_NO_ERROR)
		{
			std::cout << "GL Error in DrawElements: " << err << std::endl;
		}
	}
}


void Renderer::addQuadBufferT(std::vector<Quad<float>>& quads)
{
	std::vector<unsigned int> indices = Renderer::genIndicies(quads.size());

	m_VertexBuffers.push_back(std::make_unique<VertexBuffer>(quads.data(), quads.size() * sizeof(Quad<float>)));

	auto layout = std::make_unique<VertexBufferLayout>();
	layout->Push<float>(3);
	layout->Push<float>(4);
	layout->Push<float>(2);
	m_Layouts.push_back(std::move(layout));

	m_VertexArrays.push_back(std::make_unique<VertexArray>(
		*m_VertexBuffers[m_bufferCount],
		*m_Layouts[m_bufferCount]
	));

	// VAO is now bound from its constructor — attach IBO into it
	m_IndexBuffers.push_back(std::make_unique<IndexBuffer>(indices.data(), indices.size()));

	m_bufferCount++;
}


void Renderer::addQuadBuffer(std::vector<Quad<float>>& quads)
{
	std::vector<unsigned int> indices = Renderer::genIndicies(quads.size());

	m_VertexBuffers.push_back(std::make_unique<VertexBuffer>(quads.data(), quads.size() * sizeof(Quad<float>)));

	auto layout = std::make_unique<VertexBufferLayout>();
	layout->Push<float>(3);
	layout->Push<float>(4);
	m_Layouts.push_back(std::move(layout));

	m_VertexArrays.push_back(std::make_unique<VertexArray>(
		*m_VertexBuffers[m_bufferCount],
		*m_Layouts[m_bufferCount]
	));

	// VAO is now bound from its constructor — attach IBO into it
	m_IndexBuffers.push_back(std::make_unique<IndexBuffer>(indices.data(), indices.size()));

	m_bufferCount++;
}


void Renderer::addCellBuffer(std::vector<CCell>& quads)
{
	std::vector<unsigned int> indices = Renderer::genIndicies(quads.size());

	m_VertexBuffers.push_back(std::make_unique<VertexBuffer>(quads.data(), quads.size() * sizeof(Quad<float>)));

	auto layout = std::make_unique<VertexBufferLayout>();
	layout->Push<float>(3);
	layout->Push<float>(4);
	m_Layouts.push_back(std::move(layout));

	m_VertexArrays.push_back(std::make_unique<VertexArray>(
		*m_VertexBuffers[m_bufferCount],
		*m_Layouts[m_bufferCount]
	));

	// VAO is now bound from its constructor — attach IBO into it
	m_IndexBuffers.push_back(std::make_unique<IndexBuffer>(indices.data(), indices.size()));

	m_bufferCount++;
}



void Renderer::updateQuadBuffer(size_t index, std::vector<Quad<float>>& quads)
{
	m_VertexBuffers[index]->Bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0 , quads.size() * sizeof(Quad<float>), quads.data());
}


void Renderer::SwapBuffers()
{
	glfwSwapBuffers(m_window);
}


void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}


void Renderer::setViewport(int startx, int starty, int vWidth, int vHeight)
{
	glViewport(startx, starty, vWidth, vHeight);
}


int Renderer::getWidth() const
{
	return m_width;
}

int Renderer::getHeight() const 
{
	return m_height;
}	


std::vector<unsigned int> Renderer::genIndicies(unsigned int maxEntities)
{
	std::vector<unsigned int> indices;
	indices.reserve((size_t)maxEntities*6);
	Vec3<unsigned int> firstTriangle = {0, 1, 3};
	Vec3<unsigned int> secondTriangle = {0, 3, 2};
	Vec3<unsigned int> offset = {4, 4, 4};

	for (unsigned int i = 0; i < maxEntities; i++)
	{
		indices.push_back(firstTriangle.m_x);//, firstTriangle.m_y, firstTriangle.m_z );
		indices.push_back(firstTriangle.m_y);
		indices.push_back(firstTriangle.m_z);
		indices.push_back(secondTriangle.m_x);//, secondTriangle.m_y, secondTriangle.m_z);
		indices.push_back(secondTriangle.m_y);
		indices.push_back(secondTriangle.m_z);
		firstTriangle += offset;
		secondTriangle += offset;
	}

	return indices;
}

VertexBuffer& Renderer::getVB()
{
	return *vb;
}

unsigned int Renderer::getBufferCount()
{
	return m_bufferCount;
}


// configure VAO/VBO for texture quads
// -----------------------------------
//glGenVertexArrays(1, &VAO);
//glGenBuffers(1, &VBO);
//glBindVertexArray(VAO);
//glBindBuffer(GL_ARRAY_BUFFER, VBO);
//glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
//glEnableVertexAttribArray(0);
//glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
//glBindBuffer(GL_ARRAY_BUFFER, 0);
//glBindVertexArray(0);


// render line of text
// -------------------
void Renderer::RenderText(std::string text, float x, float y, std::string fontName, float scale = 1.0f)
{
	// activate corresponding render state	
	std::cout << "in render text" << std::endl;
	Shader* shader = loadShader("../src/shaders/text.vert", "../src/shaders/text.frag");
	std::cout << "text shader loaded!" << std::endl;
	shader->use();
	unsigned int m_texID = m_assetMan->getFont(fontName)->m_texID;
	glActiveTexture(GL_TEXTURE0 + m_texID); 
	std::cout << "active texture set to: " << m_texID << std::endl;
	glBindVertexArray(m_VertexArrays[m_texID]->getID());
	// disable byte-alignment restriction
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// iterate through all characters
	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++) 
	{
		auto characterMap = m_assetMan->getFont(fontName)->m_Characters;
		Character* ch = characterMap[*c];
		//Character ch = Characters[*c];

		float xpos = x + ch->m_bearing.m_x * scale;
		float ypos = y - (ch->m_size.m_y - ch->m_bearing.m_y) * scale;

		float w = ch->m_size.m_x * scale;
		float h = ch->m_size.m_y * scale;
		// update VBO for each character
		float vertices[6][4] = {
			{ xpos,     ypos + h,   0.0f, 0.0f },            
			{ xpos,     ypos,       0.0f, 1.0f },
			{ xpos + w, ypos,       1.0f, 1.0f },

			{ xpos,     ypos + h,   0.0f, 0.0f },
			{ xpos + w, ypos,       1.0f, 1.0f },
			{ xpos + w, ypos + h,   1.0f, 0.0f }           
		};
		// render glyph texture over quad
		glBindTexture(GL_TEXTURE_2D, m_texID);
		// update content of VBO memory
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffers[m_texID]->getID());
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		// render quad
		glDrawArrays(GL_TRIANGLES, 0, 6);
		// now advance cursors for next glyph (note that advance is number of 1/64 pixels)
		x += (ch->Advance >> 6) * scale; // bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
	}
	//REMEBER TO COMMENT OUT AFTER TESTING!!!!!!!!!!!
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}