#include "SdlTexturePtr.h"
#include <SDL3_image/SDL_image.h>

void SdlTexturePtr::LoadFromFile(const char* path)
{
	m_Ptr = IMG_Load(path);
	if (m_Ptr == NULL)
	{
		SDL_LogError(0, "IMG load failed: %s", SDL_GetError());
	}
}

void SdlTexturePtr::Unload()
{
	SDL_DestroySurface(As<SDL_Surface>());
	m_Ptr = nullptr;
}
