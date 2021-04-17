include "build/conanbuildinfo.premake.lua"

workspace "TileEditor"
    conan_basic_setup()

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "TileEditor"
    location "TileEditor"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

    linkoptions { conan_exelinkflags }

    files
    {
        "**.h", "**.cpp"
    }

    configuration "windows"
        cppdialect "C++17"

        postbuildcommands {
            "{COPY} ../build/bin/Qt6Core.dll %{cfg.targetdir}",
            "{COPY} ../build/bin/Qt6Gui.dll %{cfg.targetdir}",
            "{COPY} ../build/bin/Qt6Widgets.dll %{cfg.targetdir}",
            "{COPYDIR} ../build/bin/ %{cfg.targetdir}"
        }