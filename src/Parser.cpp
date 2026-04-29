#include "Parser.h"


Parser::Parser(){}

Parser::~Parser(){}

const std::string Parser::loadFromFile(const char* filename)
{
	std::ifstream fin(filename);
	if(!fin.is_open())
	{
		std::cout << "ERROR: Failed to open shader file " << filename << std::endl;
		return "";
	}

	std::stringstream buffer;
	buffer << fin.rdbuf();
	fin.close();
	return buffer.str();
}
