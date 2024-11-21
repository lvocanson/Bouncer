#pragma once
#include "Utils/MyColor.h"
#include <vector>

class TexturePtr;
class FontPtr;
class Sprite;
class Text;

class IWindow
{
public:

	virtual ~IWindow() = default;

	virtual void Create(const char* title, int width, int height) = 0;
	virtual void Quit() = 0;
	virtual bool IsOpen() = 0;

	// Returns deltaTime
	virtual float Update() = 0;

	virtual void BeginDraw() = 0;
	virtual void EndDraw() = 0;
	virtual void Clear(MyColor color) = 0;

	virtual void Draw(Sprite&) = 0;
	virtual void Draw(Text&, FontPtr&) = 0;

	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;
};