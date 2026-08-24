#include "Library.h"
#include "assetManager.h"


Library::Library()
{
	auto error = FT_Init_FreeType(&m_Lib);
	if(error)
	{
		std::cout << "Failed to initialize FT library!" << std::endl;
	}
}


Library::~Library()
{
	//TODO: handle deletes
	for (auto& [name, font] : m_Fonts)
	{
		delete font;
	}
	
	FT_Done_FreeType(m_Lib);
}

//res/fonts/Mx437_IBM_3270pc.ttf
FT_FaceRec_* Library::addFace(std::string name, std::string path, unsigned int slot, assetMan* man)
{
	Font* f = new Font(slot);
	//auto face = f->m_Face;
	//std::string fontPath = FileSystem::getPath(path);
	if (path.empty())
	{
		std::cout << "ERROR::FREETYPE: Failed to load font_name" << std::endl;
	}
	std::string fontPath = std::string(LITE_ENGINE_RES_DIR) + path;
	std::cout << "font path: " << fontPath << std::endl;
	if (FT_Error err = FT_New_Face(m_Lib, fontPath.c_str(), 0, &f->m_Face)) 
	{
		std::cout << "ERROR::FREETYPE: Failed to load font, code: " << err << std::endl;
	}
	std::cout << "loaded face" << std::endl;
	// set size to load glyphs as
	FT_Set_Pixel_Sizes(f->m_Face, 0, 48);
	//FTexture(face, slot);
	
	std::cout << " Ftexture created" << std::endl;
	//man->setFTMap(fontTexture, name);
	//m_FTextures[name] = fontTexture;
	// load first 128 characters of ASCII set
	std::cout << "pre char loading in Library" << std::endl;
	for (unsigned char c = 0; c < 128; c++)
	{
		// Load character glyph 
		if (FT_Load_Char(f->m_Face, c, FT_LOAD_RENDER))
		{
			std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
			continue;
		}
		// now store character for later use
		FTexture* fontTexture = new FTexture(f->m_Face, slot);
		f->addCharacter(fontTexture->getName(), c);
	}
	//glBindTexture(GL_TEXTURE_2D, slot);
	m_Fonts[name] = f;
	
	return f->m_Face;
}
Font* Library::getFont(std::string name)
{
	return m_Fonts[name];
}