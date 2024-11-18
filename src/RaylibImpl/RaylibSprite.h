#pragma once
#include "ISprite.h"

class RaylibSprite : public ISprite
{
public:

	void LoadImage(const char* path) override;
	void SetPosition(int x, int y) override;
	void GetPosition(int& outX, int& outY) override;
};
