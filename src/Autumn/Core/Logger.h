#pragma once

#include <spdlog/spdlog.h>

#include <memory>

namespace Autumn
{
	class Logger
	{
	public:
		static void Initialize(const std::string& name);

		[[nodiscard]] static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_engineLogger; }
		[[nodiscard]] static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_clientLogger; }
		
	private:
		static std::shared_ptr<spdlog::logger> s_engineLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};
}

#define AUTUMN_ENGINE_TRACE(...)   ::Autumn::Logger::GetEngineLogger()->trace(__VA_ARGS__)
#define AUTUMN_ENGINE_INFO(...)    ::Autumn::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define AUTUMN_ENGINE_WARN(...)    ::Autumn::Logger::GetEngineLogger()->warn(__VA_ARGS__)
#define AUTUMN_ENGINE_ERROR(...)   ::Autumn::Logger::GetEngineLogger()->error(__VA_ARGS__)
#define AUTUMN_ENGINE_FATAL(...)   ::Autumn::Logger::GetEngineLogger()->critical(__VA_ARGS__)

#define AUTUMN_TRACE(...)          ::Autumn::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define AUTUMN_INFO(...)           ::Autumn::Logger::GetClientLogger()->info(__VA_ARGS__)
#define AUTUMN_WARN(...)           ::Autumn::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define AUTUMN_ERROR(...)          ::Autumn::Logger::GetClientLogger()->error(__VA_ARGS__)
#define AUTUMN_FATAL(...)          ::Autumn::Logger::GetClientLogger()->critical(__VA_ARGS__)