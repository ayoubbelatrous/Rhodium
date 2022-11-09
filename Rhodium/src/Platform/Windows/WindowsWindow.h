#pragma once
#include "Window/Core/Window.h"

namespace Rhodium::Platform
{
	class WindowsWindow : public Core::Window
	{
	public:
		WindowsWindow(Core::WindowSpecification& spec);

		void* GetNativeWindow() const override
		{
		}

		void OnUpdate() override;

		void OnShutdown() override;

	private:
		Core::WindowSpecification m_Specification;
		Core::WindowProperties m_Properties;
	};
}