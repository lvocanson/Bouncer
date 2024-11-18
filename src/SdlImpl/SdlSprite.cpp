#include "SdlSprite.h"
#include <SDL3/SDL.h>

SdlSprite::SdlSprite(SDL_Renderer* renderer)
	: m_Renderer(renderer)
{
}

void SdlSprite::LoadImage(const char* path)
{
	auto surface = SDL_LoadBMP(path);
	if (surface == NULL)
	{
		SDL_LogError(0, "Load BMP failed: %s", SDL_GetError());
		return;
	}

	m_Texture = SDL_CreateTextureFromSurface(m_Renderer, surface);
	if (m_Texture == NULL)
	{
		SDL_LogError(0, "Texture creation failed: %s", SDL_GetError());
		return;
	}
}

void SdlSprite::SetPosition(int x, int y)
{
	m_Rect.x = static_cast<float>(x);
	m_Rect.y = static_cast<float>(y);
}

void SdlSprite::SetSize(int w, int h)
{
	m_Rect.w = static_cast<float>(w);
	m_Rect.h = static_cast<float>(h);
}
