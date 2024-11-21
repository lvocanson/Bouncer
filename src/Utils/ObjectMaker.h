#pragma once
#include "LibraryPicker.h"

class IWindow;
class IMouseInput;
class Logger;
class FontPtr;

// Only class that has the responsability to choose between implementations
class ObjectMaker
{
public:

	ObjectMaker(Lib library);

	IWindow* MakeWindow();
	IMouseInput* MakeMouseInput();
	Logger* MakeLogger();
	FontPtr* MakeFontPtr();

private:

	const Lib m_Library;
};
