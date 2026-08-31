#include "InputHandler.h"
//#include "Invoker.h"
//#include "PlayRec.h"
#include "GameEngine.h"
#include "Renderer.h"
//#include "SpawnSand.h"
//#include "GLFW/glfw3.h"


InputHandler& InputHandler::Instance()
{
	static InputHandler Instance{};
	return Instance;
}

void InputHandler::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Instance().processInput(window, key, scancode, action, mods);
}

void InputHandler::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    Instance().framebuffer_size_callback(window, width, height);
}

void InputHandler::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    Instance().mouse_button_callback(window, button, action, mods);
}


void InputHandler::Init()
{
	m_game = GameEngine::Instance();
	m_window = m_game->getRenderer()->getWindow();
	glfwSetWindowUserPointer(m_window, m_game->getRenderer());



	

	glfwSetKeyCallback(m_window, keyCallback);
	glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);
	glfwSetMouseButtonCallback(m_window, mouseButtonCallback);

}

InputHandler::~InputHandler()
{

}

void InputHandler::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void InputHandler::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	const auto& am = m_game->currentScene()->getAM();
	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		//const auto& am = m_game->currentScene()->getAM();
		//std::cout << m_game->currentScene() << std::endl;
		if(am.find(button) == am.end())
		{
			std::cout << "Action Not found!" << std::endl;
			return;
		}

		const std::string actionType = (action == GLFW_PRESS) ? "START" : "END";

		Action a(am.at(button), actionType);
		m_game->currentScene()->doAction(a);
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT)
	{
		
		//std::cout << m_game->currentScene() << std::endl;
		if(am.find(button) == am.end())
		{
			std::cout << "Action Not found!" << std::endl;
			return;
		}

		const std::string actionType = (action == GLFW_PRESS) ? "START" : "END";

		Action a(am.at(button), actionType);
		m_game->currentScene()->doAction(a);
	}
	
}

std::vector<double> InputHandler::getMousePosition()
{
	glfwGetCursorPos(m_window, &m_xpos, &m_ypos);
	return m_pos = {m_xpos, m_ypos};
}

void InputHandler::processInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	const auto& am = m_game->currentScene()->getAM();
	GameEngine* game = Instance().m_game;
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		if(am.find(key) == am.end())
		{
			std::cout << "Action Not found!" << std::endl;
			return;
		}
		const std::string actionType = (action == GLFW_PRESS) ? "START" : "END";

		Action a(am.at(key), actionType);
		m_game->currentScene()->doAction(a);
	}
	if (key == GLFW_KEY_P)
	{
		if(am.find(key) == am.end())
		{
			std::cout << "Action Not found!" << std::endl;
			return;
		}
		const std::string actionType = (action == GLFW_PRESS) ? "START" : "END";

		Action a(am.at(key), actionType);
		m_game->currentScene()->doAction(a);
	}
	if (key == GLFW_KEY_O)
	{
		if(am.find(key) == am.end())
		{
			std::cout << "Action Not found!" << std::endl;
			return;
		}
		const std::string actionType = (action == GLFW_PRESS) ? "START" : "END";

		Action a(am.at(key), actionType);
		m_game->currentScene()->doAction(a);
	}
	if (key == GLFW_KEY_SPACE)
	{
		if(am.find(key) == am.end())
		{
			std::cout << "Action Not found!" << std::endl;
			return;
		}
		const std::string actionType = (action == GLFW_PRESS) ? "START" : "END";

		Action a(am.at(key), actionType);
		m_game->currentScene()->doAction(a);
	}
	if (key == GLFW_KEY_F3)
	{
		if(am.find(key) == am.end())
		{
			std::cout << "Action Not found!" << std::endl;
			return;
		}
		const std::string actionType = (action == GLFW_PRESS) ? "START" : "END";

		Action a(am.at(key), actionType);
		m_game->currentScene()->doAction(a);
	}
	
	
}

/*Invoker& InputHandler::getInvoker()
{
	return *m_invoker;
}

PlayRec& InputHandler::getRec()
{
	return *m_receiver;
}*/