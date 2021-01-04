#include <Autumn.h>

#include "Events/ApplicationEvent.h"

class Sandbox : public Autumn::Application
{
public:
	Sandbox() = default;
	~Sandbox() = default;
};

Autumn::Application* Autumn::CreateApplication()
{
	return new Sandbox();
}
