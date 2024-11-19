#pragma once
#include "Vec2.h"
#include "MyColor.h"
#include <cstdlib>
#include <ctime>
#include <cassert>

static constexpr float PI = 3.14159265358979323846f;

inline void InitRand()
{
	srand(static_cast<unsigned int>(time(nullptr)));
}

// random in range [a, b)
inline int Rand(int a, int b)
{
	if (b == a) return a;
	if (b < a) std::swap(a, b);
	return rand() % (b - a) + a;
}

// random in range [a, b]
inline float Randf(float a, float b)
{
	if (b == a) return a;
	if (b < a) std::swap(a, b);
	return static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (b - a))) + a;
}

inline unsigned char RandByte()
{
	return static_cast<unsigned char>(rand() % 256);
}

inline bool CoinFlip()
{
	return static_cast<bool>(rand() % 2);
}

inline Vec2 RandUnitVec()
{
	float directionAngle = Randf(0, 2 * PI);
	return {cosf(directionAngle), sinf(directionAngle)};
}

inline MyColor RandColor()
{
	return {RandByte(), RandByte(), RandByte()};
}
