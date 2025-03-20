workspace "Hazel"
	architecture "x64"
	startproject "Sandbox"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "Hazel"
	location "Hazel"
	kind "SharedLib"
	language "C++"
 
 	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
 	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}
		
	buildoptions { "/utf-8" }
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.19041.0"
		
		defines
		{
			"HZ_PLATFORM_WINDOWS",
			"HZ_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPYDIR} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"
	
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
 	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
 	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Hazel/vendor/spdlog/include",
		"Hazel/src"
	}
	
	links
	{
		"Hazel"
	}
	
	buildoptions { "/utf-8" }
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.19041.0"
		
		defines
		{
			"HZ_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"