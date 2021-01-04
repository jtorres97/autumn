#pragma once

#include "Window.h"

namespace Autumn
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();
		
	private:
		std::unique_ptr<Window> m_window;
		bool m_running = true;
	};

	Application* CreateApplication();
}
