#include "Application/Core/Application.h"
#include "Application/Core/Entry.h"

namespace Rhodium
{
	Core::Data::ApplicationSpecification spec;
	Core::Application* Core::CreateApplication()
	{
		spec = { "Runtime App" };
		return new Application(spec);
	}
}