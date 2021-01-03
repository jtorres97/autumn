#include "Logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Autumn
{
	std::shared_ptr<spdlog::logger> Logger::s_engineLogger;
	std::shared_ptr<spdlog::logger> Logger::s_clientLogger;


	void Logger::Initialize(const std::string& name)
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_engineLogger = spdlog::stdout_color_mt("AUTUMN");
		s_clientLogger = spdlog::stdout_color_mt(name);

		s_engineLogger->set_level(spdlog::level::trace);
		s_clientLogger->set_level(spdlog::level::trace);
	}
}
