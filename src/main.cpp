#include "includes.h"


//------------------------//   GLOBAL VARIABLES   //------------------------//
int width = 1920;
int height = 1050; 
double xpos, ypos;
unsigned int framecount = 0;

//------------------------//FORWARD DECLARATIONS//------------------------//
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

//------------------------//INIT MEMORY MANAGEMENT//------------------------//
EntityMemoryPool& pool = EntityMemoryPool::Instance();
EntityMan& entityMan = EntityMan::Instance();

void addSand(double xpos, double ypos)
{
	std::vector<float> pos = {(2.0f*xpos)/width - 1.0f, 1.0f - (2.0f*ypos)/height};
	std::vector<float> vel = {0.0f, 0.0f};
	Entity e = entityMan.addEntity("sand");
	size_t id = e.getID();
	// Add/set components
	pool.getComponent<CTransform>(id) = CTransform(pos, vel);
	pool.getComponent<Cgrain>(id)     = Cgrain();
	pool.getComponent<Csand>(id)	  =	Csand();
	pool.getComponent<Cgravity>(id)   = Cgravity();
}


int main(int argc, char* argv[])
{
	Renderer renderer;
	GLFWwindow* window = renderer.getWindow();
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	//glm::mat4 proj = glm::mat4();


	//Texture texture("../res/fabric.jpg");
	//texture.Bind();
	//ourShader.setInt("u_Texture", texture.GetSlot());
	
	



	
	while(!glfwWindowShouldClose(window))
	{
		entityMan.update();
		processInput(window);
		renderer.Clear();

		//float timeValue = glfwGetTime();
		//ourShader.setFloat("uTime", timeValue);

		EntityVec& currentEntities = entityMan.getEntities();

		for ( Entity e : currentEntities )
		{
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
				}
				transform.setPos(pos);
				transform.setVel(vel);				
			}
			
		}

		//draw entities at position
		for ( Entity e : currentEntities )
		{
			std::vector<float> pos = pool.getComponent<CTransform>(e.getID()).getPos();
			renderer.Square(e, pos);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
		framecount++;
	}

	renderer.~Renderer();
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
			//LMB_->execute();
			glfwGetCursorPos(window, &xpos, &ypos);
			addSand(xpos, ypos);
		}
}

