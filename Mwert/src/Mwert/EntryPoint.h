#pragma once

#ifdef MW_PLATFORM_WINDOWS

extern Mwert::Application* Mwert::CreateApplication();

void main(int argc, char** argv)
{
	printf("Mwert Engine\n");
	auto app = Mwert::CreateApplication();
	app->Run();
	delete app;
}

#endif

