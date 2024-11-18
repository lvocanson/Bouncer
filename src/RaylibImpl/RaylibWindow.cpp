#include "RaylibWindow.h"
#include "RaylibSprite.h"

void RaylibWindow::Initialize()
{
}

void RaylibWindow::Create(const char* title, int width, int height)
{
}

bool RaylibWindow::IsOpen()
{
	return false;
}

void RaylibWindow::BeginDraw()
{
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

void RaylibWindow::Draw(ISprite&)
{
}
