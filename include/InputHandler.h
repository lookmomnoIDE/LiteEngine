#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <vector>


class GameEngine;
class Invoker;
class Renderer;
class PlayRec;
class GLFWwindow;
class SpawnSand;

class InputHandler
{
	Invoker* m_invoker = nullptr;
	PlayRec* m_receiver = nullptr;
	GameEngine* m_game = nullptr;
	SpawnSand* m_activeCommand = nullptr;
public:
	double m_xpos, m_ypos;
	std::vector<double> m_pos = {m_xpos, m_ypos};
	InputHandler();

	~InputHandler();

	void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

	std::vector<double> getMousePosition();

	void processInput(GLFWwindow* window);

	Invoker& getInvoker();

	PlayRec& getRec();


};

#endif