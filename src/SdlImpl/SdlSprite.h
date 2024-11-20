#pragma once
#include "Game/Sprite.h"

struct SDL_Renderer;
struct SDL_Texture;

class SdlSprite : public Sprite
{
public:

	SdlSprite(SDL_Renderer* renderer);
	void LoadImage(const char* path) override;
	void* GetData() override;

private:

	SDL_Renderer* m_Renderer = nullptr;
	SDL_Texture* m_Texture = nullptr;
};
