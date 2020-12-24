#pragma once

#include "Core.h"

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


