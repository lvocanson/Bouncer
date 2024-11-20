#include "RaylibMouseInput.h"
#include <raylib.h>

bool RaylibMouseInput::GetMouseState(Vec2& outPosition)
{
	auto position = GetMousePosition();
	outPosition.x = position.x;
	outPosition.y = position.y;
	return IsMouseButtonDown(MOUSE_BUTTON_LEFT);
}
