#include "App.h"
#include "Game/IWindow.h"
#include "Game/IMouseInput.h"
#include "Game/Sprite.h"
#include "Utils/RandomHelper.h"
#include <format>

App::App(Lib libToUse)
	: m_Maker(libToUse)
{
	InitRand();

	m_Window = m_Maker.MakeWindow();
	m_Window->Create(Resources::AppName, Resources::WindowWidth, Resources::WindowHeight);
	m_Window->SetFont(Resources::FontPath, Resources::FontSize);

	m_Input = m_Maker.MakeMouseInput();

	m_FpsText.SetText("FPS: 0");
	m_FpsText.SetPosition(Resources::FpsTextPosition);
	m_FpsText.SetColor(Resources::OnScreenTextColor);

	m_ScoreText.SetText("Score: 0");
	m_ScoreText.SetPosition(Resources::ScoreTextPosition);
	m_ScoreText.SetColor(Resources::OnScreenTextColor);

	m_Sprites.fill(nullptr);
	for (size_t i = 0; i < Resources::StartingSpriteNumber; i++)
	{
		auto sprite = m_Window->CreateSprite();
		sprite->LoadImage(Resources::SpriteTexPath);
		RandomizeSprite(sprite);
		m_Sprites[i] = sprite;
	}
}

App::~App()
{
	for (auto sprite : m_Sprites)
	{
		delete sprite;
	}
	m_Sprites.fill(nullptr);

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
		for (auto sprite : m_Sprites)
		{
			if (sprite && sprite->IsVisible()) m_Window->Draw(*sprite);
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

void App::RandomizeSprite(Sprite* sprite)
{
	float size = Randf(Resources::MinSpriteSize, Resources::MaxSpriteSize);
	sprite->SetSize({size, size});

	float x = Randf(0, m_Window->GetWidth() - size);
	float y = Randf(0, m_Window->GetHeight() - size);
	sprite->SetPosition({x, y});

	float speed = Randf(Resources::MinSpriteSpeed, Resources::MaxSpriteSpeed);
	sprite->SetVelocity(RandUnitVec() * speed);

	sprite->SetTint(RandColor());
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

		for (size_t i = 0; i < m_Sprites.size(); i++)
		{
			auto sprite = m_Sprites[i];
			if (!sprite)
			{
				// All sprites enabled but there is place for new
				sprite = m_Window->CreateSprite();
				sprite->LoadImage(Resources::SpriteTexPath);
				RandomizeSprite(sprite);
				m_Sprites[i] = sprite;
				return;
			}

			if (!sprite->IsVisible())
			{
				// Found a disabled sprite
				RandomizeSprite(sprite);
				sprite->SetVisible(true);
				return;
			}
		}
	}
}

void App::UpdateSprites()
{
	for (auto sprite : m_Sprites)
	{
		if (!sprite || !sprite->IsVisible())
		{
			continue;
		}

		sprite->ApplyVelocity(m_DeltaTime);
		Rect spriteRect = sprite->GetRect();
		Vec2 velocity = sprite->GetVelocity();

		{

			float cy = spriteRect.y + spriteRect.h / 2.f;
			float cx = spriteRect.x + spriteRect.w / 2.f;
			float a = spriteRect.w / 2.f;
			float b = spriteRect.h / 2.f;

			Vec2 mousePosition;
			if (m_Input->GetMouseState(mousePosition) && // Ellipsis hitbox
				((mousePosition.x - cx) * (mousePosition.x - cx)) / (a * a) + ((mousePosition.y - cy) * (mousePosition.y - cy)) / (b * b) <= 1.0f)
			{
				sprite->SetVisible(false);
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

		sprite->SetVelocity(velocity);
		sprite->SetPosition(spriteRect.position);
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
