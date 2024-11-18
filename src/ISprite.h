#pragma once

class ISprite
{
public:

	virtual void LoadImage(const char* path) = 0;
	virtual void SetPosition(int x, int y) = 0;
	virtual void GetPosition(int& outX, int& outY) = 0;
};
