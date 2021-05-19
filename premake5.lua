include "build/conanbuildinfo.premake.lua"
include "qt-premake/qt.lua"

local qt = premake.extensions.qt

workspace "TileCreator"
    conan_basic_setup()

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "TileCreator"
    location "TileCreator"
    kind "ConsoleApp"
    language "C++"

    qt.enable()
    qtpath("C:\\Qt\\6.0.3\\msvc2019_64")
    qtincludepath("C:\\Qt\\6.0.3\\msvc2019_64\\include")
    qtlibpath("C:\\Qt\\6.0.3\\msvc2019_64\\lib")
    qtbinpath("C:\\Qt\\6.0.3\\msvc2019_64\\bin")
    qtprefix "Qt6"
    qtmodules {"core", "gui", "opengl", "widgets"}
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
            "{COPY} ../file-link/Qt6Core.dll %{cfg.targetdir}",
            "{COPY} ../file-link/Qt6Gui.dll %{cfg.targetdir}",
            "{COPY} ../file-link/Qt6Widgets.dll %{cfg.targetdir}",
            "{COPYDIR} ../file-link/ %{cfg.targetdir}"
        }