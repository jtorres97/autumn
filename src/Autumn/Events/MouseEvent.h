#pragma once

#include "Event.h"

#include <sstream>

namespace Autumn
{
	class MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(float x, float y) : m_mouseX(x), m_mouseY(y) {}

		[[nodiscard]] float GetX() const { return m_mouseX; }
		[[nodiscard]] float GetY() const { return m_mouseY; }

		[[nodiscard]] std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY;
			return ss.str();
		}

		AUTUMN_EVENT_CLASS_TYPE(MouseMove)
		AUTUMN_EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		
	private:
		float m_mouseX;
		float m_mouseY;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float x, float y) : m_mouseX(x), m_mouseY(y) {}

		[[nodiscard]] float GetX() const { return m_mouseX; }
		[[nodiscard]] float GetY() const { return m_mouseY; }

		[[nodiscard]] std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_mouseX << ", " << m_mouseY;
			return ss.str();
		}

		AUTUMN_EVENT_CLASS_TYPE(MouseScrolled)
		AUTUMN_EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		
	private:
		float m_mouseX;
		float m_mouseY;
	};

	class MouseButtonEvent : public Event
	{
	public:
		[[nodiscard]] int GetMouseButton() const { return m_button; }

		AUTUMN_EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
		
	protected:
		MouseButtonEvent(int button) : m_button(button) {}
		
		int m_button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		[[nodiscard]] std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_button;
			return ss.str();
		}

		AUTUMN_EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		[[nodiscard]] std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_button;
			return ss.str();
		}

		AUTUMN_EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}