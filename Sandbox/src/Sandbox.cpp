#include <Pivnich.h>

class Sandbox : public PV::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

PV::Application* PV::CreateApplication()
{
	return new Sandbox();
}