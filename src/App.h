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

private:

	ObjectMaker m_Maker;
	IWindow* m_Window;
	std::vector<ISprite*> m_Sprites;
};
