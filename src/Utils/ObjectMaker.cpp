#include "ObjectMaker.h"
#include "SdlImpl/SdlWindow.h"
#include "SdlImpl/SdlMouseInput.h"
#include "SdlImpl/SdlLogger.h"
#include "SdlImpl/SdlFontPtr.h"
#include "RaylibImpl/RaylibWindow.h"
#include "RaylibImpl/RaylibMouseInput.h"
#include "RaylibImpl/RaylibLogger.h"
#include "RaylibImpl/RaylibFontPtr.h"

ObjectMaker::ObjectMaker(Lib library)
	: m_Library(library)
{
}

#define SWITCH_ON(object) \
switch (m_Library) \
{ \
case SDL: \
	return new Sdl##object(); \
case raylib: \
	return new Raylib##object(); \
default: \
	return nullptr; \
} 


IWindow* ObjectMaker::MakeWindow()
{
	SWITCH_ON(Window);
}

IMouseInput* ObjectMaker::MakeMouseInput()
{
	SWITCH_ON(MouseInput);
}

Logger* ObjectMaker::MakeLogger()
{
	SWITCH_ON(Logger);
}

FontPtr* ObjectMaker::MakeFontPtr()
{
	SWITCH_ON(FontPtr);
}
