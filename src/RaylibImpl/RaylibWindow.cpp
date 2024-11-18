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

void RaylibWindow::BeginDraw()
{
	BeginDrawing();
}

void RaylibWindow::EndDraw()
{
}

void RaylibWindow::Clear(unsigned char r, unsigned char g, unsigned char b)
{
}

ISprite* RaylibWindow::CreateSprite()
{
	return new RaylibSprite();
}

void RaylibWindow::Draw(ISprite& sprite)
{
	DrawTexture(((RaylibSprite&)sprite).GetTexture(), 0, 0, RED);
}
