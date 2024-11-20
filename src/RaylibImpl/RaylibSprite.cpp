#include "RaylibSprite.h"

void RaylibSprite::LoadImage(const char* path)
{
	m_Text = LoadTexture(path);
	SetTextureWrap(m_Text, TEXTURE_WRAP_CLAMP);
}

void* RaylibSprite::GetData()
{
	return &m_Text;
}
