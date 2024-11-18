#pragma once
#include "ISprite.h"
#include <raylib.h>

class RaylibSprite : public ISprite
{
public:
	RaylibSprite();
	void LoadImage(const char* path) override;
	void SetPosition(float x, float y) override;
	void SetSize(float w, float h) override;

	Texture2D GetTexture() { return m_Text; }
	Rectangle GetRect() { return m_Rect; }
private:
	Texture2D m_Text;
	Rectangle m_Rect;
};
