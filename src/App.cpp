#include "App.h"
#include "IWindow.h"
#include "ISprite.h"
#include "MyMath.h"
#include "GameData.h"
#include "Resources.h"
#include <algorithm>

App::App(Lib libToUse)
	: m_Maker(libToUse)
{
	InitRand();

	m_Window = m_Maker.MakeWindow();
	m_Window->Initialize();
	m_Window->Create(Resources::AppName, 1600, 900);
	m_Window->SetFont(Resources::FontPath, Resources::FontSize);

	m_Sprites.reserve(GameData::SpriteNumber);
	for (int i = 0; i < GameData::SpriteNumber; i++)
	{
		CreateSprite();
	}
}

int App::Run()
{
	float deltaTime = 0;
	float fpsTimer = 0;
	char fpsText[255]{0};

	while (m_Window->IsOpen())
	{
		UpdatePosition(deltaTime);

		m_Window->BeginDraw();
		m_Window->Clear(15, 15, 10);

		for (auto sprite : m_Sprites)
		{
			m_Window->Draw(*sprite, RandByte(), RandByte(), RandByte());
		}

		if ((fpsTimer += deltaTime) > 1)
		{
			sprintf_s(fpsText, "FPS: %i", static_cast<int>(1 / deltaTime));
			fpsTimer--;
		}
		m_Window->Draw(fpsText, 255, 255, 255);

		m_Window->EndDraw();

		deltaTime = m_Window->Update();
	}
	return 0;
}

void App::CreateSprite()
{
	auto sprite = m_Window->CreateSprite();

	int SpriteSize = Rand(GameData::MinSpriteSize, GameData::MaxSpriteSize);
	int SpriteX = Rand(0, m_Window->GetWidth() - SpriteSize);
	int SpriteY = Rand(0, m_Window->GetHeight() - SpriteSize);

	float SpeedX = Randf(GameData::MinSpriteSpeed, GameData::MaxSpriteSpeed);
	float SpeedY = Randf(GameData::MinSpriteSpeed, GameData::MaxSpriteSpeed);

	if (CoinFlip())
	{
		sprite->ChangeDirectionX();
	}
	if (CoinFlip())
	{
		sprite->ChangeDirectionY();
	}

	sprite->SetSpeed(SpeedX, SpeedY);
	sprite->LoadImage(Resources::CirclePath);
	sprite->SetPosition(static_cast<float>(SpriteX), static_cast<float>(SpriteY));
	sprite->SetSize(static_cast<float>(SpriteSize), static_cast<float>(SpriteSize));

	m_Sprites.emplace_back(sprite);
}

void App::UpdatePosition(float dt)
{
	for (auto sprite : m_Sprites)
	{
		float newX = sprite->GetPosX() + sprite->GetSpeedX() * dt;
		float newY = sprite->GetPosY() + sprite->GetSpeedY() * dt;

		float minX = 0.0f;
		float maxX = m_Window->GetWidth() - sprite->GetSizeX();
		float minY = 0.0f;
		float maxY = m_Window->GetHeight() - sprite->GetSizeY();

		if (newX <= minX || newX >= maxX)
		{
			sprite->ChangeDirectionX();
			newX = std::clamp(newX, minX, maxX);
		}

		if (newY <= minY || newY >= maxY)
		{
			sprite->ChangeDirectionY();
			newY = std::clamp(newY, minY, maxY);
		}

		sprite->SetPosition(newX, newY);
	}
}
