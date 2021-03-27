#pragma once

#ifdef UTOPIA_PLATFORM_WINDOWS
	#if UTOPIA_BUILD_DLL
		#define UTOPIA_API _declspec(dllexport)
	#else
		#define UTOPIA_API _declspec(dllimport)
	#endif
#else
	#error UtopiaEngine only build on Windows currently!

#endif // UTOPIA_PLATFORM_WINDOWS
