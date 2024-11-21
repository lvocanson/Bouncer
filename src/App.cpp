#include "App.h"
#include "Game/IWindow.h"
#include "Game/IMouseInput.h"
#include "Game/Logger.h"
#include "Game/TexturePtr.h"
#include "Utils/RandomHelper.h"
#include <format>

App::App(Lib libToUse)
	: m_Maker(libToUse)
{
	auto logger = m_Maker.MakeLogger();
	Logger::SetInstance(logger);
	logger->Log(Logger::Info, "Logger created");

	InitRand();
	logger->Log(Logger::Info, "Random initialized");

	m_Window = m_Maker.MakeWindow();
	m_Window->Create(Resources::AppName, Resources::WindowWidth, Resources::WindowHeight);
	logger->Log(Logger::Info, "Window created");

	m_Window->SetFont(Resources::FontPath, Resources::FontSize);
	logger->Log(Logger::Info, "Font loaded");

	m_Input = m_Maker.MakeMouseInput();
	logger->Log(Logger::Info, "Mouse input initialized");

	m_FpsText.SetText("FPS: 0");
	m_FpsText.SetPosition(Resources::FpsTextPosition);
	m_FpsText.SetColor(Resources::OnScreenTextColor);
	logger->Log(Logger::Info, "FPS text setup");

	m_ScoreText.SetText("Score: 0");
	m_ScoreText.SetPosition(Resources::ScoreTextPosition);
	m_ScoreText.SetColor(Resources::OnScreenTextColor);
	logger->Log(Logger::Info, "Score text setup");

	m_Texture = m_Window->CreateTexture();
	m_Texture->LoadFromFile(Resources::SpriteTexPath);
	logger->Log(Logger::Info, "Sprite texture loaded");

	for (size_t i = 0; i < m_Sprites.size(); i++)
	{
		auto& sprite = m_Sprites[i];
		sprite.SetTexture(m_Texture);
		RandomizeSprite(sprite);
		sprite.SetVisible(i < Resources::StartingSpriteNumber);
	}
	logger->Log(Logger::Info, "All sprites initialized");
}

App::~App()
{
	m_Texture->Unload();

	delete m_Window;
	m_Window = nullptr;

	delete m_Input;
	m_Input = nullptr;
}

int App::Run()
{
	while (m_Window->IsOpen())
	{
		TryToSpawnSprite();
		UpdateSprites();
		UpdateFpsText();

		m_Window->BeginDraw();
		m_Window->Clear(Resources::BackgroundColor);
		for (auto& sprite : m_Sprites)
		{
			if (sprite.IsVisible()) m_Window->Draw(sprite);
		}
		m_Window->Draw(m_FpsText);
		m_Window->Draw(m_ScoreText);
		m_Window->EndDraw();

		m_DeltaTime = m_Window->Update();
		m_ElapsedTime += m_DeltaTime;
		m_SpawnTimer += m_DeltaTime;
		m_FpsUpdatTimer += m_DeltaTime;
	}
	return 0;
}

void App::RandomizeSprite(Sprite& sprite)
{
	float size = Randf(Resources::MinSpriteSize, Resources::MaxSpriteSize);
	sprite.SetSize({size, size});

	float x = Randf(0, m_Window->GetWidth() - size);
	float y = Randf(0, m_Window->GetHeight() - size);
	sprite.SetPosition({x, y});

	float speed = Randf(Resources::MinSpriteSpeed, Resources::MaxSpriteSpeed);
	sprite.SetVelocity(RandUnitVec() * speed);

	sprite.SetTint(RandColor());
}

void App::TryToSpawnSprite()
{
	float spawnInterval = std::lerp(
		Resources::MaxIntervalBetweenSpawns,
		Resources::MinIntervalBetweenSpawns,
		m_ElapsedTime / Resources::TimeToReachMinInterval);

	while (m_SpawnTimer > spawnInterval)
	{
		m_SpawnTimer -= spawnInterval;

		for (auto& sprite : m_Sprites)
		{
			if (!sprite.IsVisible())
			{
				RandomizeSprite(sprite);
				sprite.SetVisible(true);
				return;
			}
		}
	}
}

void App::UpdateSprites()
{
	for (auto& sprite : m_Sprites)
	{
		if (!sprite.IsVisible())
		{
			continue;
		}

		sprite.ApplyVelocity(m_DeltaTime);
		Rect spriteRect = sprite.GetRect();
		Vec2 velocity = sprite.GetVelocity();

		{
			float cy = spriteRect.y + spriteRect.h / 2.f;
			float cx = spriteRect.x + spriteRect.w / 2.f;
			float a = spriteRect.w / 2.f;
			float b = spriteRect.h / 2.f;

			Vec2 mousePosition;
			if (m_Input->GetMouseState(mousePosition) && // Ellipsis hitbox
				((mousePosition.x - cx) * (mousePosition.x - cx)) / (a * a) + ((mousePosition.y - cy) * (mousePosition.y - cy)) / (b * b) <= 1.0f)
			{
				sprite.SetVisible(false);
				m_Score++;
				m_ScoreText.SetText(std::format("Score: {}", m_Score));
				continue;
			}
		}
		{

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
		}

		sprite.SetVelocity(velocity);
		sprite.SetPosition(spriteRect.position);
	}
}

void App::UpdateFpsText()
{
	if (m_FpsUpdatTimer > Resources::FpsUpdateInterval)
	{
		m_FpsText.SetText(std::format("FPS: {}", static_cast<int>(1 / m_DeltaTime)));
		m_FpsUpdatTimer -= Resources::FpsUpdateInterval;
	}
}
