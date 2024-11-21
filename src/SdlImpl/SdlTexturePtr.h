#pragma once
#include "Game/TexturePtr.h"

class SdlTexturePtr : public TexturePtr
{
public:

	void LoadFromFile(const char* path) override;
	void Unload() override;
};
