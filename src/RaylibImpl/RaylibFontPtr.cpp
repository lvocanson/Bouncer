#include "RaylibFontPtr.h"

void RaylibFontPtr::LoadFromFile(const char* path)
{
	m_Font = LoadFont(path);
	m_Ptr = &m_Font;
}

void RaylibFontPtr::Unload()
{
	UnloadFont(m_Font);
	m_Ptr = nullptr;
}
