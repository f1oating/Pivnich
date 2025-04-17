#include "pvpch.h"

#include "App.h"
#include "Pivnich/Events/ApplicationEvent.h"

namespace PV {

    #define BIND_EVENT_FN(x) std::bind(&App::x, this, std::placeholders::_1)

    App* App::s_Instance = nullptr;

    App::App()
    {
        PV_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;
    }

    App::~App()
    {

    }

    void App::Loop()
    {
        while (m_Running)
        {
            if (!m_Minimized)
            {

            }
        }
    }

    void App::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
    }

}