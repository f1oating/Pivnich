#include <Pivnich.h>

class Sandbox : public PV::App
{
public:
	Sandbox()
	{
		PV_LOG_APP_INFO("App class created");
	}

	~Sandbox()
	{

	}

};

PV::App* PV::CreateApp()
{
	return new Sandbox();
}