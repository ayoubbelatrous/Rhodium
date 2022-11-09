#include "rpch.h"
#include "Platform/Windows/WindowsWindow.h"

namespace Rhodium::Platform
{
	WindowsWindow::WindowsWindow(Core::WindowSpecification& spec)
		:m_Specification(spec),m_Properties(m_Specification.WindowProps)
	{
	}

	void WindowsWindow::OnUpdate()
	{
	}

	void WindowsWindow::OnShutdown()
	{
	}
}