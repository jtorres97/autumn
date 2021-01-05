#pragma once

#include "Event.h"

#include <sstream>

namespace Autumn
{
	class KeyEvent : public Event
	{
	public:
		[[nodiscard]] int GetKeyCode() const { return m_keyCode; }

		AUTUMN_EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
		
	protected:
		KeyEvent(int keyCode) : m_keyCode(keyCode) {}
		
		int m_keyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, unsigned int repeatCount) : KeyEvent(keyCode), m_repeatCount(repeatCount) {}

		[[nodiscard]] unsigned int GetRepeatCount() const { return m_repeatCount; }
		[[nodiscard]] std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
			return ss.str();
		}

		AUTUMN_EVENT_CLASS_TYPE(KeyPressed)
		
	private:
		int m_repeatCount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

		[[nodiscard]] std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_keyCode;
			return ss.str();
		}

		AUTUMN_EVENT_CLASS_TYPE(KeyReleased)
	};
}