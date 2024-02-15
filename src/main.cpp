#include "GameAssembly.h"
#include "cheat.h"

#include <filesystem>
#include <vector>

// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN

// Windows Header Files
#include <windows.h>
#include <tchar.h>

// ==========================================================================================
static std::filesystem::path GetModuleFilePath(HMODULE hModule)
{
	std::vector<TCHAR> buffer;
	DWORD len = 0;
	do
	{
		buffer.resize(buffer.capacity() + MAX_PATH);
		len = GetModuleFileName(hModule, buffer.data(), buffer.capacity());
	} while (len >= buffer.capacity());
	return std::filesystem::path {buffer.data(), buffer.data() + len};
}

// ==========================================================================================
BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	UNREFERENCED_PARAMETER(lpReserved);

	static bool Initialized = false;

	switch (dwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			HMODULE gameAssemblyBaseAddress = GetModuleHandle(_T("GameAssembly.dll"));
			if (gameAssemblyBaseAddress == NULL)
			{
				fprintf(stderr, "[Error] Failed to retrieve GameAssembly handle.");
				return FALSE;
			}
			GameAssembly.Initialize(gameAssemblyBaseAddress);

			TLDCheat::Initialize();
			Initialized = true;

			return TRUE;
		}
		case DLL_THREAD_ATTACH:
			return TRUE;
		case DLL_THREAD_DETACH:
			return TRUE;
		case DLL_PROCESS_DETACH:
			if (Initialized)
			{
				TLDCheat::Release();
			}
			return TRUE;
		default:
			return FALSE;
	}
}
