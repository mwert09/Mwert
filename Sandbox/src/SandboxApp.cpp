#include "Mwert.h"

class Sandbox : public Mwert::Application
{
public:
	Sandbox()
	{
		
	}
	~Sandbox()
	{
		
	}
};

Mwert::Application* Mwert::CreateApplication()
{
	return new Sandbox();
}