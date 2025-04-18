#pragma once

#include <memory>

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

namespace PV {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}