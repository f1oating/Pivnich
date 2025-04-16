#pragma once

#include "Base.h"

namespace PV {

    class PV_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    Application* CreateApplication();

}