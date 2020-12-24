#pragma once

#ifdef MW_PLATFORM_WINDOWS

extern Mwert::Application* Mwert::CreateApplication();

void main(int argc, char** argv)
{
	Mwert::Log::Init();
	MW_CORE_WARN("Initialized Log!");
	int a = 5;
	MW_INFO("Hello Var = {0}", a);
	
	auto app = Mwert::CreateApplication();
	app->Run();
	delete app;
}

#endif

