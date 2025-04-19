#include <Pivnich.h>

#include "Pivnich/Core/EntryPoint.h"

#include "Sandbox2D.h"

class Sandbox : public PV::App
{
public:
    Sandbox()
    {
        PushLayer(new Sandbox2D());
    }

    ~Sandbox()
    {
    }

};

PV::App* PV::CreateApp()
{
    return new Sandbox();
}