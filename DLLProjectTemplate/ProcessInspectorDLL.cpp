#pragma once
#include <Windows.h>

#include "../$ext_safeprojectname$Core/$ext_safeprojectname$Core.h"

#if defined(_DEBUG)
	#pragma comment (lib, "$ext_safeprojectname$Core_D.lib")
#else
	#pragma comment (lib, "$ext_safeprojectname$Core.lib")
#endif

// Holds the global variables for our thread
HANDLE hTBThread;
DWORD threadID;

// Function executed when the thread starts
DWORD WINAPI Start$ext_safeprojectname$(LPVOID lpParam) {
	return runme();
}

// Executed when the DLL is loaded (traditionally or through reflective injection)
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {

	if (ul_reason_for_call != DLL_PROCESS_ATTACH)
		return TRUE;

	DisableThreadLibraryCalls(hModule);
	hTBThread = CreateThread(NULL, 0, Start$ext_safeprojectname$, NULL, 0, &threadID);

	return TRUE;
}

// This is so the DLL can be started with rundll and will still function properly
// It will wait for the thread to finish
extern "C" __declspec(dllexport) BOOL Load(LPVOID lpUserdata, DWORD nUserdataLen) {
	if (hTBThread) {
		WaitForSingleObject(hTBThread, INFINITE);
	}

	return TRUE;
};
