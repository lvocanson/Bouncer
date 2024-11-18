#pragma once
#include "ISprite.h"
#include <raylib.h>

class RaylibSprite : public ISprite
{
public:
	void LoadImage(const char* path) override;
	void SetPosition(int x, int y) override;
	void SetSize(int w, int h) override;

	Texture2D GetTexture() { return m_Text; }

private:
	Texture2D m_Text;
};
