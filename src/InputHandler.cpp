#include "InputHandler.h"
#include "Invoker.h"
#include "PlayRec.h"
#include "GameEngine.h"
#include "Renderer.h"
#include "SpawnSand.h"



InputHandler::InputHandler()
{
	m_game = GameEngine::Instance();
	m_window = m_game->getRenderer()->getWindow();
	Invoker *m_invoker = new Invoker;
	PlayRec *m_receiver = new PlayRec(m_game);

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
    	glfwGetCursorPos(m_window, &m_xpos, &m_ypos);
    	m_activeCommand = new SpawnSand(m_xpos, m_ypos, m_receiver);
    	m_invoker->setStart(m_activeCommand);
    	m_invoker->sendCommand();
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
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