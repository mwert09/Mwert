#include "Application.h"

#include "Mwert/Events/ApplicationEvent.h"
#include "Mwert/Log.h"

namespace Mwert
{
	Application::Application()
	{
		
	}

	Application::~Application()
	{
		
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		MW_TRACE(e);

		while (true);
	}
}