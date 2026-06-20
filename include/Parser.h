#pragma once



#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Parser
{
	
public:
	Parser();
	~Parser();
	const static std::string loadFromFile(const char* filename);
};