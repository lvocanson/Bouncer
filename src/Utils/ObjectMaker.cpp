#include "ObjectMaker.h"
#include "SdlImpl/SdlWindow.h"
#include "RaylibImpl/RaylibWindow.h"

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
