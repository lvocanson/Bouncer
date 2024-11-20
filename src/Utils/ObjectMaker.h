#pragma once
#include "LibraryPicker.h"

class IWindow;
class IMouseInput;

// Only class that has the responsability to choose between implementations
class ObjectMaker
{
public:

	ObjectMaker(Lib library);

	IWindow* MakeWindow();
	IMouseInput* MakeMouseInput();

private:

	const Lib m_Library;
};
