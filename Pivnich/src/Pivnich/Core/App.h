#pragma once

#include "Base.h"

namespace PV {

    class App
    {
    public:
        PV_API App();
        PV_API virtual ~App();

        PV_API void Loop();
    };

    App* CreateApp();

}