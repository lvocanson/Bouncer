#pragma once
#include "Game/Sprite.h"
#include <raylib.h>

class RaylibSprite : public Sprite
{
public:

	void LoadImage(const char* path) override;
	MyTexture* GetTexture() override;

private:

	Texture2D m_Text;
};
