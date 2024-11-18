#include "RaylibSprite.h"

RaylibSprite::RaylibSprite()
	: m_Rect()
	, m_Text()
{
}

void RaylibSprite::LoadImage(const char* path)
{
	m_Text = LoadTexture(path);
	SetTextureWrap(m_Text, TEXTURE_WRAP_CLAMP);
	/*if (m_Text == NULL)
	{
		SDL_LogError(0, "Load BMP failed: %s", SDL_GetError());
		return;
	}*/
}

void RaylibSprite::SetPosition(float x, float y)
{
	m_Rect.x = x;
	m_Rect.y = y;
}

void RaylibSprite::SetSize(float w, float h)
{
	m_Rect.width = w;
	m_Rect.height = h;
}
