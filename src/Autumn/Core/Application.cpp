#include "Application.h"

namespace Autumn
{
	Application::Application()
	{
		m_window = std::make_unique<Window>(WindowProperties{ "Autumn", 1280, 720, true });
		m_window->SetEventCallback(AUTUMN_EVENT_BIND_FUNCTION(Application::OnEvent));
	}

	Application::~Application()
	{
		glfwTerminate();
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(AUTUMN_EVENT_BIND_FUNCTION(Application::OnWindowClose));

		AUTUMN_ENGINE_TRACE("Event recieved: {0}", event.ToString());
	}

	void Application::Run()
	{
		while (m_running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_running = false;
		return true;
	}
}
