#include "SdlLogger.h"
#include <SDL3/SDL.h>

void SdlLogger::Log(Category cat, const char* text)
{
	switch (cat)
	{
	case Logger::Info:
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, text);
		break;
	case Logger::Warn:
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, text);
		break;
	case Logger::Error:
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, text);
		break;
	case Logger::Debug:
		SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, text);
		break;
	default:
		SDL_Log(text);
		break;
	}
}
