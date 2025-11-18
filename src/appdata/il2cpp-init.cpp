// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// IL2CPP application initializer

#include <pch.h>

#include "il2cpp-appdata.h"
#include "il2cpp-init.h"
#include "helpers.h"

// IL2CPP APIs
#define DO_API(r, n, p) r (*n) p
#include "il2cpp-api-functions.h"
#undef DO_API

// Application-specific functions
#define DO_APP_FUNC(a, r, n, p) r (*n) p
#define DO_APP_FUNC_METHODINFO(a, n) struct MethodInfo ** n
namespace app {
#include "il2cpp-functions.h"
}
#undef DO_APP_FUNC
#undef DO_APP_FUNC_METHODINFO

// TypeInfo pointers
#define DO_TYPEDEF(a, n) n ## __Class** n ## __TypeInfo
namespace app {
#include "il2cpp-types-ptr.h"
}
#undef DO_TYPEDEF

size_t ComputeChecksum(const std::string& filename)
{
	std::ifstream file(filename, std::ios::in | std::ios::binary);
	if (!file.is_open())
	{
		LOG_ERROR("Failed to open: %s", filename.c_str());
		return 0;
	}

	size_t sum = 0;
	size_t word = 0;
	while (file.read(reinterpret_cast<char*>(&word), sizeof(word))) {
		sum += word;
	}

	if (file.gcount()) {
		word &= (~0LLU >> ((sizeof(size_t) - file.gcount()) * 8));
		sum += word;
	}

	return sum;
}

bool IsStaticCheckSumValid()
{
	char filepath[MAX_PATH];
	if (!GetModuleFileName((HMODULE)il2cppi_get_base_address(), filepath, sizeof(filepath)))
		return false;

	auto checksum = ComputeChecksum(filepath);

	if (checksum != 0x84D4EAA704705E72)
	{
		LOG_WARNING("Seems like assembly checksum (0x%zX) don't match the expected version.", checksum);
		return false;
	}

	return true;
}

// IL2CPP application initializer
void init_il2cpp()
{
	if (!IsStaticCheckSumValid())
	{
		MessageBox(NULL, "Version mismatch.", "StellaSora-Tool", MB_OK | MB_SYSTEMMODAL);
		ExitProcess(0);
		return;
	}

	// Get base address of IL2CPP module
	uintptr_t baseAddress = il2cppi_get_base_address();

	using namespace app;

	// Define IL2CPP API function addresses
	#define DO_API(r, n, p) n = (r (*) p)(baseAddress + n ## _ptr)
	#include "il2cpp-api-functions.h"
	#undef DO_API

	// Define function addresses
	#define DO_APP_FUNC(a, r, n, p) n = (r (*) p)(baseAddress + a)
 	#define DO_APP_FUNC_METHODINFO(a, n) n = (struct MethodInfo **)(baseAddress + a)
	#include "il2cpp-functions.h"
	#undef DO_APP_FUNC
 	#undef DO_APP_FUNC_METHODINFO

	// Define TypeInfo variables
	#define DO_TYPEDEF(a, n) n ## __TypeInfo = (n ## __Class**) (baseAddress + a);
	#include "il2cpp-types-ptr.h"
	#undef DO_TYPEDEF
}