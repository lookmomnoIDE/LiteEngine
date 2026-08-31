#include "Renderer.h"
#include "GameEngine.h"
#include "InputHandler.h"
#include "Vertex.h"
#include "Quad.h"
#include "grid.h"


#include <iostream>
float projection[16] = {
	2.0f/1920, 	0.0f,		0.0f,	-1.0f,   // column 0
	0.0f, 		2.0f/1050, 	0.0f,  	-1.0f,   // column 1
	0.0f, 		0.0f, 		-1.0f, 	0.0f,   // column 2
	0.0f, 		0.0f, 		0.0f, 	1.0f    // column 3 (translation)
};


void checkError(std::string message)
{
	GLenum err = glGetError();
	if (err != GL_NO_ERROR)
	{
		std::cout << "GL Error in DrawElements: " << err << std::endl;
	}
	std::cout << message << std::endl;
}


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
	//checkError("before load");
	m_shader = new Shader("../src/shaders/cool.vert", "../src/shaders/beans.frag");
	//checkError("after load");
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	//glEnable(GL_CULL_FACE);
	//checkError("after cull");
	glEnable(GL_BLEND);
	//checkError("after blend");
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//checkError("after blendfunc");
	m_assetMan = m_game->getAssetMan();
	std::cout << "loading texture" << std::endl;
	m_assetMan->addTexture("default", "C:/projects/LiteEngineV003/res/textures/default.png");
	//checkError("after texture");
	std::cout << "texture loaded" << std::endl;
	initTextBuffer(128);
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



void Renderer::DrawElements() 
{
	Shader* m_shader = loadShader("../src/shaders/cool.vert", "../src/shaders/beans.frag");
    m_shader->use();
    //glActiveTexture(0);
	for (auto i : m_quadBuffers)
	{
		auto va = m_VertexArrays[i].get();
		va->Bind();
		auto vb = m_VertexBuffers[i].get();
		vb->Bind();
		//-1 because text buffer is loaded first and doesnt have an index buffer so index is off by one. may dig into this in the futre
		//hope thats not foreshadowing. 
		auto ib = m_IndexBuffers[i-1].get();
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


void Renderer::DrawElements(std::string texture) 
{
	//checkError("before load");
	Shader* m_shader = loadShader("../src/shaders/texturedCool.vert", "../src/shaders/texturedBeans.frag");
	//checkError("after load");
    m_shader->use();
    //checkError("after use");
    m_assetMan->getTexture(texture)->Bind();
    //checkError("after bind");
    
    //glActiveTexture();
	for (auto i : m_quadBuffers)	
	{

		auto va = m_VertexArrays[i].get();
		va->Bind();
		auto vb = m_VertexBuffers[i].get();
		vb->Bind();
		//-1 because text buffer is loaded first and doesnt have an index buffer so index is off by one. may dig into this in the futre
		//hope thats not foreshadowing. 
		auto ib = m_IndexBuffers[i-1].get();
		ib->Bind();
		auto count = ib->GetCount();
		//std::cout << "Drawing " << count << " indices" << std::endl;
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);

	}
}



void Renderer::addQuadBufferT(std::vector<tQuad<float>>& quads)
{
	std::vector<unsigned int> indices = Renderer::genIndicies(quads.size());

	m_VertexBuffers.push_back(std::make_unique<VertexBuffer>(quads.data(), quads.size() * sizeof(tQuad<float>)));

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
	m_quadBuffers.push_back(m_bufferCount);
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
	m_quadBuffers.push_back(m_bufferCount);
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
	m_quadBuffers.push_back(m_bufferCount);
	m_bufferCount++;
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


void Renderer::initTextBuffer(size_t maxChars)
{
    std::vector<float> dummy(maxChars * 24, 0.0f); // 6 verts * 4 floats per char
    addTextBuffer(dummy); // allocates buffer at max capacity, GL_DYNAMIC_DRAW ideally
}


void Renderer::addTextBuffer(std::vector<float> vertices)
{
	//std::vector<unsigned int> indices = Renderer::genIndicies(vertices.size());

	m_VertexBuffers.push_back(std::make_unique<VertexBuffer>(vertices.data(), vertices.size() * sizeof(float)));

	auto layout = std::make_unique<VertexBufferLayout>();
	layout->Push<float>(4);
	m_Layouts.push_back(std::move(layout));

	m_VertexArrays.push_back(std::make_unique<VertexArray>(
		*m_VertexBuffers.back(),
    	*m_Layouts.back()
	));

	m_textBufferIndex = m_bufferCount;
	m_bufferCount++;
}



void Renderer::updateQuadBuffer(size_t index, std::vector<Quad<float>>& quads)
{
	m_VertexBuffers[index]->Bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0 , quads.size() * sizeof(Quad<float>), quads.data());
}

void Renderer::updateTextBuffer(std::vector<float>& vertices)
{
	m_VertexBuffers[m_textBufferIndex]->Bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0 , vertices.size() * sizeof(float), vertices.data());
}


void Renderer::SwapBuffers()
{
	glfwSwapBuffers(m_window);
}


void Renderer::Clear()
{
	//checkError("before");
	glClear(GL_COLOR_BUFFER_BIT);
	//checkError("after");
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
	std::cout << maxEntities << std::endl;
	indices.reserve((size_t)maxEntities*6);
	Vec3<unsigned int> firstTriangle = {0, 1, 3};//{0, 1, 3};
	Vec3<unsigned int> secondTriangle = {0, 3, 2};//{0, 3, 2};
	Vec3<unsigned int> offset = {4, 4, 4};

	for (unsigned int i = 0; i < maxEntities; i++)
	{
		indices.push_back(firstTriangle.m_x);
		indices.push_back(firstTriangle.m_y);
		indices.push_back(firstTriangle.m_z);
		indices.push_back(secondTriangle.m_x);
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

//render text
/*std::vector<float> Renderer::RenderText(std::string text, float x, float y, std::string fontName, float scale = 1.0f)
{
	std::vector<float> verts;
	verts.reserve(text.length()*24);
	
	// iterate through all characters
	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++) 
	{
		auto characterMap = m_assetMan->getFont(fontName)->getCharMap();
		std::cout << *c << std::endl;
		Character* ch = characterMap[*c];
		if(ch == nullptr || ch == NULL)
		{
			std::cout << "error: character not found by renderer!" << std::endl;
		}

		float xpos = x + ch->m_bearing.m_x * scale;
		float ypos = y - (ch->m_size.m_y - ch->m_bearing.m_y) * scale;

		float w = ch->m_size.m_x * scale;
		float h = ch->m_size.m_y * scale;
		// update VBO for each character
		float vertices[6][4] = {
			{ xpos,     ypos + h,   0.0f, 0.0f},            
			{ xpos,     ypos,       0.0f, 1.0f},
			{ xpos + w, ypos,       1.0f, 1.0f},

			{ xpos,     ypos + h,   0.0f, 0.0f},
			{ xpos + w, ypos,       1.0f, 1.0f},
			{ xpos + w, ypos + h,   1.0f, 0.0f}           
		};
		x += (ch->Advance >> 6) * scale;
		for(int i = 0; i < 6; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				verts.push_back(vertices[i][j]);
			}
		}
	}
	return verts;
}

// draw line of text
// -------------------
void Renderer::drawText(std::string fontName)
{
	// activate corresponding render state	
	std::cout << "in draw text" << std::endl;
	Shader* m_shader = loadShader("../src/shaders/text.vert", "../src/shaders/text.frag");
	std::cout << "text shader loaded!" << std::endl;
	m_shader->use();
	m_shader->setFloat4("ourColor", 1.0f, 1.0f, 1.0f, 1.0f);
	m_shader->setMat4("projection", (float*)projection);
	unsigned int texID = m_assetMan->getFont(fontName)->m_texID;
	glActiveTexture(GL_TEXTURE0 + texID); 
	std::cout << "active texture set to: " << texID << std::endl;
	//addTextBuffer(m_textBuffer);
	glBindVertexArray(m_VertexArrays[m_textBufferIndex]->getID());
	// render glyph texture over quad
	glBindTexture(GL_TEXTURE_2D, texID);
	// update content of VBO memory
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffers[m_textBufferIndex]->getID());
	//glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(m_textBuffer), m_textBuffer);
	//glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(m_VertexBuffers[m_textBufferIndex]), (*void)m_VertexBuffers[m_textBufferIndex]); // be sure to use glBufferSubData and not glBufferData
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	// render quad
	glDrawArrays(GL_TRIANGLES, 0, sizeof(m_VertexBuffers[m_textBufferIndex]));
	// now advance cursors for next glyph (note that advance is number of 1/64 pixels)
	 // bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))

	//REMEBER TO COMMENT OUT AFTER TESTING!!!!!!!!!!!
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}*/

void Renderer::drawText(std::string text, float x, float y, std::string fontName, float scale, float color[4])
{
	auto* font = m_assetMan->getFont(fontName);
	//checkError("before load");
    Shader* m_shader = loadShader("../src/shaders/text.vert", "../src/shaders/text.frag");
    //checkError("after load");
    m_shader->use();
    //checkError("after use");
    m_shader->setFloat4("ourColor", color[0], color[1], color[2], color[3]);
    //checkError("after ourColor");
    m_shader->setMat4("projection", (float*)projection);
    //checkError("after proj");
    m_shader->setInt("text", font->getTexID());
    
    auto& characterMap = font->getCharMap();

    std::vector<float> verts;
	verts.reserve(text.length()*24);
	//std::vector<unsigned int> texIDs;
	glBindVertexArray(m_VertexArrays[m_textBufferIndex]->getID());
	glActiveTexture(GL_TEXTURE0 + font->getTexID());
    for (char c : text)
    {
        Character* ch = characterMap[c];
        if (ch == nullptr) continue;

        float xpos = x + ch->m_bearing.m_x * scale;
        float ypos = y - (ch->m_size.m_y - ch->m_bearing.m_y) * scale;
        float w = ch->m_size.m_x * scale;
        float h = ch->m_size.m_y * scale;

        std::vector<float> verts = {
            xpos,     ypos + h,   0.0f, 0.0f,
            xpos,     ypos,       0.0f, 1.0f,
            xpos + w, ypos,       1.0f, 1.0f,
            xpos,     ypos + h,   0.0f, 0.0f,
            xpos + w, ypos,       1.0f, 1.0f,
            xpos + w, ypos + h,   1.0f, 0.0f
        };

        updateTextBuffer(verts);    	
    	glBindTexture(GL_TEXTURE_2D, ch->m_texID);
    	glDrawArrays(GL_TRIANGLES, 0, 6); // offset into the buffer, 6 verts per glyph
    	

        x += (ch->Advance >> 6) * scale;
    }

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}