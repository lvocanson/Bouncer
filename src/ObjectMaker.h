#pragma once
#include "LibraryPicker.h"

class ISprite;
class IWindow;

// Only class that has the responsability to choose between implementations
class ObjectMaker
{
public:

	ObjectMaker(Lib library);

	IWindow* MakeWindow();

private:

	const Lib m_Library;
};
