#include "mwpch.h"
#include "Application.h"

#include "Mwert/Events/ApplicationEvent.h"
#include "Mwert/Log.h"


namespace Mwert
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
		
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}