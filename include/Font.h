#ifndef FONT_H
#define FONT_H

#include <map>
#include <glad/glad.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "Character.h"


class Font
{
public: 
	std::map<GLchar, Character*> m_Characters;
	FT_Face m_Face;
	unsigned int m_texID;
	Font(unsigned int slot)
	:m_texID(slot)
	{

	}
	~Font()
	{
		for (auto& [ch, glyph] : m_Characters)
		{
		    delete glyph;
		}
		FT_Done_Face(m_Face);
	}


	void addCharacter(unsigned int texID, GLchar c)
	{
		Character* character = new Character{
			texID,
			Vec2<int>(m_Face->glyph->bitmap.width, m_Face->glyph->bitmap.rows),
			Vec2<int>(m_Face->glyph->bitmap_left, m_Face->glyph->bitmap_top),
			static_cast<unsigned int>(m_Face->glyph->advance.x)
		};
		this->getCharMap().insert(std::pair<GLchar, Character*>(c, character));
	}


	FT_FaceRec_* getFace()
	{
		return m_Face;
	}
	

	std::map<GLchar, Character*>& getCharMap()
	{
		return m_Characters;
	}
};


#endif