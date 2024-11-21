#pragma once
#include "Game/FontPtr.h"

struct SDL_Renderer;
struct TTF_TextEngine;

class SdlFontPtr : public FontPtr
{
public:

	void LoadFromFile(const char* path) override;
	void Unload() override;
	void SetSize(float size) override;
};
