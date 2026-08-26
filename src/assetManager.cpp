#include "assetManager.h"
#include "Library.h"


assetMan::assetMan()
{
	m_Library = new Library();
}


assetMan::~assetMan()
{
	for (auto& [name, texture] : m_Textures)
	{
		delete texture;
	}
	for (auto& [name, texture] : m_FTextures)
	{
		delete texture;
	}

	delete m_Library;
}


void assetMan::addTexture(std::string name, std::string path)
{
	Texture* tex = new Texture(path, texCounter);
	m_Textures[name] = tex;
	texCounter++;
}
/*
void assetMan::addAnimation(std::string name, Animation animation)
{

}

void assetMan::addSound(std::string name, std::string path)
{

}
*/



void assetMan::addFont(std::string name, std::string path)
{
	std::cout << "inside add font in assetMan" << std::endl;
	m_Library->addFace(name, path, texCounter, this);
	std::cout<< "face added" << std::endl;
	FTexture* fontTexture = new FTexture(m_Library->getFont(name)->getFace(), texCounter);
	std::cout << "FTexture added" << std::endl;
	m_FTextures[name] = fontTexture;
	texCounter++;
}

Texture* assetMan::getTexture(std::string name)
{
	return m_Textures[name];
}
/*
Animation& assetMan::getAnimation(std::string name)
{

}

Sound& assetMan::getASound(std::string name)
{

}
*/
Font* assetMan::getFont(std::string name)
{
	return m_Library->getFont(name);
	//return m_FTextures[name];
}

void assetMan::setFTMap(FTexture* ftexture, std::string name)
{
	m_FTextures[name] = ftexture;
}


FTexture* assetMan::getFTMapTexture(std::string name)
{
	return m_FTextures[name];
}