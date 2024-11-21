#pragma once
#include "Game/FontPtr.h"

class SdlFontPtr : public FontPtr
{
public:

	void LoadFromFile(const char* path) override;
	void Unload() override;
	void SetSize(float size) override;
};
