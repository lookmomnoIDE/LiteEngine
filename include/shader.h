#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Parser.h"


class Shader
{

public:
	//the program ID
	unsigned int ID;
	int success;
	char infoLog[512];

	//constructor reads and builds shader
	Shader(const char* vertexPath, const char* fragmentPath);

	//use/activate the shader
	void use() const;

	void unUse();

	//utility uniform section
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;

};

#endif