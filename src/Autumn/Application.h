#ifndef AUTUMN_CLASS_APPLICATION
#define AUTUMN_CLASS_APPLICATION

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

#endif
