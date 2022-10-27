workspace "Rhodium"
    architecture "x64"
    startproject "Runtime"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    flags
    {
        "MultiProcessorCompile"
    }
    defines
    {
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


include "Rhodium"
include "Runtime"