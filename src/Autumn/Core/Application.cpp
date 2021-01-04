#include "Application.h"

namespace Autumn
{
	Application::Application()
	{
		m_window = std::make_unique<Window>(WindowProperties{ "Autumn", 1280, 720, true });
	}

	Application::~Application()
	{
		glfwTerminate();
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
}
