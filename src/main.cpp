#include "LibraryPicker.h"
#include "App.h"

int main(int argc, char** argv)
{
	Lib libToUse = GetLibraryToUse(argc, argv);
	App app(libToUse);
	return app.Run();
}
