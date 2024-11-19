#pragma once
#include "Utils/ObjectMaker.h"
#include <vector>

class IWindow;
class Sprite;

class App
{
public:

	App(Lib libToUse);
	int Run();
	void CreateSprite();
	void UpdatePosition(float dt);

private:
	ObjectMaker m_Maker;
	IWindow* m_Window;
	std::vector<Sprite*> m_Sprites;
};
