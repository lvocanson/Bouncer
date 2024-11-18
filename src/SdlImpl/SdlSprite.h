#pragma once
#include "ISprite.h"

struct SDL_Renderer;

class SdlSprite : public ISprite
{
public:

	SdlSprite(SDL_Renderer* renderer);
	void LoadImage(const char* path) override;
	void SetPosition(int x, int y) override;
	void GetPosition(int& outX, int& outY) override;

private:

};
