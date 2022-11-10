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

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Rhodium/vendor/GLFW/include"
IncludeDir["GLM"] = "%{wks.location}/Rhodium/vendor/glm"

group "Dependencies"
	include "Rhodium/vendor/glfw"
group ""


include "Rhodium"
include "Runtime"