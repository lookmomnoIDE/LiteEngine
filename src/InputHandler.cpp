#include "InputHandler.h"
#include "Invoker.h"
#include "PlayRec.h"
#include "GameEngine.h"
#include "Renderer.h"
#include "SpawnSand.h"



InputHandler::InputHandler()
{
	m_game = GameEngine::Instance();
	m_invoker = new Invoker();
	m_receiver = new PlayRec(m_game);

}

InputHandler::~InputHandler()
{
	delete m_invoker;
	delete m_receiver;	
}

void InputHandler::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void InputHandler::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		std::cout << "LMB pressed!" << std::endl;
    	glfwGetCursorPos(window, &m_xpos, &m_ypos);
    	std::cout << "set cursor position!" << std::endl;
    	m_activeCommand = new SpawnSand(m_xpos, m_ypos, m_receiver);
    	std::cout << "Active command initialized!" << std::endl;
    	m_invoker->setStart(m_activeCommand);
    	std::cout << "Active command set start!" << std::endl;
    	m_invoker->sendCommand();
    	std::cout << "Invoker sent command!" << std::endl;
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		std::cout << "LMB released!" << std::endl;
    	m_invoker->setStop(m_activeCommand);
    	m_invoker->sendCommand();
    	delete m_activeCommand;
    	m_activeCommand = nullptr;
	}
}

std::vector<double> InputHandler::getMousePosition()
{
	return {m_xpos, m_ypos};
}

void InputHandler::processInput(GLFWwindow* window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
		m_game->quit();
	}
	
}

Invoker& InputHandler::getInvoker()
{
	return *m_invoker;
}

PlayRec& InputHandler::getRec()
{
	return *m_receiver;
}