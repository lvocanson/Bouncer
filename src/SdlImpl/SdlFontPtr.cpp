#include "SdlFontPtr.h"
#include <SDL3_ttf/SDL_ttf.h>

void SdlFontPtr::LoadFromFile(const char* path)
{
	m_Ptr = TTF_OpenFont(path, m_Size);
	if (m_Ptr == NULL)
	{
		SDL_LogError(0, "Open Font failed: %s", SDL_GetError());
	}
}

void SdlFontPtr::Unload()
{
	TTF_CloseFont(As<TTF_Font>());
}

void SdlFontPtr::SetSize(float size)
{
	FontPtr::SetSize(size);
	if (m_Ptr)
	{
		TTF_SetFontSize(As<TTF_Font>(), size);
	}
}
