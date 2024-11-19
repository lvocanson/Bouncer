#include "App.h"
#include "Game/IWindow.h"
#include "Game/Sprite.h"
#include "Game/Text.h"
#include "Game/Resources.h"
#include "Utils/RandomHelper.h"
#include <format>

App::App(Lib libToUse)
	: m_Maker(libToUse)
{
	InitRand();

	m_Window = m_Maker.MakeWindow();
	m_Window->Create(Resources::AppName, Resources::WindowWidth, Resources::WindowHeight);
	m_Window->SetFont(Resources::FontPath, Resources::FontSize);

	m_Sprites.reserve(Resources::SpriteNumber);
	for (int i = 0; i < Resources::SpriteNumber; i++)
	{
		CreateSprite();
	}
}

int App::Run()
{
	float deltaTime = 0;
	float fpsTimer = 0;
	Text fpsText;
	fpsText.SetPosition(Resources::FpsTextPosition);
	fpsText.SetColor(Resources::FpsTextColor);

	while (m_Window->IsOpen())
	{
		UpdatePosition(deltaTime);

		m_Window->BeginDraw();
		m_Window->Clear(Resources::BackgroundColor);

		for (auto sprite : m_Sprites)
		{
			m_Window->Draw(*sprite);
		}

		if ((fpsTimer += deltaTime) > 1)
		{
			fpsText.SetText(std::format("FPS: {}", static_cast<int>(1 / deltaTime)));
			fpsTimer--;
		}
		m_Window->Draw(fpsText);

		m_Window->EndDraw();

		deltaTime = m_Window->Update();
	}
	return 0;
}

void App::CreateSprite()
{
	auto sprite = m_Window->CreateSprite();
	sprite->LoadImage(Resources::SpriteTexPath);

	float size = Randf(Resources::MinSpriteSize, Resources::MaxSpriteSize);
	sprite->SetSize({size, size});

	float x = Randf(0, m_Window->GetWidth() - size);
	float y = Randf(0, m_Window->GetHeight() - size);
	sprite->SetPosition({x, y});

	float speed = Randf(Resources::MinSpriteSpeed, Resources::MaxSpriteSpeed);
	sprite->SetVelocity(RandUnitVec() * speed);

	sprite->SetTint(RandColor());

	m_Sprites.emplace_back(sprite);
}

void App::UpdatePosition(float dt)
{
	for (auto sprite : m_Sprites)
	{
		sprite->ApplyVelocity(dt);
		Rect spriteRect = sprite->GetRect();
		Vec2 velocity = sprite->GetVelocity();

		float maxX = m_Window->GetWidth() - spriteRect.w;
		float maxY = m_Window->GetHeight() - spriteRect.h;

		if (spriteRect.x < 0.0f)
		{
			spriteRect.x = -spriteRect.x;
			velocity.x = -velocity.x;
		}
		else if (spriteRect.x > maxX)
		{
			spriteRect.x = 2 * maxX - spriteRect.x;
			velocity.x = -velocity.x;
		}

		if (spriteRect.y < 0.0f)
		{
			spriteRect.y = -spriteRect.y;
			velocity.y = -velocity.y;
		}
		else if (spriteRect.y > maxY)
		{
			spriteRect.y = 2 * maxY - spriteRect.y;
			velocity.y = -velocity.y;
		}

		sprite->SetVelocity(velocity);
		sprite->SetPosition(spriteRect.position);
	}
}
