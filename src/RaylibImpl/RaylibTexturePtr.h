#pragma once
#include "Game/TexturePtr.h"
#include <raylib.h>

class RaylibTexturePtr : public TexturePtr
{
public:

	void LoadFromFile(const char* path) override;
	void Unload() override;

private:

	Texture m_Texture;
};
