#pragma once
#include <cstdint>

union MyColor
{
	constexpr MyColor(uint8_t r, uint8_t g, uint8_t b)
		: r(r), g(g), b(b), a(255)
	{
	}

	constexpr MyColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
		: r(r), g(g), b(b), a(a)
	{
	}

	constexpr MyColor(uint32_t color)
		: fullColor(color)
	{
	}

	struct
	{
		uint8_t r, g, b, a;
	};

	uint32_t fullColor;
};