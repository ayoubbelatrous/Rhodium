#pragma once
#include "Window/Core/Window.h"
#include "GLFW/glfw3.h"

namespace Rhodium::Platform
{
	class WindowsWindow : public Core::Window
	{
	public:
		WindowsWindow(Core::WindowSpecification& spec);

		void* GetNativeWindow() const override
		{
			return nullptr;
		}

		void OnUpdate() override;
		void OnShutdown() override;

	private:

		struct WindowData
		{
			std::string Title;

			uint32_t width, height;
			bool vsync;
		};

		Core::WindowSpecification m_Specification;
		Core::WindowProperties m_Properties;

		WindowData m_Data;
		GLFWwindow* m_GLFWWindowPtr;
	};
}