#include "ObjectMaker.h"
#include "SdlImpl/SdlWindow.h"
#include "SdlImpl/SdlMouseInput.h"
#include "SdlImpl/SdlLogger.h"
#include "RaylibImpl/RaylibWindow.h"
#include "RaylibImpl/RaylibMouseInput.h"
#include "RaylibImpl/RaylibLogger.h"

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

Logger* ObjectMaker::MakeLogger()
{
	switch (m_Library)
	{
	case SDL:
		return new SdlLogger();
	case raylib:
		return new RaylibLogger();
	}
	return nullptr;
}
