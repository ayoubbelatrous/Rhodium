#include "rpch.h"

#include "Platform/Windows/WindowsWindow.h"
#include "Events/ApplicationEvents.h"

namespace Rhodium::Platform
{
	WindowsWindow::WindowsWindow(Core::WindowSpecification& spec)
		:m_Specification(spec), m_Properties(m_Specification.WindowProps)
	{
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);



		m_GLFWWindowPtr = glfwCreateWindow(m_Specification.WindowProps.Width, m_Specification.WindowProps.Height
			, m_Specification.WindowProps.WindowName.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_GLFWWindowPtr);


		m_Context = Core::GraphicsContext::Create();
		m_Context->Init();

		glfwSetWindowUserPointer(m_GLFWWindowPtr, &m_Data);

		glfwSetWindowSizeCallback(m_GLFWWindowPtr, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		data.Width = width;
		data.Height = height;

		Core::WindowResizeEvent event(width, height);
		data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(m_GLFWWindowPtr, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		Core::WindowCloseEvent event;
		data.EventCallback(event);
			});
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_GLFWWindowPtr);
	}

	void WindowsWindow::OnShutdown()
	{
		glfwDestroyWindow(m_GLFWWindowPtr);
		glfwTerminate();
	}

	void WindowsWindow::SetEventCallback(const EventCallbackFn& eventCallback)
	{
		m_Data.EventCallback = eventCallback;
	}

	bool WindowsWindow::GetKey(const Core::KeyCode keyCode)
	{
		auto state = glfwGetKey(m_GLFWWindowPtr, static_cast<int32_t>(keyCode));
		return state == GLFW_PRESS;
	}

	bool WindowsWindow::GetMouseButton(uint16_t i)
	{
		return glfwGetMouseButton(m_GLFWWindowPtr, i) == GLFW_PRESS;
	}

	int WindowsWindow::GetWidth()
	{

		return m_Data.Width;
	}

	int WindowsWindow::GetHeight()
	{
		return m_Data.Height;
	}

}