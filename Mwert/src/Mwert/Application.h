#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Mwert
{
	class  MWERT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	
	Application* CreateApplication();
}


