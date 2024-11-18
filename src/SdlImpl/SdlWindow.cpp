#include "SdlWindow.h"
#include "SdlSprite.h"
#include <SDL3/SDL.h>

void SdlWindow::Initialize()
{
	if (!SDL_InitSubSystem(SDL_INIT_VIDEO))
	{
		SDL_LogError(0, "Failed to init video subsystem. %s", SDL_GetError());
		return;
	}
}

void SdlWindow::Create(const char* title, int width, int height)
{
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
}

bool SdlWindow::IsOpen()
{
	return m_Window != nullptr;
}

void SdlWindow::Update()
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
}

void SdlWindow::BeginDraw()
{
}

void SdlWindow::EndDraw()
{
	SDL_RenderPresent(m_Renderer);
}

void SdlWindow::Clear(unsigned char r, unsigned char g, unsigned char b)
{
	SDL_SetRenderDrawColor(m_Renderer, r, g, b, ~0);
	SDL_RenderClear(m_Renderer);
}

ISprite* SdlWindow::CreateSprite()
{
	return new SdlSprite(m_Renderer);
}

void SdlWindow::Draw(ISprite& sprite)
{
	auto& sdlSprite = (SdlSprite&)sprite;
	SDL_RenderTexture(m_Renderer, sdlSprite.GetTexture(), NULL, sdlSprite.GetRect());
}

void SdlWindow::Quit()
{
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;

	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;

	SDL_Quit();
}
