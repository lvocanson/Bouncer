#pragma once
#include "IWindow.h"
#include <SDL3/SDL_stdinc.h>

struct SDL_Window;
struct SDL_Renderer;
struct TTF_TextEngine;
struct TTF_Font;

class SdlWindow : public IWindow
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

	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;

	TTF_TextEngine* m_Engine = nullptr;
	TTF_Font* m_Font = nullptr;

	Uint64 m_LastFrameCounter;
	Uint64 m_CountPerSecond;
};
