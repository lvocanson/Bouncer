#include "App.h"
#include "IWindow.h"
#include "ISprite.h"
#include "Resources.h"

App::App(Lib libToUse)
	: m_Maker(libToUse)
{
	m_Window = m_Maker.MakeWindow();
	m_Window->Initialize();

	using namespace Resources;
	m_Window->Create(AppName, 1600, 900);

	static constexpr int SpriteNb = 1;
	m_Sprites.reserve(SpriteNb);
	for (int i = 0; i < SpriteNb; i++)
	{
		auto sprite = m_Window->CreateSprite();
		static constexpr float SpriteX = 10;
		static constexpr float SpriteY = 10;
		static constexpr float SpriteW = 100;
		static constexpr float SpriteH = 100;

		sprite->LoadImage(Resources::CirclePath);
		sprite->SetPosition(SpriteX + SpriteW * i, SpriteY);
		sprite->SetSize(SpriteW, SpriteH);

		m_Sprites.emplace_back(sprite);
	}
}

int App::Run()
{
	while (m_Window->IsOpen())
	{
		m_Window->Update();

		m_Window->BeginDraw();
		m_Window->Clear(15, 15, 10);

		for (auto sprite : m_Sprites)
		{
			m_Window->Draw(*sprite);
		}
		m_Window->EndDraw();
	}
	return 0;
}
