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
	void ChangeDirectionX() override;
	void ChangeDirectionY() override;

	void SetPosition(float x, float y) override;
	void SetSize(float w, float h) override;
	float GetPosX() override;
	float GetPosY() override;
	float GetSizeX() override;
	float GetSizeY() override;
	float GetSpeedX() override;
	float GetSpeedY() override;

	SDL_Texture* GetTexture() { return m_Texture; }
	SDL_FRect* GetRect() { return &m_Rect; }

private:

	SDL_Renderer* m_Renderer;
	SDL_Texture* m_Texture;
	SDL_FRect m_Rect;
	float m_SpeedX;
	float m_SpeedY;
};
