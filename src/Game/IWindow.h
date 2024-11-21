#pragma once
#include "Utils/MyColor.h"
#include <vector>

class TexturePtr;
class Sprite;
class Text;

class IWindow
{
public:

	virtual void Create(const char* title, int width, int height) = 0;
	virtual void Quit() = 0;
	virtual bool IsOpen() = 0;

	// Returns deltaTime
	virtual float Update() = 0;

	virtual void SetFont(const char* path, float size) = 0;

	virtual void BeginDraw() = 0;
	virtual void EndDraw() = 0;
	virtual void Clear(MyColor color) = 0;
	
	virtual TexturePtr* CreateTexture() = 0;
	virtual void Draw(Sprite&) = 0;
	virtual void Draw(Text&) = 0;

	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;
};