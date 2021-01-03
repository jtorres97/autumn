#pragma once

namespace Autumn
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run() = 0;
	private:
	};

	Application* CreateApplication();
}
