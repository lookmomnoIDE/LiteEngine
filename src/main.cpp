#include "includes.h"


//------------------------//   GLOBAL VARIABLES   //------------------------//
float width = 1920.0f;
float height = 1050.0f;
float aspectRatio = width/height;
double xpos = width/2, ypos = height/2;


float grain[] = {
		// positions	//Texture Coordinates

		 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,  1.0f,  1.0f,   //1
		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,  0.0f,  1.0f,   //2
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,  0.0f,  0.0f,   //3
		-0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,  1.0f,  0.0f    //4
};

unsigned int indices[] = {
	0, 1, 3, 
	1, 2, 3
};


//------------------------//FORWARD DECLARATIONS//------------------------//
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);


EntityMemoryPool& pool = EntityMemoryPool::Instance();
// EntityMemoryPool::EntityMemoryPool(1000);


int main(int argc, char* argv[])
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(width, height, "LiteEngine", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "ERROR: Failed to create GLFW window!" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "ERROR: Failed to initialize GLAD!" << std::endl;
		return -1;
	}

	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	Shader ourShader("../src/cool.vert", "../src/beans.frag");

	/*VertexArray va;
	VertexBuffer vb(grain, sizeof(grain));

	IndexBuffer ib(indices, 6);

	ib.Bind();

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(4);
	layout.Push<float>(2);
	va.addBuffer(vb, layout);*/
	
	ourShader.use();
	Renderer renderer;
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);


	//glm::mat4 proj = glm::mat4();


	//Texture texture("../res/fabric.jpg");
	//texture.Bind();
	//ourShader.setInt("u_Texture", texture.GetSlot());
	EntityMan& entityMan = EntityMan::Instance();
	Entity sand = entityMan.addEntity("sand");
	size_t id = sand.getID(); // however your Entity exposes its index

	// Add/set a component
	pool.getComponent<CTransform>(id) = CTransform();
	pool.getComponent<Cgrain>(id)     = Cgrain();


	unsigned int framecount = 0;
	Cgrain& s = pool.getComponent<Cgrain>(id);
	float size = s.getSize();

	int winWidth, winHeight, fbWidth, fbHeight;
	glfwGetWindowSize(window, &winWidth, &winHeight);
	glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
	std::cout << "window: " << winWidth << "x" << winHeight << std::endl;
	std::cout << "framebuffer: " << fbWidth << "x" << fbHeight << std::endl;

	while(!glfwWindowShouldClose(window))
	{

		processInput(window);
		std::vector<float> position = pool.getComponent<CTransform>(id).getPos();

		renderer.Clear();

		//float timeValue = glfwGetTime();
		//ourShader.setFloat("uTime", timeValue);

		//renderer.Draw(va, vb, ourShader);
		//renderer.DrawElements(va, vb, ib, ourShader);
		//std::vector<float> pos = {(xpos / width) * 2.0 - 1.0, 1.0 - (ypos / height)* 2.0f};
		/*std::vector<float> pos = {
		    (xpos / 1920.0f) * 2.0f - 1.0f - (size / aspectRatio) / 2.0f,  // center X
		    1.0f - (ypos / 1080.0f) * 2.0f + size / 2.0f                    // center Y
		};*/
		//glfwGetCursorPos(window, &xpos, &ypos);
		std::cout << "x: " << xpos << ", " << "y: " << ypos << std::endl;
		/*std::vector<float> pos = {
		    (xpos / 1920.0f) * 2.0f - 1.0f,
		    1.0f - (ypos / 1080.0f) * 2.0f
		};*/

		std::vector<float> pos = {(2.0f*xpos)/width - 1.0f, 1.0f - (2.0f*ypos)/height};
		std::cout << "x':  " << pos[0] << " " << "y': " << pos[1] << std::endl;
		//std::vector<float> center = { (xpos + width/2) / width, (ypos + height/2) / height};
		//std::cout << "centerX: " << center[0] << " " << "centerY: " << center[1] << std::endl;
		pool.getComponent<CTransform>(id).setPos(pos);
		renderer.Square(sand, pos, ourShader);
		if (framecount%240 == 0)
		{
			std::cout << position[0] << ", " << position[1] << std::endl;
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
		framecount++;
	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		{
			glfwGetCursorPos(window, &xpos, &ypos);
			//std::cout << xpos << ", "<< ypos << std::endl;

		}
}