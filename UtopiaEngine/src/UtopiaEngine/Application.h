#pragma once

#include "Core.h"

namespace Utopia 
{
	class UTOPIA_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
	};

	// To be defined in client application
	Application* CreateApplication();
}
