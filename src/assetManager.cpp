#include "assetManager.h"


void assetMan::addTexture(std::string name, std::string path)
{
	Texture tex = new Texture(path, texCounter);
	m_Textures[name] = tex;
	texCounter++;
}

void assetMan::addAnimation(std::string name, Animation animation)
{

}

void assetMan::addSound(std::string name, std::string path)
{

}

void assetMan::addFont(std::string name, std::string path)
{

}

Texture& assetMan::getTexture(std::string name)
{
	return m_Textures[name];
}

Animation& assetMan::getAnimation(std::string name)
{

}

Sound& assetMan::getASound(std::string name)
{

}

Font& assetMan::getFont(std::string name)
{
	
}