#include "App.h"
#include "IWindow.h"
#include "ISprite.h"
#include "MyMath.h"
#include "GameData.h"
#include "Resources.h"

App::App(Lib libToUse)
	: m_Maker(libToUse)
{
	InitRand();

	m_Window = m_Maker.MakeWindow();
	m_Window->Initialize();
	m_Window->Create(Resources::AppName, 1600, 900);

	m_Sprites.reserve(GameData::SpriteNumber);
	for (int i = 0; i < GameData::SpriteNumber; i++)
	{
		CreateSprite();
	}
}

int App::Run()
{
	while (m_Window->IsOpen())
	{
		m_Window->Update();
		UpdatePosition();
		m_Window->BeginDraw();
		m_Window->Clear(15, 15, 10);

		for (auto sprite : m_Sprites)
		{
			m_Window->Draw(*sprite, RandByte(), RandByte(), RandByte());
			m_Window->DrawFps(10, 10);
		}

		m_Window->EndDraw();
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

void App::UpdatePosition()
{
	for (auto sprite : m_Sprites)
	{
		float x = sprite->GetPosX();
		float y = sprite->GetPosY();

		sprite->SetPosition(x += sprite->GetSpeedX(), y += sprite->GetSpeedY());

		if ((sprite->GetPosX() >= (m_Window->GetWidth() - sprite->GetSizeX()) || sprite->GetPosX() < 0))
			sprite->ChangeDirectionX();
		if ((sprite->GetPosY() >= (m_Window->GetHeight() - sprite->GetSizeY()) || sprite->GetPosY() < 0))
			sprite->ChangeDirectionY();
	}
}
