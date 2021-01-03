#pragma once

#include <functional>

#include "Core/Core.h"

#include <string>

namespace Autumn
{
	enum class EventType
	{
		None = 0,
		WindowClose,
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,
		AppTick,
		AppUpdate,
		AppRender,
		KeyPressed,
		KeyReleased,
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMove,
		MouseScrolled,
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define AUTUMN_EVENT_CLASS_TYPE(type)                                                                                                         \
	[[nodiscard]] static EventType GetStaticType() { return EventType::##type; }														      \
	[[nodiscard]] virtual EventType GetEventType() const override { return GetStaticType(); }                                                 \
	[[nodiscard]] virtual const char* GetName() const override { return #type; }

#define AUTUMN_EVENT_CLASS_CATEGORY(category)                                                                                                 \
	[[nodiscard]] virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory category) const { return GetCategoryFlags() & category; }

	protected:
		bool m_handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFunc = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : m_event(event) {}

		template<typename T>
		bool Dispatch(EventFunc<T> function)
		{
			if (m_event.GetEventType() == T::GetStaticType())
			{
				m_event.m_handled = function(*(T*)&m_event);
				return true;
			}
			return false;
		}
		
	private:
		Event& m_event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event) { return os << event.ToString(); }
}