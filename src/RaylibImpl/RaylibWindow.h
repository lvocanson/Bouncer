#pragma once
#include "IWindow.h"

class RaylibWindow : public IWindow
{
public:

	void Initialize() override;
	void Create(const char* title, int width, int height) override;
	bool IsOpen() override;
	void Update() override;

	void BeginDraw() override;
	void EndDraw() override;
	void Clear(unsigned char r, unsigned char g, unsigned char b) override;

	ISprite* CreateSprite() override;
	void Draw(ISprite&) override;
};
