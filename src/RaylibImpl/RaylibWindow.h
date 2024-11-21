#pragma once
#include "Game/IWindow.h"
#include <raylib.h>

class RaylibWindow : public IWindow
{
public:

	void Create(const char* title, int width, int height) override;
	void Quit() override;
	bool IsOpen() override;

	float Update() override;

	void BeginDraw() override;
	void EndDraw() override;
	void Clear(MyColor color) override;

	void Draw(Sprite&) override;
	void Draw(Text&, FontPtr& fontPtr) override;

	int GetWidth() override;
	int GetHeight() override;
};
