#pragma once
#include "ObjectMaker.h"
#include <vector>

class IWindow;
class ISprite;

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
	std::vector<ISprite*> m_Sprites;
};
