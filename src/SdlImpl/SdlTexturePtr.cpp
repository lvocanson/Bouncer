#include "SdlTexturePtr.h"
#include <SDL3_image/SDL_image.h>

SdlTexturePtr::SdlTexturePtr(SDL_Renderer* renderer)
	: m_Renderer(renderer)
{
}

void SdlTexturePtr::LoadFromFile(const char* path)
{

	auto surface = IMG_Load(path);
	if (surface == NULL)
	{
		SDL_LogError(0, "IMG load failed: %s", SDL_GetError());
	}

	m_Ptr = SDL_CreateTextureFromSurface(m_Renderer, surface);
	if (m_Ptr == NULL)
	{
		SDL_LogError(0, "Texture creation failed: %s", SDL_GetError());
	}

	SDL_DestroySurface(surface);
}

void SdlTexturePtr::Unload()
{
	SDL_DestroyTexture(As<SDL_Texture>());
}
