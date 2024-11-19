#pragma once
#include "IWindow.h"

class RaylibWindow : public IWindow
{
public:

	void Initialize() override;
	void Create(const char* title, int width, int height) override;
	bool IsOpen() override;
	void Update() override;

	float GetFps() override;
	void SetFps(int fps) override;
	void BeginDraw() override;
	void EndDraw() override;
	void Clear(unsigned char r, unsigned char g, unsigned char b) override;

	ISprite* CreateSprite() override;
	void Draw(ISprite&, unsigned char r, unsigned char g, unsigned char b) override;
	void Draw(IText&, unsigned char r, unsigned char g, unsigned char b) override;
	void DrawFps(float x, float y) override;
	int GetWidth() override;
	int GetHeight() override;
};
