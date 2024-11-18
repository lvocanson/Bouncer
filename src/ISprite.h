#pragma once

class ISprite
{
public:

	virtual void LoadImage(const char* path) = 0;
	virtual void SetPosition(float x, float y) = 0;
	virtual void SetSize(float w, float h) = 0;
};
