#pragma once
#include "ISprite.h"
#include <SDL3/SDL_rect.h>

struct SDL_Renderer;
struct SDL_Texture;

class SdlSprite : public ISprite
{
public:

	SdlSprite(SDL_Renderer* renderer);
	void LoadImage(const char* path) override;
	void SetPosition(int x, int y) override;
	void SetSize(int w, int h) override;

	SDL_Texture* GetTexture() { return m_Texture; }
	SDL_FRect* GetRect() { return &m_Rect; }

private:

	SDL_Renderer* m_Renderer;
	SDL_Texture* m_Texture;
	SDL_FRect m_Rect;
};
