#pragma once
#include "LibraryPicker.h"

class IWindow;
class IMouseInput;
class Logger;
class FontPtr;
class TexturePtr;

// Only class that has the responsability to choose between implementations
class ObjectMaker
{
public:

	ObjectMaker(Lib library);

	IWindow* MakeWindow();
	IMouseInput* MakeMouseInput();
	Logger* MakeLogger();
	FontPtr* MakeFontPtr();
	TexturePtr* MakeTexturePtr();

private:

	const Lib m_Library;
};
