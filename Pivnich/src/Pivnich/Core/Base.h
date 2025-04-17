#pragma once

#ifdef PV_PLATFORM_WINDOWS
    #ifdef PV_BUILD_DLL
        #define PV_API __declspec(dllexport)
    #else
        #define PV_API __declspec(dllimport)
    #endif
#endif

#ifdef PV_DEBUG
#define	PV_ENABLE_ASSERTS
#endif

#ifdef PV_ENABLE_ASSERTS
    #define PV_ASSERT(x, ...) { if(!(x)) { PV_LOG_APP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define PV_CORE_ASSERT(x, ...) { if(!(x)) { PV_LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define PV_ASSERT(x, ...)
    #define PV_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)