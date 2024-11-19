#pragma once
#include "Vec2.h"

union Rect
{
	constexpr Rect(float x, float y, float w, float h)
		: x(x), y(y), w(w), h(h)
	{
	}

	constexpr Rect(Vec2 position, Vec2 size)
		: position(position), size(size)
	{
	}

	struct
	{
		float x, y, w, h;
	};

	struct
	{
		Vec2 position, size;
	};

	float Left() const { return x; }
	float Top() const { return y; }
	float Right() const { return x + w; }
	float Bottom() const { return y + h; }
};
