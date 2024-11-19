#pragma once

class ISprite;
class IText;

class IWindow
{
public:

	virtual void Initialize() = 0;
	virtual void Create(const char* title, int width, int height) = 0;
	virtual void Quit() = 0;
	virtual bool IsOpen() = 0;

	// Returns deltaTime
	virtual float Update() = 0;

	virtual void SetFont(const char* path, float size) = 0;

	virtual void BeginDraw() = 0;
	virtual void EndDraw() = 0;
	virtual void Clear(unsigned char r, unsigned char g, unsigned char b) = 0;
	
	virtual ISprite* CreateSprite() = 0;
	virtual void Draw(ISprite&, unsigned char r, unsigned char g, unsigned char b) = 0;
	virtual void Draw(char* text, unsigned char r, unsigned char g, unsigned char b) = 0;

	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;
};