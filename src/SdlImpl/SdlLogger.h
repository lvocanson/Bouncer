#pragma once
#include "Game/Logger.h"

class SdlLogger : public Logger
{
public:

	void Log(Category, const char* text) override;
};
