#include "RaylibWindow.h"
#include "Game/FontPtr.h"
#include "Game/Sprite.h"
#include "Game/Text.h"
#include "Game/TexturePtr.h"

void RaylibWindow::Create(const char* title, int width, int height)
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(width, height, title);
}

void RaylibWindow::Quit()
{
	CloseWindow();
}

bool RaylibWindow::IsOpen()
{
	return !WindowShouldClose();
}

float RaylibWindow::Update()
{
	return GetFrameTime();
}

void RaylibWindow::BeginDraw()
{
	BeginDrawing();
}

void RaylibWindow::EndDraw()
{
	EndDrawing();
}

void RaylibWindow::Clear(MyColor color)
{
	ClearBackground({color.r, color.g, color.b, color.a});
}

void RaylibWindow::Draw(Sprite& sprite)
{
	auto texture = sprite.GetTexture()->As<Texture>();
	Rect spriteRect = sprite.GetRect();
	Rectangle destRect = {spriteRect.x, spriteRect.y, spriteRect.w, spriteRect.h};
	MyColor color = sprite.GetTint();
	DrawTexturePro(*texture, {0.0f, 0.0f, (float)texture->width, (float)texture->height}, destRect, {0,0}, 0.0f, {color.r, color.g, color.b, color.a});
}

void RaylibWindow::Draw(Text& text, FontPtr& fontPtr)
{
	Vec2 pos = text.GetPosition();
	MyColor color = text.GetColor();
	DrawTextEx(*fontPtr.As<Font>(), text.GetText().c_str(), {pos.x, pos.y}, fontPtr.GetSize(), 0, Color(color.r, color.g, color.b, color.a));
}

int RaylibWindow::GetWidth()
{
	return GetScreenWidth();
}

int RaylibWindow::GetHeight()
{
	return GetScreenHeight();
}
