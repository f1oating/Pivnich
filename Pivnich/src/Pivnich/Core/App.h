#pragma once

#include "Base.h"

namespace PV {

    class PV_API App
    {
    public:
        App();
        virtual ~App();

        void Loop();

        void OnEvent();
    };

    App* CreateApp();

}