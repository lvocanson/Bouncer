#pragma once
#include "Utils/ObjectMaker.h"
#include "Game/Resources.h"
#include "Game/Text.h"
#include <array>

class IWindow;
class Sprite;
class IMouseInput;

class App
{
public:

	App(Lib libToUse);
	~App();
	int Run();

private:

	void RandomizeSprite(Sprite*);
	void TryToSpawnSprite();
	void UpdateSprites();
	void UpdateFpsText();

private:
	ObjectMaker m_Maker;
	IWindow* m_Window;
	IMouseInput* m_Input;
	Text m_FpsText;
	std::array<Sprite*, Resources::MaxSpriteNumber> m_Sprites;

	float m_ElapsedTime = 0;
	float m_DeltaTime = 0;
	float m_SpawnTimer = 0;
	float m_FpsUpdatTimer = 0;
};
