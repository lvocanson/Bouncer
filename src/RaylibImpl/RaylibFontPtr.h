#pragma once
#include "Game/FontPtr.h"
#include <raylib.h>

class RaylibFontPtr : public FontPtr
{
public:

	void LoadFromFile(const char* path) override;
	void Unload() override;

private:

	Font m_Font;
};
