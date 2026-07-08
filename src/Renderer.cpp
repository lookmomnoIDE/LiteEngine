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

	//Set Renderer ID!
	//m_RendererID = m_game->getUniqueRID();
	//std::cout << "Renderer ID: " << m_RendererID << std::endl;
	glViewport(0, 0, m_width, m_height);
	m_shader = new Shader("../src/cool.vert", "../src/beans.frag");
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	
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
	m_shader = nullptr;
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
		std::cout << "Drawing " << ib->GetCount() << " indices" << std::endl;
		glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_INT, 0);
		GLenum err = glGetError();
		if (err != GL_NO_ERROR)
		{
			std::cout << "GL Error in DrawElements: " << err << std::endl;
		}
	}
}

void Renderer::Square(const Entity e, Vec2<float> pos)
{
	/*EntityMemoryPool* pool = EntityMemoryPool::Instance();
	size_t id = e.getID();
	Cgrain& s = pool->getComponent<Cgrain>(id);
	float size = s.getSize();
	const Vec4<float>& color = {pool->getComponent<Csand>(id).getColor()};


	//Instance verticies as a part of Cgrain


	float halfX = (size * m_aspectRatio) / 2.0f;
	float halfY = size / 2.0f;

	float verts[] = 
	{
		pos.m_x - halfX,  pos.m_y - halfY,  -1.0f,  color.m_x, color.m_y, color.m_z, color.m_w,
		pos.m_x + halfX,  pos.m_y - halfY,  -1.0f,  color.m_x, color.m_y, color.m_z, color.m_w,
		pos.m_x - halfX,  pos.m_y + halfY,  -1.0f,  color.m_x, color.m_y, color.m_z, color.m_w,
		pos.m_x + halfX,  pos.m_y + halfY,  -1.0f,  color.m_x, color.m_y, color.m_z, color.m_w
	};*/

	//Create funtion to generate indicies
	//0, 1, 2, 3 	-> 4, 5, 6, 7 	-> 8, 9, 10, 11 ...
	//0 - 3 		->	4 - 7 		-> 8 - 11 		...

/*	unsigned int indices[] = 
	{
		0, 1, 3,   // top-left,  top-right,    bottom-right
		0, 3, 2    // top-left,  bottom-right, bottom-left
	};
*/
	//Take everythiing below this comment and make it its own function

	/*VertexArray va;
	VertexBuffer vb(verts, sizeof(verts));

	IndexBuffer ib(indices, 6); // Indices ok, 6 -> #number of active entities * 6

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(4);
	va.addBuffer(vb, layout);*/
	//Renderer::DrawElements(va, vb, ib);
}

//This fn simply take the setup out of renderer init puts it in its own fn. 
/*void Renderer::fallingSandMemory()
{
	std::cout << "Renderer: Pre buffer initialization" << std::endl;
	const auto& ME = m_game->getPool()->getMaxEnts();
	std::cout << "Renderer: Max Entities: " << ME << std::endl;
	size_t memSize = ME * sizeof(Vertex<float>) * 4; // 4 because 4 verts in a quad
	std::cout << "Renderer: Memory size: " << memSize << std::endl;
	vb = new VertexBuffer(nullptr, memSize);
	std::cout << "Renderer: VertexBuffer initialized" << std::endl;
	std::vector<unsigned int> indices = Renderer::genIndicies(ME);
	std::cout << "indices generated" << std::endl;
	ib = new IndexBuffer(&indices, (size_t)6*ME); // Indices ok, 6 -> #number of active entities * 6
	std::cout << "Index Buffer generated" << std::endl;
	std::cout << "Renderer: initialized" << std::endl;
	va = new VertexArray();
	layout = new VertexBufferLayout();
	layout->Push<float>(3);
	layout->Push<float>(4);
	va->addBuffer(*vb, *layout);
}*/


/*void Renderer::CGoLMemory()
{
	Grid g(this->getWidth(), this->getHeight(), 20, 4, 0);

	unsigned int col = g.getCols();
	unsigned int row = g.getRows();
	//unsigned int memSize = (col + row)*static_cast<unsigned int>(sizeof(Quad<float>));
	//vb = new VertexBuffer(nullptr, static_cast<size_t>(memSize));

	std::vector<Quad<float>> quads = g.fabGridLines();
	//vb = new VertexBuffer(&quads, sizeof(quads));
	//vb = new VertexBuffer(quads.data(), quads.size());
	std::vector<unsigned int> indices = Renderer::genIndicies(quads.size());
	ib = new IndexBuffer(&indices, (size_t)(indices.size() * sizeof(unsigned int)));
	vb = new VertexBuffer(quads.data(), quads.size() * sizeof(Quad<float>));
	//ib = new IndexBuffer(&indices, (size_t)6*(col*row));
	//ib = new IndexBuffer(&indices, (size_t)(6 * (col+row)));
	va = new VertexArray();
	layout = new VertexBufferLayout();
	layout->Push<float>(3);
	layout->Push<float>(4);
	va->addBuffer(*vb, *layout);
}*/

/*void Renderer::addGrid(std::vector<Quad<float>> quads)
{
	std::vector<unsigned int> indices = Renderer::genIndicies(quads.size());
	ib = new IndexBuffer(&indices, (size_t)(indices.size() * sizeof(unsigned int)));
	vb = new VertexBuffer(quads.data(), quads.size() * sizeof(Quad<float>));
	va = new VertexArray();
	layout = new VertexBufferLayout();
	layout->Push<float>(3);
	layout->Push<float>(4);
	va->addBuffer(*vb, *layout);
}*/


/*void Renderer::addQuadBuffer(std::vector<Quad<float>>& quads)
{
	std::vector<unsigned int> indices = Renderer::genIndicies(quads.size());
	std::cout << "Pre IB" << std::endl;
	m_IndexBuffers.push_back(std::make_unique<IndexBuffer>(&indices, (size_t)(indices.size()*sizeof(unsigned int))));
	std::cout << "Pre vb" << std::endl;
	m_VertexBuffers.push_back(std::make_unique<VertexBuffer>(quads.data(), quads.size() * sizeof(Quad<float>)));
	std::cout << "past VB" << std::endl;
	auto layout = std::make_unique<VertexBufferLayout>();
	layout->Push<float>(3);
	layout->Push<float>(4);
	m_Layouts.push_back(std::move(layout));
	m_VertexArrays.push_back(std::make_unique<VertexArray>(*m_VertexBuffers[m_bufferCount].get(), *m_Layouts[m_bufferCount].get()));
	m_bufferCount++;

}*/



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
	glBufferSubData(GL_ARRAY_BUFFER, 0, quads.size() * sizeof(Quad<float>), quads.data());
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