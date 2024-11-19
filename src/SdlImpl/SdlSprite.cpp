#include "SdlSprite.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

SdlSprite::SdlSprite(SDL_Renderer* renderer)
	: m_Renderer(renderer)
{
}

void SdlSprite::LoadImage(const char* path)
{
	auto surface = IMG_Load(path);
	if (surface == NULL)
	{
		SDL_LogError(0, "IMG load failed: %s", SDL_GetError());
		return;
	}

	m_Texture = SDL_CreateTextureFromSurface(m_Renderer, surface);
	if (m_Texture == NULL)
	{
		SDL_LogError(0, "Texture creation failed: %s", SDL_GetError());
		return;
	}
}
