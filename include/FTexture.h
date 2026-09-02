#ifndef FTEXTURE_H
#define FTEXTURE_H


#include <string>
#include <ft2build.h>
#include FT_FREETYPE_H


class FTexture
{
	unsigned int m_tName;
	unsigned int m_Slot = 1;
	int m_Width, m_Height;
public:
	FTexture(FT_FaceRec_* face, unsigned int slot);

	~FTexture();

	void Bind();

	void unBind();

	const unsigned int GetSlot() const;

	unsigned int getName();
};


#endif