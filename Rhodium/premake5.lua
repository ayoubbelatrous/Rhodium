project "Rhodium"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/".. outputdir .. "/%{prj.name}")

    pchsource "src/rpch.cpp"
    pchheader "rpch.h"

    includedirs
    {
        "src",
        "%{IncludeDir.GLFW}",
    }
    
    files
    {
        "src/**.h",
		"src/**.cpp"
    }

    links
	{
		"GLFW",
	}

    filter "system:windows"
	    systemversion "latest"
        defines "RH_WINDOWS"

	filter "configurations:Debug"
		defines "RH_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RH_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "RH_DIST"
		runtime "Release"
		optimize "on"