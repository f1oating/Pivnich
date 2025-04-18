#pragma once

#include "Base.h"

#include <spdlog/spdlog.h>

namespace PV {

    class Log
    {
    public:
        static PV_API void Init();

        static PV_API Ref<spdlog::logger> GetCoreLogger();
        static PV_API Ref<spdlog::logger> GetAppLogger();

    private:
        static Ref<spdlog::logger> s_CoreLogger;
        static Ref<spdlog::logger> s_AppLogger;

    };

}

// ---------------------------- Core Logger Macros ------------------------------ //
#define PV_LOG_CORE_CRITICAL(...)    PV::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define PV_LOG_CORE_ERROR(...)       PV::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PV_LOG_CORE_WARN(...)        PV::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PV_LOG_CORE_INFO(...)        PV::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PV_LOG_CORE_DEBUG(...)       PV::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define PV_LOG_CORE_TRACE(...)       PV::Log::GetCoreLogger()->trace(__VA_ARGS__)
// ------------------------------------------------------------------------------ //

// ---------------------------- App Logger Macros ------------------------------- //
#define PV_LOG_APP_CRITICAL(...)     PV::Log::GetAppLogger()->critical(__VA_ARGS__)
#define PV_LOG_APP_ERROR(...)        PV::Log::GetAppLogger()->error(__VA_ARGS__)
#define PV_LOG_APP_WARN(...)         PV::Log::GetAppLogger()->warn(__VA_ARGS__)
#define PV_LOG_APP_INFO(...)         PV::Log::GetAppLogger()->info(__VA_ARGS__)
#define PV_LOG_APP_DEBUG(...)        PV::Log::GetAppLogger()->debug(__VA_ARGS__)
#define PV_LOG_APP_TRACE(...)        PV::Log::GetAppLogger()->trace(__VA_ARGS__)
// ------------------------------------------------------------------------------ //