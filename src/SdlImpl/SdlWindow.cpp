#include "SdlWindow.h"
#include "Game/FontPtr.h"
#include "Game/Sprite.h"
#include "Game/Text.h"
#include "Game/TexturePtr.h"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

SdlWindow::~SdlWindow()
{
	TTF_Quit();
	SDL_Quit();
	SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "SDL quitted");
}

void SdlWindow::Create(const char* title, int width, int height)
{
	if (!SDL_InitSubSystem(SDL_INIT_VIDEO))
	{
		SDL_LogError(0, "Failed to init video subsystem. %s", SDL_GetError());
		return;
	}

	m_LastFrameCounter = SDL_GetPerformanceCounter();
	m_CountPerSecond = SDL_GetPerformanceFrequency();

	if (!TTF_Init())
	{
		SDL_LogError(0, "Failed to init ttf library. %s", SDL_GetError());
	}

	m_Window = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
	if (m_Window == NULL)
	{
		SDL_LogError(0, "Failed to create window. %s", SDL_GetError());
		return;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, 0);
	if (m_Renderer == NULL)
	{
		SDL_LogError(0, "Failed to create renderer. %s", SDL_GetError());
		return;
	}

	m_Engine = TTF_CreateRendererTextEngine(m_Renderer);
	if (m_Engine == NULL)
	{
		SDL_LogError(0, "Text Engine creation failed: %s", SDL_GetError());
	}
}

void SdlWindow::Quit()
{
	TTF_DestroyRendererTextEngine(m_Engine);
	m_Engine = nullptr;

	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;

	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
}

bool SdlWindow::IsOpen()
{
	return m_Window != nullptr;
}

float SdlWindow::Update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			Quit();
			break;
		}
	}

	auto beforeLastCounter = m_LastFrameCounter;
	m_LastFrameCounter = SDL_GetPerformanceCounter();
	float deltaTime = static_cast<float>(m_LastFrameCounter - beforeLastCounter) / m_CountPerSecond;
	return deltaTime;
}

void SdlWindow::BeginDraw()
{
}

void SdlWindow::EndDraw()
{
	SDL_RenderPresent(m_Renderer);
}

void SdlWindow::Clear(MyColor color)
{
	SDL_SetRenderDrawColor(m_Renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(m_Renderer);
}

void SdlWindow::Draw(Sprite& sprite)
{
	auto surface = sprite.GetTexture()->As<SDL_Surface>();
	SDL_Texture* texture = m_CachedTexture;
	if (surface != m_CachedSurface)
	{
		SDL_DestroyTexture(m_CachedTexture);
		texture = SDL_CreateTextureFromSurface(m_Renderer, surface);
		m_CachedSurface = surface;
		m_CachedTexture = texture;
	}

	MyColor color = sprite.GetTint();
	SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
	Rect spriteRect = sprite.GetRect();
	SDL_FRect destRect = {spriteRect.x, spriteRect.y, spriteRect.w, spriteRect.h};

	SDL_RenderTexture(m_Renderer, texture, NULL, &destRect);
}

void SdlWindow::Draw(Text& text, FontPtr& fontPtr)
{
	auto& string = text.GetText();

	TTF_Text* ttfText;
	if (string == m_CachedStrings[0])
	{
		ttfText = m_CachedTexts[0];
	}
	else if (string == m_CachedStrings[1])
	{
		ttfText = m_CachedTexts[1];
	}
	else
	{
		ttfText = m_CachedTexts[0];
		m_CachedTexts[0] = TTF_CreateText(m_Engine, fontPtr.As<TTF_Font>(), string.c_str(), 0);

		TTF_DestroyText(m_CachedTexts[1]);
		m_CachedTexts[1] = ttfText;
		ttfText = m_CachedTexts[0];
		if (ttfText == NULL)
		{
			SDL_LogError(0, "Create Text failed: %s", SDL_GetError());
		}

		m_CachedStrings[1] = m_CachedStrings[0];
		m_CachedStrings[0] = string;
	}

	Vec2 pos = text.GetPosition();
	MyColor color = text.GetColor();
	TTF_SetTextColor(ttfText, color.r, color.g, color.b, color.a);

	if (!TTF_DrawRendererText(ttfText, pos.x, pos.y))
	{
		SDL_LogError(0, "Draw text failed: %s", SDL_GetError());
	}
}

int SdlWindow::GetWidth()
{
	int w;
	SDL_GetWindowSize(m_Window, &w, NULL);
	return w;
}

int SdlWindow::GetHeight()
{
	int h;
	SDL_GetWindowSize(m_Window, NULL, &h);
	return h;
}
