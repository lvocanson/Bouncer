#include "RaylibTexturePtr.h"
#include <raylib.h>

void RaylibTexturePtr::LoadFromFile(const char* path)
{
	m_Texture = LoadTexture(path);
	m_Ptr = &m_Texture;
}

void RaylibTexturePtr::Unload()
{
	UnloadTexture(m_Texture);
}
