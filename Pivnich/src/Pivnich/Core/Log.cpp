#include "pvpch.h"

#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace PV {

    Ref<spdlog::logger> Log::s_CoreLogger;
    Ref<spdlog::logger> Log::s_AppLogger;

    void Log::Init()
    {
        spdlog::set_pattern("[%H:%M:%S %z] [%^%n%$]: %v");
        
        s_CoreLogger = spdlog::stdout_color_mt("Core");
        s_CoreLogger->set_level(spdlog::level::trace);
        s_AppLogger = spdlog::stdout_color_mt("App");
        s_AppLogger->set_level(spdlog::level::trace);
    }

    Ref<spdlog::logger> Log::GetCoreLogger() { return s_CoreLogger; }
    Ref<spdlog::logger> Log::GetAppLogger() { return s_AppLogger; }

}