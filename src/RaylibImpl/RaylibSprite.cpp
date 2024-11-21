#include "RaylibSprite.h"

void RaylibSprite::LoadImage(const char* path)
{
	m_Text = LoadTexture(path);
	SetTextureWrap(m_Text, TEXTURE_WRAP_CLAMP);
}

MyTexture* RaylibSprite::GetTexture()
{
	return &m_Text;
}
