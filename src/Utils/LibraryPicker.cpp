#include "LibraryPicker.h"
#include <cstring>

/*
* Default Library to use
*/

#if ( \
	defined(USE_SDL) +\
	defined(USE_RAYLIB) \
) != 1
#error Exactly one library must be defined. Define `USE_SDL` or `USE_RAYLIB`.
#endif

#if defined(USE_SDL)
static constexpr Lib DefaultLib = SDL;
#elif defined(USE_RAYLIB)
static constexpr Lib DefaultLib = raylib;
#endif

/*
* Parse command line arguments
*/

static constexpr char UseSdlArg[] = "--SDL";
static constexpr char UseRaylibArg[] = "--raylib";

Lib GetLibraryToUse(int argc, char** argv)
{
	Lib libToUse = DefaultLib;

#ifndef FORCE_LIB

	for (int i = 0; i < argc; ++i)
	{
		if (strcmp(argv[i], UseSdlArg) == 0)
		{
			libToUse = SDL;
		}
		else if (strcmp(argv[i], UseRaylibArg) == 0)
		{
			libToUse = raylib;
		}
	}

#endif 

	return libToUse;
}
