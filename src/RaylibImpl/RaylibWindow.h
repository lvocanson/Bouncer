#pragma once
#include "IWindow.h"
#include <raylib.h>

class RaylibWindow : public IWindow
{
public:

	void Initialize() override;
	void Create(const char* title, int width, int height) override;
	void Quit() override;
	bool IsOpen() override;
	float Update() override;

	void SetFont(const char* path, float size) override;

	void BeginDraw() override;
	void EndDraw() override;
	void Clear(unsigned char r, unsigned char g, unsigned char b) override;

	ISprite* CreateSprite() override;
	void Draw(ISprite&, unsigned char r, unsigned char g, unsigned char b) override;
	void Draw(char* text, unsigned char r, unsigned char g, unsigned char b) override;
	int GetWidth() override;
	int GetHeight() override;

private:

	Font m_Font;
};
