#include "App.h"
#include "IWindow.h"
#include "Resources.h"

App::App(Lib libToUse)
	: m_Maker(libToUse)
{
	m_Window = m_Maker.MakeWindow();
	m_Window->Initialize();

	using namespace Resources;
	m_Window->Create(AppName, 1600, 900);

	static constexpr int SpriteNb = 20;
	m_Sprites.reserve(SpriteNb);
	for (int i = 0; i < SpriteNb; i++)
	{
		m_Sprites.emplace_back(m_Window->CreateSprite());
	}
}

int App::Run()
{
	while (m_Window->IsOpen())
	{
		m_Window->Update();

		m_Window->BeginDraw();
		m_Window->Clear(200, 25, 25);
		for (auto sprite : m_Sprites)
		{
			m_Window->Draw(*sprite);
		}
		m_Window->EndDraw();
	}
	return 0;
}
