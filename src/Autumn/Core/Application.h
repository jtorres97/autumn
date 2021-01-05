#pragma once

#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace Autumn
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& event);
		
	private:
		bool OnWindowClose(WindowCloseEvent& event);
		
		std::unique_ptr<Window> m_window;
		bool m_running = true;
	};

	Application* CreateApplication();
}
