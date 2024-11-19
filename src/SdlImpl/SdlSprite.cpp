#include "SdlSprite.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

SdlSprite::SdlSprite(SDL_Renderer* renderer)
	: m_Renderer(renderer)
	, m_Rect()
	, m_Texture()
{
	m_SpeedX = 5;
	m_SpeedY = 5;
}

void SdlSprite::LoadImage(const char* path)
{
	auto surface = IMG_Load(path);
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

void SdlSprite::ChangeDirectionX()
{
	m_SpeedX *= -1.0f;
}

void SdlSprite::ChangeDirectionY()
{
	m_SpeedY *= -1.0f;
}

void SdlSprite::SetPosition(float x, float y)
{
	m_Rect.x = x;
	m_Rect.y = y;
}

void SdlSprite::SetSize(float w, float h)
{
	m_Rect.w = w;
	m_Rect.h = h;
}

float SdlSprite::GetPosX()
{
	return m_Rect.x;
}

float SdlSprite::GetPosY()
{
	return m_Rect.y;
}
float SdlSprite::GetSizeX()
{
	return m_Rect.w;
}

float SdlSprite::GetSizeY()
{
	return m_Rect.h;
}

float SdlSprite::GetSpeedX()
{
	return m_SpeedX;
}

float SdlSprite::GetSpeedY()
{
	return m_SpeedY;
}


