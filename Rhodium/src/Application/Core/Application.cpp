#include "rpch.h"
#include "Application/Core/Application.h"

namespace Rhodium::Core
{

	Application::Application(Data::ApplicationSpecification spec)
	{
		m_Specification = spec;
		std::cout << spec.ApplicationName;
	}

	Application::~Application()
	{

	}

}