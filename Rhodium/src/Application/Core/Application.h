#pragma once
#include "Application/Core/ApplicationData.h"

namespace Rhodium::Core
{
	class Application
	{
	public:
		Application() = default;
		Application(Data::ApplicationSpecification spec);
		~Application();
	private:
		Data::ApplicationSpecification m_Specification;
	};

	Application* CreateApplication();
}