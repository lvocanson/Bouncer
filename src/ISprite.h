#pragma once

class ISprite
{
public:

	virtual void LoadImage(const char* path) = 0;
	virtual void SetPosition(float x, float y) = 0;
	virtual float GetPosX() = 0;
	virtual float GetPosY() = 0;
	virtual void SetSize(float w, float h) = 0;
	virtual float GetSizeX() = 0;
	virtual float GetSizeY() = 0;
	virtual void ChangeDirectionX() = 0;
	virtual void ChangeDirectionY() = 0;
	virtual float GetSpeedX() = 0;
	virtual float GetSpeedY() = 0;

};
