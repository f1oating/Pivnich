#pragma once

#include "Base.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace PV {

    class Log
    {
    public:
        static PV_API void Init();

        static PV_API std::shared_ptr<spdlog::logger>& GetCoreLogger();
        static PV_API std::shared_ptr<spdlog::logger>& GetClientLogger();

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

}

// ---------------------------- Core Logger Macros ------------------------------ //
#define PV_CORE_ERROR(...)		::PV::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PV_CORE_WARN(...)		::PV::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PV_CORE_INFO(...)		::PV::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PV_CORE_TRACE(...)		::PV::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PV_CORE_FATAL(...)		::PV::Log::GetCoreLogger()->fatal(__VA_ARGS__)
// ------------------------------------------------------------------------------ //

// ---------------------------- Client Logger Macros ---------------------------- //
#define PV_ERROR(...)			::PV::Log::GetClientLogger()->error(__VA_ARGS__)
#define PV_WARN(...)			::PV::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PV_INFO(...)			::PV::Log::GetClientLogger()->info(__VA_ARGS__)
#define PV_TRACE(...)			::PV::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PV_FATAL(...)			::PV::Log::GetClientLogger()->fatal(__VA_ARGS__)
// ------------------------------------------------------------------------------ //