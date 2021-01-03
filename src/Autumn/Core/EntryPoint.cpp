#include "Application.h"
#include "Logger.h"

extern Autumn::Application* Autumn::CreateApplication();

int main(int argc, char** argv)
{
	Autumn::Logger::Initialize("APP");
	AUTUMN_ENGINE_INFO("Finished engine initialization.");
	
	auto app = Autumn::CreateApplication();
	AUTUMN_ENGINE_INFO("Finished client application initialization.");
	app->Run();
	delete app;
}
