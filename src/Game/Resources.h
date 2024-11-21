#pragma once
#include "Utils/MyColor.h"
#include "Utils/Vec2.h"

namespace Resources
{
	static constexpr auto AppName = "Bouncer";
	static constexpr int WindowWidth = 1600;
	static constexpr int WindowHeight = 900;

	static_assert(WindowWidth > 0, "WindowWidth must be positive");
	static_assert(WindowHeight > 0, "WindowHeight must be positive");

	static constexpr auto SpriteTexPath = "res/Circle.png";
	static constexpr size_t StartingSpriteNumber = 10;
	static constexpr size_t MaxSpriteNumber = 50;

	static_assert(StartingSpriteNumber > 0, "StartingSpriteNumber must be positive");
	static_assert(MaxSpriteNumber > StartingSpriteNumber, "MaxSpriteNumber must be greater than StartingSpriteNumber");

	static constexpr float MinSpriteSize = 50;
	static constexpr float MaxSpriteSize = 150;

	static_assert(MinSpriteSize > 0, "MinSpriteSize must be positive");
	static_assert(MaxSpriteSize > MinSpriteSize, "MaxSpriteSize must be greater than MinSpriteSize");

	static constexpr float MinSpriteSpeed = 50;
	static constexpr float MaxSpriteSpeed = 150;

	static_assert(MinSpriteSpeed > 0, "MinSpriteSpeed must be positive");
	static_assert(MaxSpriteSpeed > MinSpriteSpeed, "MaxSpriteSpeed must be greater than MinSpriteSpeed");

	static constexpr auto FontPath = "res/LeagueSpartan-Bold.otf";
	static constexpr auto FontSize = 15;

	static_assert(FontSize > 0, "FontSize must be positive");

	static constexpr float MinIntervalBetweenSpawns = 0.2f;
	static constexpr float MaxIntervalBetweenSpawns = 1.f;
	static constexpr float TimeToReachMinInterval = 60.f;

	static_assert(MinIntervalBetweenSpawns < MaxIntervalBetweenSpawns, "MinIntervalBetweenSpawns must be less than MaxIntervalBetweenSpawns");
	static_assert(MinIntervalBetweenSpawns > 0.f, "MinIntervalBetweenSpawns must be positive");
	static_assert(TimeToReachMinInterval > 0.f, "TimeToReachMinInterval must be positive");

	static constexpr MyColor BackgroundColor = {15, 15, 15};
	static constexpr MyColor OnScreenTextColor = {255, 255, 255, 200};

	static constexpr Vec2 FpsTextPosition = {10, 10};
	static constexpr Vec2 ScoreTextPosition = {10, 25};

	static constexpr float FpsUpdateInterval = 1.f;

	static_assert(FpsUpdateInterval > 0.f, "FpsUpdateInterval must be positive");
}
