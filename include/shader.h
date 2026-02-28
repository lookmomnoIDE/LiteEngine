#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <fstream>
#include <sstream>


#include <iostream>

class Shader{
public:
	enum ShaderType {NORMAL, LIGHTING, POST_PROCESS, UI};
	GLuint shaders[NORMAL];
	//unsigned int ID;

	std::string loadShaderSource(const std::string& filePath)
	{
		std::ifstream fileStream(filePath);
		if (!fileStream.is_open()) {
			std::cout << "ERROR: Failed to open shader file: " << filePath << std::endl;
			return "";
		}

		std::stringstream buffer;
		buffer << fileStream.rdbuf();
		fileStream.close();
		return buffer.str();
	}

	void readyShader(const char* vertexShaderPath, const char* fragmentShaderPath, unsigned int* whichShader)
	{
		std::cout << "Loading vertex shader..." << std::endl;
		std::string vertexShaderSource = loadShaderSource(vertexShaderPath);
		std::cout << "Vertex shader loaded!" << std::endl;
		std::cout << "Loading fragment shader..." << std::endl;
		std::string fragmentShaderPath = loadShaderSource(fragmentShaderPath);
		std::cout << "Fragment shader loaded!" << std::endl;

		if (vertexShaderSource.empty() || fragmentShaderSource.empty()) {
			std::cout << "ERROR: One or both shader files failed to load!" << std::endl;
			return;
		}

		unsigned int vertex, fragment;

		vertex = glCreateShader(GL_VERTEX_SHADER);
		if (vertex == 0) {
			std::cout << "ERROR: glCreateShader(GL_VERTEX_SHADER) failed!" << std::endl;
			std::cout << "OpenGL ERROR: " << glGetError() << std::endl;
			return;
		}

		const char* vertexShader = vertexShaderSource.c_str();
		glShaderSource(vertex, 1, &vertexShader, NULL);
		glCompileShader(vertex);
		checkCompileErrors(vertex, "VERTEX");

		const char* fragShader = fragmentShaderSource.c_str();
		glShaderSource(fragment, 1, &fragShader, NULL);
		glCompileShader(fragment);
		checkCompileErrors(fragment, "FRAGMENT");

		shaders[whichShader] = glCreateProgram();
		glAttachShader(shaders[whichShader], vertex);
		glAttachShader(shaders[whichShader], fragment);
		glLinkProgram(shaders[whichShader]);
		checkCompileErrors(shaders[whichShader], "PROGRAM");
		glDeleteShader(vertex);
		glDeleteShader(fragment);

	}


	void use()
	{
		glUseProgram(shader[whichShader]);
	}	
	// utility uniform functions
    // ------------------------------------------------------------------------
    void setBool(const std::string &name, bool value) const
    {         
        glUniform1i(glGetUniformLocation(shader[whichShader], name.c_str()), (int)value); 
    }
    // ------------------------------------------------------------------------
    void setInt(const std::string &name, int value) const
    { 
        glUniform1i(glGetUniformLocation(shader[whichShader], name.c_str()), value); 
    }
    // ------------------------------------------------------------------------
    void setFloat(const std::string &name, float value) const
    { 
        glUniform1f(glGetUniformLocation(shader[whichShader], name.c_str()), value); 
    }
    // ------------------------------------------------------------------------
    void setVec2(const std::string &name, const glm::vec2 &value) const
    { 
        glUniform2fv(glGetUniformLocation(shader[whichShader], name.c_str()), 1, &value[0]); 
    }
    void setVec2(const std::string &name, float x, float y) const
    { 
        glUniform2f(glGetUniformLocation(shader[whichShader], name.c_str()), x, y); 
    }
    // ------------------------------------------------------------------------
    void setVec3(const std::string &name, const glm::vec3 &value) const
    { 
        glUniform3fv(glGetUniformLocation(shader[whichShader], name.c_str()), 1, &value[0]); 
    }
    void setVec3(const std::string &name, float x, float y, float z) const
    { 
        glUniform3f(glGetUniformLocation(shader[whichShader], name.c_str()), x, y, z); 
    }
    // ------------------------------------------------------------------------
    void setVec4(const std::string &name, const glm::vec4 &value) const
    { 
        glUniform4fv(glGetUniformLocation(shader[whichShader], name.c_str()), 1, &value[0]); 
    }
    void setVec4(const std::string &name, float x, float y, float z, float w) const
    { 
        glUniform4f(glGetUniformLocation(shader[whichShader], name.c_str()), x, y, z, w); 
    }
    // ------------------------------------------------------------------------
    void setMat2(const std::string &name, const glm::mat2 &mat) const
    {
        glUniformMatrix2fv(glGetUniformLocation(shader[whichShader], name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat3(const std::string &name, const glm::mat3 &mat) const
    {
        glUniformMatrix3fv(glGetUniformLocation(shader[whichShader], name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat4(const std::string &name, const glm::mat4 &mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(shader[whichShader], name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

private:
	void checkCompileErrors(GLuint shader, std::string type)
    {
        GLint success;
        GLchar infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }

};
#endif