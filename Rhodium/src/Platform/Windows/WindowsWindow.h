#pragma once
#include "Window/Core/Window.h"
#include "GLFW/glfw3.h"
#include "Events/Event.h"
#include "Rendering/GraphicsContext.h"

namespace Rhodium::Platform
{
	class WindowsWindow : public Core::Window
	{
	public:

		WindowsWindow(Core::WindowSpecification& spec);

		void* GetNativeWindow() const override
		{
			return m_GLFWWindowPtr;
		}

		void OnUpdate() override;
		void OnShutdown() override;


		void SetEventCallback(const EventCallbackFn& eventCallback) override;


		bool GetKey(Core::KeyCode keyCode) override;
		bool GetMouseButton(uint16_t i) override;

		int GetWidth() override;
		int GetHeight() override;

	private:

		struct WindowData
		{
			std::string Title;

			uint32_t Width, Height;
			bool Vsync;
			EventCallbackFn EventCallback;
		};

		Core::WindowSpecification m_Specification;
		Core::WindowProperties m_Properties;

		WindowData m_Data;
		GLFWwindow* m_GLFWWindowPtr;

		Core::Scope<Core::GraphicsContext> m_Context;
	};
}