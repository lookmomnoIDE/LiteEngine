#include <stdlib.h>
#include <iostream>
#include <cmath>


#include "shader.h"
#include "camera.h"

char windowTitle = "LiteENGINE";
float deltaFrame = 0.0f;
float lastFrame = 0.0f;


void glfw_error_callback(int error, const char* description);
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void framebuffer_size_callback(GLFWwindow* window, int SCREENWIDTH, int SCREENHEIGHT);


int main()
{
	if(!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return -1;
	}
	std::cout << "Initialized GLFW." << std::endl;



	glfwSetErrorCallback(glfw_error_callback);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    GLFWmonitor* primary = glfwGetPrimaryMonitor();
    if (!primary) {
    	std::cout << "Failed to get primary monitor!" << std::endl;
    	glfwTerminate();
    	return -1;
    }
    std::cout << "Primary monitor: " << primary << std::endl;


    GLFWvidmode const* mode = glfwGetVideoMode(primary);
    float SCREENWIDTH = mode->width;
    float SCREENHEIGHT = mode->height;
    lastX = SCREENWIDTH/2.0f;
    lastY = SCREENHEIGHT/2.0f;
    std::cout << "Screenwidth: " << SCREENWIDTH << "\n" << "Screenheight: " << SCREENHEIGHT << std::endl;
    std::cout << "Center Screen: " << lastX << ", " << lastY <<  std::endl;

    float mainScale = ImGui_ImplGlfw_GetContentScaleForMonitor(primary);


    GLFWwindow* window = glfwCreateWindow(SCREENWIDTH*mainScale, SCREENHEIGHT*mainScale, windowTitle, NULL, NULL);
    if (window == NULL) {
    	std::cout << "Failed to create OpenGl window!" << std::endl;
    	glfwTerminate();
    	return -1;
    }
    std::cout << "Window created." std::endl;


    glfwMakeContextCurrent(window);
    if (glfwGetCurrentContext() != window) {
    	std::cout << "Failed to make context current!" << std::endl;
    	glfwTerminate();
    	return -1;
    }
    std::cout << "Made context current: " << glfwGetCurrentContext() << std::endl;


    int gladVersion = gladLoadGL();
    if (gladVersion == 0) {
    	std::cout << "Failed to initialize GLAD!" << std::endl;
    	glfwTerminate();
    	return -1;
    }
    std::cout << "GLAD loaded, version: " << gladVersion << std::endl;
    std::cout << "Glad initialized." << std::endl;

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);
	std::cout << "Callbacks initialized." std::endl;

	std::cout "Initializing ImGui." << std::endl;

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	//ImGui Input/Output flags (bitwise or: |=) 
	//Store up to 32 bools in one intiger with bit manipulation. 
	//check and see if true with bitwise & operator. 
	//example:	MyConfigFlags_FullscreenEnable  = 1 << 0,  // bit 0 = 0b00000001 = 1
	//			MyConfigFlags_VSyncEnable       = 1 << 1,  // bit 1 = 0b00000010 = 2
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

	ImGui::StyleColorsDark();
	ImGuiStyle& style = ImGui::GetStyle();
	style.ScaleAllSizes(mainScale);
	style.FontScaleDpi = mainScale;

	io.ConfigDpiScaleFonts = true;
	io.ConfigDpiScaleViewports = false;

	std::cout << "Initializing ImGui backends." << std::endl;
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330 core");

	glViewort(0, 0, SCREENWIDTH * mainScale, SCREENHEIGHT * mainScale);
	std::cout << "Entering main loop..." << std::endl;

	while(!glfwWindowShouldClose(window)){
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaFrame = currentFrame - lastFrame;
		lastFrame = currentFrame;
		processInput(window); // TODO
	}


	std::cout << "Cleaning up..." << std::endl;
	glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(window);
	glfwTerminate();
	std::cout << "Application finished" << std::endl;
	return 0;
}



static void glfw_error_callback(int error, const char* description)
{
	std::cout << stderr << "GLFW error %d: %s \n" << error << description << std::endl;

}


void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
{
	camera.ProcessMouseScroll(static_cast<float>(yoffset));
}


