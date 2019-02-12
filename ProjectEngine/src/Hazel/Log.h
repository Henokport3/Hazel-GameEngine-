#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"


namespace Hazel {

	class HAZEL_API Log
	{
	public:
		// A static initializer
		static void Init();

		// A shared pointer for logging the status of the core
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

		// A shared pointer for logging the status of the client
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

/*----------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------LOG MACROS--------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------*/

// CORE log macros
#define HZ_CORE_FATAL(...)	::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)	// Define a core FATAL logger
#define HZ_CORE_ERROR(...)	::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)	// Define a core ERROR logger
#define HZ_CORE_WARN(...)	::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)	// Define a core WARNING logger
#define HZ_CORE_INFO(...)	::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)	// Define a core MESSAGE logger
#define HZ_CORE_TRACE(...)	::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)	// Define a core TRACE logger

// CLIENT log macros
#define HZ_FATAL(...)	::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)		// Define a client FATAL logger
#define HZ_ERROR(...)	::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)		// Define a client ERROR logger
#define HZ_WARN(...)	::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)		// Define a client WARNING logger
#define HZ_INFO(...)	::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)		// Define a client MESSAGE logger
#define HZ_TRACE(...)	::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)		// Define a client TRACE logger

/*----------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------LOG MACROS--------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------------------------*/
