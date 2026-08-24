#ifndef SHADER_H
#define SHADER_H


#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Parser.h"
#include "Vec4.h"


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
	void setFloat4(const std::string &name, float value0, float value1, float value2, float value3) const;
	void setMat4(const std::string &name, const float* value) const;

};

#endif