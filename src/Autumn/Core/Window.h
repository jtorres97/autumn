#pragma once

#include "Events/Event.h"

#include <GLFW/glfw3.h>

#include <functional>
#include <memory>
#include <string>

namespace Autumn
{
	using EventCallbackFunc = std::function<void(Event&)>;

	struct WindowProperties
	{
		std::string title;
		unsigned int width;
		unsigned int height;
		bool vsync;
		EventCallbackFunc callback;
	};

	class Window
	{
	public:
		Window(const WindowProperties& props);
		~Window();

		void OnUpdate();

		[[nodiscard]] unsigned int GetWidth() const { return m_properties.width; }
		[[nodiscard]] unsigned int GetHeight() const { return m_properties.height; }
		[[nodiscard]] bool IsVsync() const { return m_properties.vsync; }

		void SetEventCallback(const EventCallbackFunc& callback) { m_properties.callback = callback; }
		void SetVsync(bool enabled);
		
	private:
		void Initialize(const WindowProperties& props);
		void Close();

		GLFWwindow* m_window;
		WindowProperties m_properties;

		static bool s_glfwInit;
	};
}