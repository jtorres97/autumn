#ifndef AUTUMN_ENTRYPOINT
#define AUTUMN_ENTRYPOINT

#include "Application.h"

extern Autumn::Application* Autumn::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Autumn::CreateApplication();
	app->Run();
	delete app;
}

#endif
