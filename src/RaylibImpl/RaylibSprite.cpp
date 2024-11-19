#include "RaylibSprite.h"

RaylibSprite::RaylibSprite()
	: m_Rect()
	, m_Text()
	, m_SpeedX()
	, m_SpeedY()
{
}

void RaylibSprite::LoadImage(const char* path)
{
	m_Text = LoadTexture(path);
	SetTextureWrap(m_Text, TEXTURE_WRAP_CLAMP);
}

void RaylibSprite::ChangeDirectionX()
{
	m_SpeedX *= -1.0f;
}

void RaylibSprite::ChangeDirectionY()
{
	m_SpeedY *= -1.0f;
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

void RaylibSprite::SetSpeed(float x, float y)
{
	m_SpeedX = x;
	m_SpeedY = y;
}

float RaylibSprite::GetPosX()
{
	return m_Rect.x;
}

float RaylibSprite::GetPosY()
{
	return m_Rect.y;
}

float RaylibSprite::GetSizeX()
{
	return m_Rect.width;
}

float RaylibSprite::GetSizeY()
{
	return m_Rect.height;
}

float RaylibSprite::GetSpeedX()
{
	return m_SpeedX;
}

float RaylibSprite::GetSpeedY()
{
	return m_SpeedY;
}


