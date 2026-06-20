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
	GameEngine* m_game = nullptr;
	GLFWwindow* m_window = nullptr;
	double m_xpos, m_ypos;
	std::vector<double> m_pos = {m_xpos, m_ypos};
public:
	
	static InputHandler& Instance();

	void Init();

	~InputHandler();
	
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);


	void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

	std::vector<double> getMousePosition();

	void processInput(GLFWwindow* window, int key, int scancode, int action, int mods);

/*	Invoker& getInvoker();

	PlayRec& getRec();
*/

};

#endif