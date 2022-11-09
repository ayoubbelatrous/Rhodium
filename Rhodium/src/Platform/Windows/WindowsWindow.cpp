#include "rpch.h"
#include "Platform/Windows/WindowsWindow.h"

namespace Rhodium::Platform
{
	WindowsWindow::WindowsWindow(Core::WindowSpecification& spec)
		:m_Specification(spec),m_Properties(m_Specification.WindowProps)
	{
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

		m_GLFWWindowPtr = glfwCreateWindow(m_Specification.WindowProps.Width, m_Specification.WindowProps.Height
			, m_Specification.WindowProps.WindowName.c_str(),nullptr,nullptr);

		glfwMakeContextCurrent(m_GLFWWindowPtr);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_GLFWWindowPtr);
	}

	void WindowsWindow::OnShutdown()
	{
		delete m_GLFWWindowPtr;
	}
}