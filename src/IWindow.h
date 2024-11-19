#pragma once

class ISprite;
class IText;

class IWindow
{
public:

	virtual void Initialize() = 0;
	virtual void Create(const char* title, int width, int height) = 0;
	virtual bool IsOpen() = 0;
	virtual void Update() = 0;

	virtual float GetFps() = 0;
	virtual void SetFps(int fps) = 0;
	virtual void BeginDraw() = 0;
	virtual void EndDraw() = 0;
	virtual void Clear(unsigned char r, unsigned char g, unsigned char b) = 0;
	
	virtual ISprite* CreateSprite() = 0;
	virtual void Draw(ISprite&, unsigned char r, unsigned char g, unsigned char b) = 0;
	virtual void Draw(IText&, unsigned char r, unsigned char g, unsigned char b) = 0;
	virtual void DrawFps(float x, float y) = 0;

	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;
};