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
	void BeginDraw() override;
	void EndDraw() override;
	void Draw(ISprite&) override;

	SDL_Renderer* GetRenderer() { return m_Renderer; }

private:

	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;
};
