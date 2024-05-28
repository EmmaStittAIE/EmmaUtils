workspace "Emma Utils Workspace"
    filename "EmmaUtilsWorkspace"
    startproject "Emma Utils"

    language "C++"
    cppdialect "C++20"
    toolset "clang"

    location "generated"
    
    configurations { "Debug", "Release" }
    platforms { "Linux", "Win32", "Win64" }

    filter "configurations:Debug"
        symbols "On"
        optimize "Debug"
    
        defines { "_DEBUG" }

    filter "configurations:Release"
        symbols "Off"
        optimize "On"

        defines { "_RELEASE" }

    filter "platforms:Linux"
        system "linux"
        architecture "x86_64"

        defines { "_LINUX" }

    filter "platforms:Win32"
        system "windows"
        architecture "x86"

        defines { "_WIN32" }

    filter "platforms:Win64"
        system "windows"
        architecture "x86_64"

        defines { "_WIN64" }

    filter {}

project "Emma Utils"
    filename "EmmaUtils"
    targetname "EmmaUtils"
    targetdir "build/%{cfg.platform}/%{cfg.buildcfg}"
    objdir "build/%{cfg.platform}/%{cfg.buildcfg}/obj"

    prebuildcommands
    {
        "{MKDIR} %[build/%{cfg.platform}/%{cfg.buildcfg}]",
        "{RMDIR} %[build/%{cfg.platform}/%{cfg.buildcfg}/include]",
        "{COPYDIR} %[include] %[build/%{cfg.platform}/%{cfg.buildcfg}]"
    }

    includedirs
    {
        "include"
    }

    files
    {
        "src/**.cpp"
    }

    kind "StaticLib"

    filter "configurations:Debug"
        targetsuffix "-d"

    filter {}
