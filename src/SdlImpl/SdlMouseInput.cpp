#include "SdlMouseInput.h"
#include <SDL3/SDL.h>

bool SdlMouseInput::GetMouseState(Vec2& outPosition)
{
	return SDL_GetMouseState(&outPosition.x, &outPosition.y) & SDL_BUTTON_MASK(SDL_BUTTON_LEFT);
}
