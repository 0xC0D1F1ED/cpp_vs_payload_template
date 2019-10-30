#pragma once
#include <Windows.h>

#include "../$ext_safeprojectname$Core/$ext_safeprojectname$Core.h"

#if defined(_DEBUG)
	#pragma comment (lib, "$ext_safeprojectname$Core_D.lib")
#else
	#pragma comment (lib, "$ext_safeprojectname$Core.lib")
#endif

int main(int argc, char *argv[])
{
	return runme();
}