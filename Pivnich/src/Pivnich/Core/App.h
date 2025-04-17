#pragma once

#include "Base.h"
#include "Pivnich/Events/Event.h"

namespace PV {

    class PV_API App
    {
    public:
        App();
        virtual ~App();

        void Loop();

        void OnEvent(Event& e);

        inline static App& Get() { return *s_Instance; }

    private:
        bool m_Running = true;
        bool m_Minimized = false;

    private:
        static App* s_Instance;
    };

    App* CreateApp();

}