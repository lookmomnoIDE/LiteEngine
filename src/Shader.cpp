#include "shader.h"



Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	//Retrieve the vertex/fragment source code from Filepath
	std::string vertexCode = Parser::loadFromFile(vertexPath);
	std::string fragCode = Parser::loadFromFile(fragmentPath);
	//convert code to c-string
	const char* vertexSrc = vertexCode.c_str();
	const char* fragSrc = fragCode.c_str();

	//compile shaders
	unsigned int vertex, fragment;

	//Vertex shader compilation
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertexSrc, NULL);
	glCompileShader(vertex);

	//vertex shader compilation error checking
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success) 
	{
	    glGetShaderInfoLog(vertex, 512, NULL, infoLog);
	    std::cout << "VERTEX SHADER ERROR:\n" << infoLog << std::endl;
	}

	//fragment shader compilation
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragSrc, NULL);
	glCompileShader(fragment);

	//fragment shader compilation error checking
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success) 
	{
	    glGetShaderInfoLog(fragment, 512, NULL, infoLog);
	    std::cout << "FRAGMENT SHADER ERROR:\n" << infoLog << std::endl;
	}

	//Attach and link shader files to shader program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	//Check compilation status and return errors
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success) 
	{
	    glGetProgramInfoLog(ID, 512, NULL, infoLog);
	    std::cout << "LINK ERROR:\n" << infoLog << std::endl;
	}

	//clean-up!
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

//use/activate the shader
void Shader::use() const
{
	glUseProgram(ID);
}

void Shader::unUse()
{
	glUseProgram(0);
}

//utility uniform section
void Shader::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int) value);
}
void Shader::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void Shader::setFloat4(const std::string &name, float value0, float value1, float value2, float value3) const
{	
	glUniform4f(glGetUniformLocation(ID, name.c_str()), value0, value1, value2, value3);
}
void Shader::setFloat4(const std::string &name, Color& color) const
{	
	glUniform4f(glGetUniformLocation(ID, name.c_str()), color.m_r, color.m_g, color.m_b, color.m_a);
}
void Shader::setMat4(const std::string &name, const float* value) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, true, value);
}