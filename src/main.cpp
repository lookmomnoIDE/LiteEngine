#include "includes.h"


//------------------------//   GLOBAL VARIABLES   //------------------------//
int width = 1920;
int height = 1050; 
float aspectRatio = width/height;
//double xpos = width/2, ypos = height/2;
double xpos, ypos;

//------------------------//FORWARD DECLARATIONS//------------------------//
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

//------------------------//INIT MEMORY MANAGEMENT//------------------------//
EntityMemoryPool& pool = EntityMemoryPool::Instance();
EntityMan& entityMan = EntityMan::Instance();


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

	//INIT SCREEN DIMENSIONS
	int winWidth, winHeight;
	glfwGetWindowSize(window, &winWidth, &winHeight);
	width = winWidth;
	height = winHeight;

	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	Shader ourShader("../src/cool.vert", "../src/beans.frag");

	
	ourShader.use();
	Renderer renderer;
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);


	//glm::mat4 proj = glm::mat4();


	//Texture texture("../res/fabric.jpg");
	//texture.Bind();
	//ourShader.setInt("u_Texture", texture.GetSlot());
	
	


	unsigned int framecount = 0;
	Entity e = entityMan.addEntity("sand");
	size_t id = e.getID(); // however your Entity exposes its index
	// Add/set a component
	pool.getComponent<CTransform>(id) = CTransform();
	pool.getComponent<Cgrain>(id)     = Cgrain();
	pool.getComponent<Csand>(id)	  =	Csand();
	pool.getComponent<Cgravity>(id)	  = Cgravity();

	while(!glfwWindowShouldClose(window))
	{
		entityMan.update();
		processInput(window);
		//std::vector<float> position = pool.getComponent<CTransform>(id).getPos();

		renderer.Clear();

		//float timeValue = glfwGetTime();
		//ourShader.setFloat("uTime", timeValue);

		EntityVec& currentEntities = entityMan.getEntities();

		for ( Entity e : currentEntities )
		{
			std::cout << e.getID() << std::endl;
			if(pool.hasComponent<Cgravity>(e.getID()))
			{
				CTransform& transform = pool.getComponent<CTransform>(e.getID());
				Cgravity& gravity = pool.getComponent<Cgravity>(e.getID());
				std::vector<float>& vel = transform.getVel();
				vel[1] += gravity.getGravity();
				std::vector<float>& pos = transform.getPos();
				pos[1] += vel[1];
				std::cout << "x: " << pos[0] << "y: " << pos[1] << std::endl;
				if (pos[1] <= -1)
				{
					pos[1] = -.9;
					vel[0] = 0;
					vel[1] = 0;
					pool.remComponent<Cgravity>(e.getID());
					std::cout << "removed gravity from entity: " << e.getID() << std::endl;
					if ( pool.hasComponent<Cgravity>(e.getID()))
					{
						std::cout << "why do I still have gravity: " << e.getID() << std::endl;
					}
				}
				transform.setPos(pos);
				transform.setVel(vel);				
			}
			
		}

		//draw entities at position
		for ( Entity e : currentEntities )
		{
			std::vector<float> pos = pool.getComponent<CTransform>(e.getID()).getPos();
			renderer.Square(e, pos, ourShader);
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
			std::vector<float> pos = {(2.0f*xpos)/width - 1.0f, 1.0f - (2.0f*ypos)/height};
			std::vector<float> vel = {0.0f, 0.0f};
			Entity e = entityMan.addEntity("sand");
			size_t id = e.getID(); // however your Entity exposes its index
			// Add/set a component
			pool.getComponent<CTransform>(id) = CTransform(pos, vel);
			pool.getComponent<Cgrain>(id)     = Cgrain();
			pool.getComponent<Csand>(id)	  =	Csand();
			pool.getComponent<Cgravity>(id)   = Cgravity();
		}
}

