#include "RaylibWindow.h"
#include "RaylibTexturePtr.h"
#include "Game/Sprite.h"
#include "Game/Text.h"

void RaylibWindow::Create(const char* title, int width, int height)
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	InitWindow(width, height, title);
}

void RaylibWindow::Quit()
{
	UnloadFont(m_Font);
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

void RaylibWindow::SetFont(const char* path, float size)
{
	m_Font = LoadFont(path);
	m_FontSize = size;
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

TexturePtr* RaylibWindow::CreateTexture()
{
	return new RaylibTexturePtr();
}

void RaylibWindow::Draw(Sprite& sprite)
{
	auto texture = sprite.GetTexture()->As<Texture>();
	Rect spriteRect = sprite.GetRect();
	Rectangle destRect = {spriteRect.x, spriteRect.y, spriteRect.w, spriteRect.h};
	MyColor color = sprite.GetTint();
	DrawTexturePro(*texture, {0.0f, 0.0f, (float)texture->width, (float)texture->height}, destRect, {0,0}, 0.0f, {color.r, color.g, color.b, color.a});
}

void RaylibWindow::Draw(Text& text)
{
	Vec2 pos = text.GetPosition();
	MyColor color = text.GetColor();
	DrawTextEx(m_Font, text.GetText().c_str(), {pos.x, pos.y}, m_FontSize, 0, Color(color.r, color.g, color.b, color.a));
}

int RaylibWindow::GetWidth()
{
	return GetScreenWidth();
}

int RaylibWindow::GetHeight()
{
	return GetScreenHeight();
}
