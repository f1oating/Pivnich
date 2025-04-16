#pragma once

#ifdef PV_PLATFORM_WINDOWS
    #ifdef PV_BUILD_DLL
        #define PV_API __declspec(dllexport)
    #else
        #define PV_API __declspec(dllimport)
    #endif
#endif

