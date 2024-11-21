#pragma once
#include "Utils/ObjectMaker.h"
#include "Game/Resources.h"
#include "Game/Sprite.h"
#include "Game/Text.h"
#include <array>

class IWindow;
class IMouseInput;
class TexturePtr;
class FontPtr;

class App
{
public:

	App(Lib libToUse);
	~App();
	int Run();

private:

	void RandomizeSprite(Sprite&);
	void TryToSpawnSprite();
	void UpdateSprites();
	void UpdateFpsText();

private:
	ObjectMaker m_Maker;
	IWindow* m_Window;
	IMouseInput* m_Input;
	
	FontPtr* m_Font;
	Text m_FpsText;
	Text m_ScoreText;

	TexturePtr* m_Texture;
	std::array<Sprite, Resources::MaxSpriteNumber> m_Sprites;

	float m_ElapsedTime = 0;
	float m_DeltaTime = 0;
	float m_LastSpriteSpawn = 0;
	float m_LastFpsUpdate = 0;
	unsigned int m_FrameCounter = 0;
	unsigned int m_Score = 0;
};
