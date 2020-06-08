// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN

// Windows Header Files
#include <windows.h>
#include "cheat.h"

BOOL APIENTRY DllMain(HMODULE /*hModule*/, DWORD ul_reason_for_call, LPVOID /*lpReserved*/)
{
	HMODULE gameModule = GetModuleHandleA("GameAssembly.dll");

	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			[[fallthrough]];
		case DLL_THREAD_ATTACH:
			Game::Cheat::Initialize(gameModule);
			return TRUE;
		case DLL_THREAD_DETACH:
			break;
		case DLL_PROCESS_DETACH:
			Game::Cheat::Release();
			return TRUE;
	}

	return FALSE;
}

