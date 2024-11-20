#pragma once
#include "Game/IMouseInput.h"

class RaylibMouseInput : public IMouseInput
{
public:

	bool GetMouseState(Vec2& outPosition) override;
};
