#pragma once

#include "Event.h"

#include <sstream>

namespace Autumn
{
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_width(width), m_height(height) {}

		unsigned int GetWidth() const { return m_width; }
		unsigned int GetHeight() const { return m_height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_width << ", " << m_height;
			return ss.str();
		}

		AUTUMN_EVENT_CLASS_TYPE(WindowResize)
		AUTUMN_EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_width;
		unsigned int m_height;
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		AUTUMN_EVENT_CLASS_TYPE(WindowClose)
		AUTUMN_EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppTickEvent : public Event
	{
		AppTickEvent() = default;

		AUTUMN_EVENT_CLASS_TYPE(WindowClose)
		AUTUMN_EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppUpdateEvent : public Event
	{
		AppUpdateEvent() = default;

		AUTUMN_EVENT_CLASS_TYPE(AppUpdate)
		AUTUMN_EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppRenderEvent : public Event
	{
		AppRenderEvent() = default;

		AUTUMN_EVENT_CLASS_TYPE(AppRender)
		AUTUMN_EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}