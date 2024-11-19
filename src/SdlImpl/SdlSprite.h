#pragma once
#include "Game/Sprite.h"

struct SDL_Renderer;
struct SDL_Texture;

class SdlSprite : public Sprite
{
public:

	SdlSprite(SDL_Renderer* renderer);
	void LoadImage(const char* path) override;

	SDL_Texture* GetTexture() { return m_Texture; }

private:

	SDL_Renderer* m_Renderer = nullptr;
	SDL_Texture* m_Texture = nullptr;
};
