workspace "UtopiaEngine"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "UtopiaEngine"
	location "UtopiaEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines {
			"UTOPIA_PLATFORM_WINDOWS",
			"UTOPIA_BUILD_DLL",
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "UTOPIA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "UTOPIA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "UTOPIA_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"UtopiaEngine/vendor/spdlog/include",
		"UtopiaEngine/src/UtopiaEngine"
	}

	links {
		"UtopiaEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines {
			"UTOPIA_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "UTOPIA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "UTOPIA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "UTOPIA_DIST"
		optimize "On"