#pragma once

#include "Events/Event.h"

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
		using EventCallbackFn = std::function<void(Core::Event&)>;
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;
		virtual void OnShutdown() = 0;

		virtual void* GetNativeWindow() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& eventCallback) = 0;

		static Scope<Window> Create(WindowSpecification& spec);

	private:
	};
}