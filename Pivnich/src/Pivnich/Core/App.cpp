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

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
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

            m_Window->OnUpdate();
        }
    }

    void App::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));
    }

    bool App::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;
        return true;
    }

    bool App::OnWindowResize(WindowResizeEvent& e)
    {
        if (e.GetWidth() == 0 || e.GetHeight() == 0)
        {
            m_Minimized = true;
            return false;
        }

        m_Minimized = false;

        return false;
    }

}