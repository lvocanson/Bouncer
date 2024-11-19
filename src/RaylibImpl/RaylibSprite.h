#pragma once
#include "Game/Sprite.h"
#include <raylib.h>

class RaylibSprite : public Sprite
{
public:

	void LoadImage(const char* path) override;
	Texture2D GetTexture() { return m_Text; }

private:

	Texture2D m_Text;
};
