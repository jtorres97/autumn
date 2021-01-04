#include <Autumn.h>

#include "Events/ApplicationEvent.h"

class Sandbox : public Autumn::Application
{
public:
	Sandbox() = default;
	~Sandbox() = default;

	void Run() override
	{
		Autumn::WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(Autumn::EventCategoryApplication))
			AUTUMN_TRACE(e.ToString());
		AUTUMN_CORE_ASSERT(e.GetWidth() == 1270, "Window Width");
		while (true){}
	}
};

Autumn::Application* Autumn::CreateApplication()
{
	return new Sandbox();
}
