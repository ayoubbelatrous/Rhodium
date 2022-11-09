#include "rpch.h"
#include "Application/Core/Application.h"

namespace Rhodium::Core
{
	Application::Application(Data::ApplicationSpecification spec)
		:m_Specification(spec)
	{
		WindowSpecification windowSpecification =
		{
			{m_Specification.ApplicationName,720,1280},
			VSync::EveryVBlank
		};
		m_Window = Window::Create(windowSpecification);
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true)
		{
			m_Window->OnUpdate();
		}
	}
}