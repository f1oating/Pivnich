#pragma once

#ifdef PV_PLATFORM_WINDOWS

extern PV::App* PV::CreateApp();

int main(int argc, char** argv)
{
    PV::Log::Init();
    PV_LOG_CORE_INFO("Log initialized");

    PV::App* app = PV::CreateApp();
    app->Loop();
    delete app;
}

#endif