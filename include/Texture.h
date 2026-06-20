#pragma once
#include <string>
#include <Renderer.h>


class Texture
{
	unsigned int m_RendererID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
	unsigned int m_Slot;
public:
	Texture(const std::string path);

	~Texture();

	void Bind(unsigned int slot = 0);

	void unBind();

	const unsigned int GetSlot() const;
};

