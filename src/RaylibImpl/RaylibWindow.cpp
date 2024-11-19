#include "RaylibWindow.h"
#include "RaylibSprite.h"

void RaylibWindow::Initialize()
{
}

void RaylibWindow::Create(const char* title, int width, int height)
{
	InitWindow(width, height, title);
}

void RaylibWindow::Quit()
{
	UnloadFont(m_Font);
}

bool RaylibWindow::IsOpen()
{
	return !WindowShouldClose();
}

float RaylibWindow::Update()
{
	return GetFrameTime();
}

void RaylibWindow::SetFont(const char* path, float size)
{
	m_Font = LoadFont(path);
}

void RaylibWindow::BeginDraw()
{
	BeginDrawing();
}

void RaylibWindow::EndDraw()
{
	EndDrawing();
}

void RaylibWindow::Clear(unsigned char r, unsigned char g, unsigned char b)
{
	ClearBackground(Color(r, g, b));
}

ISprite* RaylibWindow::CreateSprite()
{
	return new RaylibSprite();
}

void RaylibWindow::Draw(ISprite& sprite, unsigned char r, unsigned char g, unsigned char b)
{
	auto& raylibSprite = (RaylibSprite&)sprite;
	auto texture = raylibSprite.GetTexture();

	DrawTexturePro(texture, {0.0f, 0.0f, (float)texture.width, (float)texture.height}, raylibSprite.GetRect(), {0,0}, 0.0f, Color(r,g,b));
}

void RaylibWindow::Draw(char* text, unsigned char r, unsigned char g, unsigned char b)
{
	// TODO
}

int RaylibWindow::GetWidth()
{
	return GetScreenWidth();
}

int RaylibWindow::GetHeight()
{
	return GetScreenHeight();
}