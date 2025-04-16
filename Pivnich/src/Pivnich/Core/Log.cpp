#include "pvpch.h"

#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace PV {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("Hazel");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger>& PV::Log::GetCoreLogger() { return s_CoreLogger; }
	std::shared_ptr<spdlog::logger>& PV::Log::GetClientLogger() { return s_ClientLogger; }

}