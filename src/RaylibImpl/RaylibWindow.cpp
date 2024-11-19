#include "RaylibWindow.h"
#include "RaylibSprite.h"
#include <raylib.h>
#include "Resources.h"

void RaylibWindow::Initialize()
{
}

void RaylibWindow::Create(const char* title, int width, int height)
{
	InitWindow(width, height, title);
}

bool RaylibWindow::IsOpen()
{
	return !WindowShouldClose();
}

void RaylibWindow::Update()
{

}

float RaylibWindow::GetFPS()
{
	return 0;
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

void RaylibWindow::Draw(ISprite& sprite)
{
	auto& raylibSprite = (RaylibSprite&)sprite;
	auto texture = raylibSprite.GetTexture();

	DrawTexturePro(texture, {0.0f, 0.0f, (float)texture.width, (float)texture.height}, raylibSprite.GetRect(), {0,0}, 0.0f, WHITE);
}

void RaylibWindow::Draw(IText&)
{

}

int RaylibWindow::GetWidth()
{
	return GetScreenWidth();
}

int RaylibWindow::GetHeight()
{
	return GetScreenHeight();
}