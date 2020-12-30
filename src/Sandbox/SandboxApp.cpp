#include <Autumn.h>

class Sandbox : public Autumn::Application
{
public:
	Sandbox() = default;
	~Sandbox() = default;

	void Run() override
	{
		while (true){}
	}
};

Autumn::Application* Autumn::CreateApplication()
{
	return new Sandbox();
}
