#pragma once
#include "Game/TexturePtr.h"

struct SDL_Renderer;

class SdlTexturePtr : public TexturePtr
{
public:

	SdlTexturePtr(SDL_Renderer*);
	void LoadFromFile(const char* path) override;
	void Unload() override;

private:

	SDL_Renderer* m_Renderer;
};
