#pragma once

#ifdef MW_PLATFORM_WINDOWS
	#ifdef MW_BUILD_DLL
		#define MWERT_API __declspec(dllexport)
	#else
		#define MWERT_API __declspec(dllimport)
	#endif
#else
	#error Mwert only supports Windows for now!
#endif
