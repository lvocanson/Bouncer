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
		m_Sprites.emplace_back(m_Maker.MakeSprite(m_Window));
	}
}

int App::Run()
{
	while (m_Window->IsOpen())
	{
		m_Window->BeginDraw();
		for (auto sprite : m_Sprites)
		{
			m_Window->Draw(*sprite);
		}
		m_Window->EndDraw();
	}
	return 0;
}
