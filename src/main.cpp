#include "cheat.h"

// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN

// Windows Header Files
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	UNREFERENCED_PARAMETER(hModule);
	UNREFERENCED_PARAMETER(lpReserved);

	switch (dwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			InitializeCheat(GetModuleHandleA("GameAssembly.dll"));
			return TRUE;
		}
		case DLL_THREAD_ATTACH:
			return TRUE;
		case DLL_THREAD_DETACH:
			return TRUE;
		case DLL_PROCESS_DETACH:
			ReleaseCheat();
			return TRUE;
		default:
			return FALSE;
	}
}

