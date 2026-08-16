#pragma once
#include <string>
#include <Renderer.h>


class Texture
{
	unsigned int m_tName;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
	unsigned int m_Slot = 0;
public:
	Texture(std::string path, unsigned int slot);

	~Texture();

	void Bind();

	void unBind();

	const unsigned int GetSlot() const;
};

