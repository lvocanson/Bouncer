#pragma once
#include "Utils/Vec2.h"

class IMouseInput
{
public:

	// Returns true if clicked
	virtual bool GetMouseState(Vec2& outPosition) = 0;
};
