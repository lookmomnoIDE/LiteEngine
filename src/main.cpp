#include "includes.h"


//------------------------//   GLOBAL VARIABLES   //------------------------//
int width = 1920;
int height = 1080;


float grain[] = {
        // positions	//Texture Coordinates

         0.005f*0.5625f,  0.005f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,  1.0f,  1.0f,   //1
         0.005f*0.5625f, -0.005f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,  0.0f,  1.0f,   //2
        -0.005f*0.5625f, -0.005f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,  0.0f,  0.0f,   //3
        -0.005f*0.5625f,  0.005f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,  1.0f,  0.0f    //4
};

unsigned int indices[] = {
	0, 1, 3, 
	1, 2, 3
};


//------------------------//FORWARD DECLARATIONS//------------------------//
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


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

	Shader ourShader("../src/cool.vert", "../src/beans.frag");

	VertexArray va;
	VertexBuffer vb(grain, sizeof(grain));

	IndexBuffer ib(indices, 6);

	ib.Bind();

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(4);
	layout.Push<float>(2);
	va.addBuffer(vb, layout);
	
	ourShader.use();
	Renderer renderer;
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);


	//glm::mat4 proj = glm::mat4();


	Texture texture("../res/fabric.jpg");
	texture.Bind();
	ourShader.setInt("u_Texture", texture.GetSlot());


	while(!glfwWindowShouldClose(window))
	{
		processInput(window);

		renderer.Clear();

		//float timeValue = glfwGetTime();
		//ourShader.setFloat("uTime", timeValue);

		//renderer.Draw(va, vb, ourShader);
		renderer.DrawElements(va, vb, ib, ourShader);

		glfwSwapBuffers(window);
		glfwPollEvents();
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
