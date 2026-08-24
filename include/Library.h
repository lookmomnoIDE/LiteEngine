#ifndef LIBRARY_H
#define LIBRARY_H

#include <map>
#include <glad/glad.h>

#include <ft2build.h>
#include FT_FREETYPE_H


#include "Font.h"
#include "assetManager.h"



class Library
{
public:
	FT_Library m_Lib;
	std::map<std::string, Font*> m_Fonts;
	Library();


	~Library();

	//res/fonts/Mx437_IBM_3270pc.ttf
	FT_FaceRec_* addFace(std::string name, std::string path, unsigned int slot, assetMan* man);
	Font* getFont(std::string name);
};

#endif
