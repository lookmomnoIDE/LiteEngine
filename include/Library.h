#ifndef LIBRARY_H
#define LIBRARY_H

#include <map>

#include <ft2build.h>
#include FT_FREETYPE_H


#include "Font.h"




class Library
{
public:
	FT_Library m_Lib;
	std::map<std::string, Font*> m_Fonts;
	Library()
	{
		auto error = FT_Init_FreeType(&m_Lib);
		if(error)
		{
			std::cout << "Failed to initialize FT library!" << std::endl;
		}
	}


	~Library()
	{
		//TODO: handle deletes
		for (auto& [name, font] : m_Fonts)
		{
			delete font;
		}
		
		FT_Done_FreeType(m_Lib);
	}

	//res/fonts/Mx437_IBM_3270pc.ttf
	FT_FaceRec_* addFace(std::string name, std::string path, unsigned int slot)
	{
		Font* f = new Font(slot);
		auto face = f->m_Face;
		//std::string fontPath = FileSystem::getPath(path);
		if (path.empty())
		{
			std::cout << "ERROR::FREETYPE: Failed to load font_name" << std::endl;
		}
		if (FT_New_Face(m_Lib, path.c_str(), 0, &face)) 
		{
			std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
		}
		// set size to load glyphs as
		FT_Set_Pixel_Sizes(face, 0, 48);
		FTexture(face, slot);
		
		// load first 128 characters of ASCII set
		for (unsigned char c = 0; c < 128; c++)
		{
			// Load character glyph 
			if (FT_Load_Char(face, c, FT_LOAD_RENDER))
			{
				std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
				continue;
			}
			// now store character for later use

			Character character = 
			{
				slot,
				Vec2<int>(face->glyph->bitmap.width, face->glyph->bitmap.rows),
				Vec2<int>(face->glyph->bitmap_left, face->glyph->bitmap_top),
				static_cast<unsigned int>(face->glyph->advance.x)
			};
			//f->m_Characters.insert(std::pair<GLchar, Character>(c, character));
			f->m_Characters[c] = &character;
		}
		glBindTexture(GL_TEXTURE_2D, slot);
		m_Fonts[name] = f;
		
		return face;
	}
	Font* getFont(std::string name)
	{
		return m_Fonts[name];
	}
};

#endif
