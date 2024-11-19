#pragma once
#include "ISprite.h"
#include <raylib.h>

class RaylibSprite : public ISprite
{
public:
	RaylibSprite();
	void LoadImage(const char* path) override;
	void ChangeDirectionX() override;
	void ChangeDirectionY() override;

	void SetPosition(float x, float y) override;
	void SetSize(float w, float h) override;
	float GetPosX() override;
	float GetPosY() override;
	float GetSizeX() override;
	float GetSizeY() override;
	float GetSpeedX() override;
	float GetSpeedY() override;

	Texture2D GetTexture() { return m_Text; }
	Rectangle GetRect() { return m_Rect; }

private:
	Texture2D m_Text;
	Rectangle m_Rect;
	float m_SpeedX;
	float m_SpeedY;
};
