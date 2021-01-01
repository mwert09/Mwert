#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"


namespace Mwert
{
	class MWERT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


// Core Log macros
#define MW_CORE_TRACE(...)  ::Mwert::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MW_CORE_INFO(...)   ::Mwert::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MW_CORE_WARN(...)   ::Mwert::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MW_CORE_ERROR(...)  ::Mwert::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MW_CORE_FATAL(...)  ::Mwert::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define MW_TRACE(...)		::Mwert::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MW_INFO(...)		::Mwert::Log::GetClientLogger()->info(__VA_ARGS__)
#define MW_WARN(...)		::Mwert::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MW_ERROR(...)		::Mwert::Log::GetClientLogger()->error(__VA_ARGS__)
#define MW_FATAL(...)		::Mwert::Log::GetClientLogger()->fatal(__VA_ARGS__)

