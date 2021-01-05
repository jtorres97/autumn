#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace Autumn
{
	bool Window::s_glfwInit = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		AUTUMN_ENGINE_ERROR("GLFW error detected: {0}: {1}", error, description);
	}

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
			glfwSetErrorCallback(GLFWErrorCallback);

			s_glfwInit = true;
		}

		m_window = glfwCreateWindow(props.width, props.height, props.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_properties);

		SetVsync(props.vsync);

		// GLFW callbacks
		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
		{
			auto* const data = static_cast<WindowProperties*>(glfwGetWindowUserPointer(window));
			data->width = width;
			data->height = height;

			WindowResizeEvent resize{static_cast<unsigned int>(width), static_cast<unsigned int>(height)};
			data->callback(resize);
		});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
		{
			auto* const data = static_cast<WindowProperties*>(glfwGetWindowUserPointer(window));

			WindowCloseEvent close{};
			data->callback(close);
		});

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int keyCode, int scanCode, int action, int mods)
		{
			auto* const data = static_cast<WindowProperties*>(glfwGetWindowUserPointer(window));

			switch (action)
			{
			case GLFW_PRESS:
				{
					KeyPressedEvent press{keyCode, 0};
					data->callback(press);
				}
				break;
			case GLFW_REPEAT:
				{
					KeyPressedEvent press{keyCode, ++data->keyRepeats};
					data->callback(press);
				}
				break;
			case GLFW_RELEASE:
				{
					data->keyRepeats = 0;
					KeyReleasedEvent release{keyCode};
					data->callback(release);
				}
				break;
			default:
				{
					AUTUMN_ENGINE_WARN("Unrecognized GLFW key event (type: {})", action);
				}
				break;
			}
		});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
		{
			auto* const data = static_cast<WindowProperties*>(glfwGetWindowUserPointer(window));

			switch (action)
			{
			case GLFW_PRESS:
				{
					MouseButtonPressedEvent press{button};
					data->callback(press);
				}
				break;

			case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent release{button};
					data->callback(release);
				}
				break;

			default:
				{
					AUTUMN_ENGINE_WARN("Unrecognized GLFW mouse event (type: {})", action);
				}
				break;
			}
		});

		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			auto* const data = static_cast<WindowProperties*>(glfwGetWindowUserPointer(window));

			MouseScrolledEvent scroll{static_cast<float>(xOffset), static_cast<float>(yOffset)};
			data->callback(scroll);
		});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
		{
			auto* const data = static_cast<WindowProperties*>(glfwGetWindowUserPointer(window));

			MouseMoveEvent move{static_cast<float>(xPos), static_cast<float>(yPos)};
			data->callback(move);
		});
	}

	void Window::Close()
	{
		glfwDestroyWindow(m_window);
	}
}
