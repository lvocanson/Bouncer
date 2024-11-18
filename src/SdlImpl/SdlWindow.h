#pragma once
#include "IWindow.h"

struct SDL_Window;
struct SDL_Renderer;

class SdlWindow : public IWindow
{
public:

	void Initialize() override;
	void Create(const char* title, int width, int height) override;
	bool IsOpen() override;
	void Update() override;

	float GetFPS() override;
	void BeginDraw() override;
	void EndDraw() override;
	void Clear(unsigned char r, unsigned char g, unsigned char b) override;
	
	ISprite* CreateSprite() override;
	void Draw(ISprite&) override;
	void Draw(IText&) override;

	void Quit();

private:

	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;
};
