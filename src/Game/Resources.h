#pragma once
#include "Utils/MyColor.h"
#include "Utils/Vec2.h"

namespace Resources
{
	static constexpr auto AppName = "Bouncer";
	static constexpr int WindowWidth = 1600;
	static constexpr int WindowHeight = 900;

	static constexpr auto SpriteTexPath = "res/Circle.png";
	static constexpr size_t StartingSpriteNumber = 10;
	static constexpr size_t MaxSpriteNumber = 50;
	static constexpr float MinSpriteSize = 50;
	static constexpr float MaxSpriteSize = 150;
	static constexpr float MinSpriteSpeed = 50;
	static constexpr float MaxSpriteSpeed = 150;
	
	static constexpr auto FontPath = "res/LeagueSpartan-Bold.otf";
	static constexpr auto FontSize = 15;

	static constexpr float MinIntervalBetweenSpawns = 0.2f;
	static constexpr float MaxIntervalBetweenSpawns = 1.f;
	static constexpr float TimeToReachMinInterval = 60.f;

	static constexpr MyColor BackgroundColor = {15, 15, 15};
	static constexpr MyColor OnScreenTextColor = {255, 255, 255, 200};
	static constexpr Vec2 FpsTextPosition = {10, 10};
	static constexpr Vec2 ScoreTextPosition = {10, 25};
	static constexpr float FpsUpdateInterval = 1.f;
}
