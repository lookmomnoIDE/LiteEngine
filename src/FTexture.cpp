#include "FTexture.h"
#include <glad/glad.h>


FTexture::FTexture(FT_FaceRec_* face, unsigned int slot)
	:m_Width(face->glyph->bitmap.width), m_Height(face->glyph->bitmap.rows), m_Slot(slot)
{
	glGenTextures(1, &m_tName);
	glBindTexture(GL_TEXTURE_2D, m_tName);
	
	// set texture options
	// disable byte-alignment restriction
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, m_Width, m_Height, 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
}


FTexture::~FTexture()
{
	
}

void FTexture::Bind() 
{
	glActiveTexture(GL_TEXTURE0 + m_Slot);
	glBindTexture(GL_TEXTURE_2D, m_tName);
}

void FTexture::unBind() 
{
	glBindTexture(GL_TEXTURE_2D, GL_TEXTURE0);
}

const unsigned int FTexture::GetSlot() const
{
	return m_Slot;
}

unsigned int FTexture::getName()
{
	return m_tName;
}
