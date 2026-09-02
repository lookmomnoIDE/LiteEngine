#include "assetManager.h"
#include "Library.h"
#include "Texture.h"
#include "FTexture.h"
#include "palette.h"


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
	for (auto& [name, palette] : m_palettes)
	{
		delete palette;
	}

	delete m_Library;
}


void assetMan::addTexture(std::string name, std::string path)
{
	Texture* tex = new Texture(path, texCounter);
	std::cout << "out of new texture: "<< name << std::endl;
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


Palette* assetMan::makeEmptyPalette(std::string name)
{
	m_palettes[name] = new Palette();
	return m_palettes[name];
}


Palette* assetMan::loadPalette(std::string name, const std::string path)
{
	m_palettes[name] = new Palette(path);
	return m_palettes[name];
}


Palette* assetMan::getPalette(std::string name)
{
	return m_palettes[name];
}