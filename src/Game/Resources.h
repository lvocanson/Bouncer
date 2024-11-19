#pragma once
#include "Utils/MyColor.h"
#include "Utils/Vec2.h"

namespace Resources
{
	static constexpr auto AppName = "Bouncer";
	static constexpr int WindowWidth = 1600;
	static constexpr int WindowHeight = 900;

	static constexpr auto SpriteTexPath = "res/Circle.png";
	static constexpr int SpriteNumber = 10;
	static constexpr float MinSpriteSize = 50;
	static constexpr float MaxSpriteSize = 150;
	static constexpr float MinSpriteSpeed = 50;
	static constexpr float MaxSpriteSpeed = 150;
	
	static constexpr auto FontPath = "res/Holen Vintage.otf";
	static constexpr auto FontSize = 12;

	static constexpr MyColor BackgroundColor = {15, 15, 15};
	static constexpr MyColor FpsTextColor = {255, 255, 255, 127};
	static constexpr Vec2 FpsTextPosition = {10, 10};
}
