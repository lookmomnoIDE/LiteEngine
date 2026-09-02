#ifndef PALETTE_H
#define PALETTE_H


#include <fstream>
#include <map>
#include <string>
#include <unordered_map>
#include <iostream>
#include <memory>

#include "Color.h"



class Palette
{
	std::unordered_map<std::string, Color> m_colors;
public:
	Palette()
	{

	}
	Palette(const std::string& path)
	{

	}

	~Palette()
	{

	}
	void addColor(std::string name, Color color)
	{
		m_colors[name] = color;
	}

	Color& getColor(std::string name)
	{
		return m_colors[name];
	}

	void loadColorsFromFile(const std::string& path)
	{
		std::string input;
		std::string name;
		Color color;
		std::ifstream fin(path);
		if (!fin.is_open())
		{
    		std::cout << "file not found" << std::endl;
		}

		while (fin >> name >> color.m_r >> color.m_g >> color.m_b >> color.m_a)
		{
    		this->addColor(name, color);
		}
	}
};


#endif