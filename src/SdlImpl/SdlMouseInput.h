#pragma once
#include "Game/IMouseInput.h"

class SdlMouseInput : public IMouseInput
{
public:

	bool GetMouseState(Vec2& outPosition) override;
};
