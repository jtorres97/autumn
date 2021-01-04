#include "Window.h"

namespace Autumn
{
	bool Window::s_glfwInit = false;
	
	Window::Window(const WindowProperties& props)
	{
		Initialize(props);
	}

	Window::~Window()
	{
		Close();
	}

	void Window::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void Window::SetVsync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		m_properties.vsync = enabled;
	}

	void Window::Initialize(const WindowProperties& props)
	{
		m_properties = props;

		AUTUMN_ENGINE_INFO("Creating window {0} ({1}x{2})", props.title, props.width, props.height);

		if (!s_glfwInit)
		{
			auto success = glfwInit();
			AUTUMN_CORE_ASSERT(success, "Unable to initialize GLFW!");

			s_glfwInit = true;
		}

		m_window = glfwCreateWindow(props.width, props.height, props.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_properties);

		SetVsync(props.vsync);
	}

	void Window::Close()
	{
		glfwDestroyWindow(m_window);
	}
}
