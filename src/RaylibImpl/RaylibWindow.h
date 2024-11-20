#pragma once
#include "Game/IWindow.h"
#include <raylib.h>

class RaylibWindow : public IWindow
{
public:

	void Create(const char* title, int width, int height) override;
	void Quit() override;
	bool IsOpen() override;

	float Update(std::vector<Sprite*>& sprites) override;

	void SetFont(const char* path, float size) override;

	void BeginDraw() override;
	void EndDraw() override;
	void Clear(MyColor color) override;

	Sprite* CreateSprite() override;
	void Draw(Sprite&) override;
	void Draw(Text&) override;
	int GetWidth() override;
	int GetHeight() override;

private:

	Font m_Font;
	float m_FontSize;
};
