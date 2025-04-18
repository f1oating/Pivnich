#pragma once

#include "Base.h"
#include "Window.h"
#include "LayerStack.h"

#include "Pivnich/Events/Event.h"
#include "Pivnich/Events/ApplicationEvent.h"

namespace PV {

    class PV_API App
    {
    public:
        App();
        virtual ~App();

        void Loop();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

        inline static App& Get() { return *s_Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        bool m_Minimized = false;
        LayerStack m_LayerStack;

    private:
        static App* s_Instance;
    };

    App* CreateApp();

}