#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <glad/glad.h>
#include <iostream>


Texture::Texture(std::string path, unsigned int slot)
	:m_FilePath(path), m_LocalBuffer(nullptr), m_Width(5000), m_Height(5000), m_BPP(0), m_Slot(slot)
{
	stbi_set_flip_vertically_on_load(1);
	m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);
	if(m_LocalBuffer == NULL)
	{
		std::cout << "Texture not in buffer" << std::endl;
	}
	glGenTextures(1, &m_tName);
	glBindTexture(GL_TEXTURE_2D, m_tName);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
}


Texture::~Texture()
{
	if(m_LocalBuffer)
	{
		stbi_image_free(m_LocalBuffer);
	}	
	glDeleteTextures(1, &m_tName);
}

void Texture::Bind() 
{
	if(m_LocalBuffer == nullptr)
	{
		std::cout << "local buffer is pointer to null pointer" << std::endl;
	}
	glActiveTexture(GL_TEXTURE0 + m_Slot);
	glBindTexture(GL_TEXTURE_2D, m_tName);
}

void Texture::unBind() 
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

const unsigned int Texture::GetSlot() const
{
	return m_Slot;
}
