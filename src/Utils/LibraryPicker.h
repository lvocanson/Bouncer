#pragma once

enum Lib : char
{
	SDL,
	raylib
};

Lib GetLibraryToUse(int argc, char** argv);
