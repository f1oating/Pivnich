#include <Pivnich.h>

class Sandbox : public PV::App
{
public:
    Sandbox()
    {
    }

    ~Sandbox()
    {
    }

};

PV::App* PV::CreateApp()
{
    return new Sandbox();
}