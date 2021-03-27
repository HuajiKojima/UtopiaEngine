#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>
#include <memory>

namespace Utopia 
{
	class UTOPIA_API ConsoleLog
	{
	public:

		static void LogInit();

		static inline std::shared_ptr<spdlog::logger>& GetCoreLogger() 
		{
			return s_CoreLogger;
		}

		static inline std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}
