#pragma once
#include "Game/IWindow.h"
#include <SDL3/SDL_stdinc.h>

struct SDL_Window;
struct SDL_Renderer;
struct TTF_TextEngine;
struct TTF_Font;

class SdlWindow : public IWindow
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
	void Draw(Text&, FontPtr&) override;

	int GetWidth() override;
	int GetHeight() override;

private:

	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;
	TTF_TextEngine* m_Engine = nullptr;

	Uint64 m_LastFrameCounter;
	Uint64 m_CountPerSecond;
};
