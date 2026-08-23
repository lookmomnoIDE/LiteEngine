#ifndef FONT_H
#define FONT_H

#include <map>

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
		for (auto& [GLchar, Character] : m_Characters)
		{
			delete Character;
		}

		FT_Done_Face(m_Face);
	}
	FT_FaceRec_* getFace()
	{
		return m_Face;
	}
};


#endif