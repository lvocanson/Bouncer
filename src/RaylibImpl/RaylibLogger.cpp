#include "RaylibLogger.h"
#include <raylib.h>

void RaylibLogger::Log(Category cat, const char* text)
{
	TraceLogLevel lvl = LOG_NONE;
	switch (cat)
	{
	case Logger::Info:
		lvl = LOG_INFO;
		break;
	case Logger::Warn:
		lvl = LOG_WARNING;
		break;
	case Logger::Error:
		lvl = LOG_ERROR;
		break;
	case Logger::Debug:
		lvl = LOG_DEBUG;
		break;
	}
	TraceLog(lvl, text);
}
