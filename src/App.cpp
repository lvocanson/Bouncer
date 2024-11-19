#include "App.h"
#include "IWindow.h"
#include "ISprite.h"
#include "Resources.h"
#include <stdlib.h>
#include <time.h>

App::App(Lib libToUse)
	: m_Maker(libToUse)
{
	m_Window = m_Maker.MakeWindow();
	m_Window->Initialize();

	using namespace Resources;
	m_Window->Create(AppName, 1600, 900);
	//m_Window->SetFps(500);

	static constexpr int SpriteNb = 10;
	m_Sprites.reserve(SpriteNb);
	srand(time(NULL));
	
	for (int i = 0; i < SpriteNb; i++)
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
			m_Window->Draw(*sprite);
			//m_Window->DrawFps(10,10);
		}
		
		m_Window->EndDraw();
	}
	return 0;
}

void App::CreateSprite() 
{
	auto sprite = m_Window->CreateSprite();

	int SpriteSize = rand() % 100 + 50;

	int SpriteX = rand() % (m_Window->GetWidth() - SpriteSize);
	int SpriteY = rand() % (m_Window->GetHeight() - SpriteSize);

	float SpeedX = rand() % 1 + 0.5;
	float SpeedY = rand() % 1 + 0.5;

	if (rand() % 2 == 1) {
		sprite->ChangeDirectionX();
	}
	if (rand() % 2 == 1) {
		sprite->ChangeDirectionY();
	}
	sprite->SetSpeed(SpeedX, SpeedY);
	sprite->LoadImage(Resources::CirclePath);
	sprite->SetPosition(SpriteX, SpriteY);
	sprite->SetSize(SpriteSize, SpriteSize);

	m_Sprites.emplace_back(sprite);
}

void App::UpdatePosition()
{
	for (auto sprite : m_Sprites)
	{
		float x = sprite->GetPosX();
		float y = sprite->GetPosY();

		sprite->SetPosition(x+= sprite->GetSpeedX(), y += sprite->GetSpeedY());

		if ((sprite->GetPosX() >= (m_Window->GetWidth() - sprite->GetSizeX()) || sprite->GetPosX() < 0))
			sprite->ChangeDirectionX();
		if ((sprite->GetPosY() >= (m_Window->GetHeight() - sprite->GetSizeY()) || sprite->GetPosY() < 0))
			sprite->ChangeDirectionY();
	}
}
