#pragma once
#include "Game/Logger.h"

class RaylibLogger : public Logger
{
public:

	void Log(Category, const char* text) override;
};
