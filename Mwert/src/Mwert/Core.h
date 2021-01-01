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

#ifdef MW_ENABLE_ASSERTS
	#define MW_ASSERT(x, ...) {if(!(x)) {MW_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define MW_CORE_ASSERT(x, ...) {if(!(x)) {MW_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define MW_ASSERT(x, ...)
	#define MW_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)