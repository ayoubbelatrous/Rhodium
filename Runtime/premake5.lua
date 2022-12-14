project "Runtime"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Rhodium/src",
		"%{IncludeDir.GLM}",
		"%{IncludeDir.ENTT}"
	}

	links
	{
		"Rhodium"
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