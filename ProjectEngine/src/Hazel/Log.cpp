#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hazel
{
	// Declares core/client loggers as shared pointers
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// Logs pattern (https://github.com/gabime/spdlog/wiki/3.-Custom-formatting#pattern-flags for info on pattern flags)
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// Core logger
		s_CoreLogger = spdlog::stdout_color_mt("HAZEL");	// Logs and prints from core
		s_CoreLogger->set_level(spdlog::level::trace);		// Level set to trace (print all)

		// Client logger
		s_ClientLogger = spdlog::stdout_color_mt("APP");	// Logs and prints from client
		s_ClientLogger->set_level(spdlog::level::trace);	// Level set to trace (print all)
	}
}