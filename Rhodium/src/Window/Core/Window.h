#pragma once
#include <string>

namespace Rhodium::Core
{
	enum class VSync
	{
		None,
		EveryVBlank,
		EverySecondVBlank
	};
	
	struct WindowProperties
	{
		std::string WindowName = "Window";
		uint32_t Width, Height;
	};

	struct WindowSpecification
	{
		WindowProperties WindowProps;
		VSync Vsync;
	};

	class Window
	{
	public:
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;
		virtual void OnShutdown() = 0;

		virtual void* GetNativeWindow() const = 0;
		static Scope<Window> Create(WindowSpecification& spec);

	private:
	};
}