#pragma once

#ifdef PV_PLATFORM_WINDOWS

extern PV::Application* PV::CreateApplication();

int main(int argc, char** argv)
{
    PV::Log::Init();
    PV_CORE_WARN("Initialized Log!");

    auto app = PV::CreateApplication();
    app->Run();
    delete app;
}

#endif