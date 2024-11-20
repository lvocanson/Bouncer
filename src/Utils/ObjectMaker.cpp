#include "ObjectMaker.h"
#include "SdlImpl/SdlWindow.h"
#include "SdlImpl/SdlMouseInput.h"
#include "RaylibImpl/RaylibWindow.h"
#include "RaylibImpl/RaylibMouseInput.h"

ObjectMaker::ObjectMaker(Lib library)
	: m_Library(library)
{
}

IWindow* ObjectMaker::MakeWindow()
{
	switch (m_Library)
	{
	case SDL:
		return new SdlWindow();
	case raylib:
		return new RaylibWindow();
	}
	return nullptr;
}

IMouseInput* ObjectMaker::MakeMouseInput()
{
	switch (m_Library)
	{
	case SDL:
		return new SdlMouseInput();
	case raylib:
		return new RaylibMouseInput();
	}
	return nullptr;
}
