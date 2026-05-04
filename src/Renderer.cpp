#include "Renderer.h"


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

	glViewport(0, 0, m_width, m_height);
	m_shader = new Shader("../src/cool.vert", "../src/beans.frag");
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

Renderer::~Renderer()
{
	delete m_shader;
	glfwTerminate();
}

Shader* Renderer::loadShader(std::string vertex, std::string fragment)
{
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


void Renderer::DrawElements(const VertexArray& va, const VertexBuffer& vb, const IndexBuffer& ib) const
{
	m_shader->use();
	va.Bind();
	vb.Bind();
	ib.Bind();
	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0);
}

void Renderer::Square(const Entity e, std::vector<float> pos)
{
	EntityMemoryPool& pool = EntityMemoryPool::Instance();
	//Entity player = pool.addEntity("player");
	size_t id = e.getID(); // however your Entity exposes its index
	pool.getComponent<CTransform>(id).setPos(pos);
	float xRatio = 1920.0f/1050.0f;
	Cgrain& s = pool.getComponent<Cgrain>(id);
	float size = s.getSize();
	std::vector<float> color = {pool.getComponent<Csand>(id).getColor()};


	float halfX = (size / xRatio) / 2.0f;
	float halfY = size / 2.0f;
	//std::cout <<"halfX: "<< halfX << ", " <<"halfY: " << halfY << std::endl;

	float verts[] = {
    pos[0] - halfX,  pos[1] - halfY,  -1.0f,  color[0], color[1], color[2], color[3],
    pos[0] + halfX,  pos[1] - halfY,  -1.0f,  color[0], color[1], color[2], color[3],
    pos[0] - halfX,  pos[1] + halfY,  -1.0f,  color[0], color[1], color[2], color[3],
    pos[0] + halfX,  pos[1] + halfY,  -1.0f,  color[0], color[1], color[2], color[3]
	};


	unsigned int indices[] = {
    0, 1, 3,   // top-left,  top-right,    bottom-right
    0, 3, 2    // top-left,  bottom-right, bottom-left
	};


	VertexArray va;
	VertexBuffer vb(verts, sizeof(verts));

	IndexBuffer ib(indices, 6);

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(4);
	va.addBuffer(vb, layout);
	Renderer::DrawElements(va, vb, ib);
}

void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}


