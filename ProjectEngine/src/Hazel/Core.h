#pragma once

// Unlike functions which gets called, MACROS can be disable all logs from distribution builds and does not get included in the binary.

// Macros for importing/exporting dynamic libraries (DLL) from symbols
#ifdef HZ_PLATFORM_WINDOWS							// If running on Windows...
	#ifdef  HZ_BUILD_DLL							// If building a DLL file...
		#define HAZEL_API _declspec(dllexport)		// Export symbol
	#else											// Otherwise...
		#define HAZEL_API _declspec(dllimport)		// Import symbol
	#endif //  HZ_BUILD_DLL
#else												// If NOT running on Windows... (then ERROR!)
	#error The engine only supports Windows!

#endif // HZ_PLATFORM_WINDOWS