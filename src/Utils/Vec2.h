#pragma once

struct Vec2
{
	float x, y;

	Vec2 operator+(Vec2 lhs)
	{
		return {x + lhs.x, y + lhs.y};
	}

	Vec2 operator+=(Vec2 lhs)
	{
		return {x += lhs.x, y += lhs.y};
	}

	Vec2 operator-(Vec2 lhs)
	{
		return {x - lhs.x, y - lhs.y};
	}

	Vec2 operator-=(Vec2 lhs)
	{
		return {x -= lhs.x, y -= lhs.y};
	}

	Vec2 operator*(float factor)
	{
		return {x * factor, y * factor};
	}

	Vec2 operator*=(float factor)
	{
		return {x *= factor, y *= factor};
	}
};
