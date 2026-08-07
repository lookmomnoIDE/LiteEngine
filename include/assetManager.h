#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include <string>

#include "Texture.h"

class assetMan
{
	std::map<std::string, *Texture> 	m_Textures;
	std::map<std::string, *Animation> 	m_Animations;
	std::map<std::string, *Sound> 		m_Sounds;
	std::map<std::string, *Font> 		m_Fonts;
	unsigned int texCounter = 0;
	unsigned int animCounter = 0;
	unsigned int soundCounter = 0;
	unsigned int fontCounter = 0;

public:
	assetMan(){}
	~assetMan(){}
	void addTexture(std::string name, std::string path);
	void addAnimation(std::string name, Animation animation);
	void addSound(std::string name, std::string path);
	void addFont(std::string name, std::string path);

	Texture& 	getTexture(std::string name);
	Animation& 	getAnimation(std::string name);
	Sound& 		getSound(std::string name);
	Font& 		getFont(std::string name);

};

#endif