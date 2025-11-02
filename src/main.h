#pragma once
#include "framework.h"
#include <list>

namespace global {
	namespace process {
		inline DWORD pId;
		inline HANDLE handle;
		inline WNDPROC hwnd;
		inline HMODULE hModule;
		inline WNDPROC WndProc;
		inline int WindowWidth;
		inline int WindowHeight;
		inline LPCSTR Title;
		inline LPCSTR ClassName;
		inline LPCSTR Path;
	}

	inline std::list<void(*)()> AdventureModuleController_Update;
}

void Run(HMODULE* phModule);