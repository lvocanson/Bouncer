#include "ObjectMaker.h"
#include "SdlImpl/SdlWindow.h"
#include "SdlImpl/SdlSprite.h"
#include "RaylibImpl/RaylibWindow.h"
#include "RaylibImpl/RaylibSprite.h"
#include <cassert>

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

ISprite* ObjectMaker::MakeSprite(IWindow* owner)
{
	switch (m_Library)
	{
	case SDL:
	{
		auto win = dynamic_cast<SdlWindow*>(owner);
		assert(win);
		return new SdlSprite(win->GetRenderer());
	}
	case raylib:
		return new RaylibSprite();
	}
	return nullptr;
}
