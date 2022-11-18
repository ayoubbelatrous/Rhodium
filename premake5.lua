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
IncludeDir["GLAD"] = "%{wks.location}/Rhodium/vendor/glad/include"
IncludeDir["GLM"] = "%{wks.location}/Rhodium/vendor/glm"
IncludeDir["IMGUI"] = "%{wks.location}/Rhodium/vendor/imgui"
IncludeDir["ENTT"] = "%{wks.location}/Rhodium/vendor/entt/include"

group "Dependencies"
	include "Rhodium/vendor/glfw"
    include "Rhodium/vendor/glad"
    include "Rhodium/vendor/imgui"
group ""


include "Rhodium"
include "Runtime"