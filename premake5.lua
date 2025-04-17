workspace "Pivnich"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["glfw"] = "Pivnich/vendor/glfw/include"

include "Pivnich/vendor/glfw"

project "Pivnich"
	location "Pivnich"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pvpch.h"
	pchsource "Pivnich/src/pvpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.glfw}",
	}

	links
	{
		"glfw"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PV_PLATFORM_WINDOWS",
			"PV_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "language:C++"
		buildoptions { "/utf-8" }

	filter "configurations:Debug"
		defines "PV_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PV_RELEASE"
		runtime "Release"
		optimize "On"	

	filter "configurations:Dist"
		defines "PV_DIST"
		runtime "Release"
		optimize "On"

-------------------------------------------------------------

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
		"Pivnich/vendor/spdlog/include",
        "Pivnich/src"
    }

    links
    {
        "Pivnich"
    }

	filter "language:C++"
		buildoptions { "/utf-8" }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "PV_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "PV_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "PV_RELEASE"
        runtime "Release"
        optimize "On"	

    filter "configurations:Dist"
        defines "PV_DIST"
        runtime "Release"
        optimize "On"