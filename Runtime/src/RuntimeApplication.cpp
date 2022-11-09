#include "Application/Core/Application.h"
#include "Application/Core/Entry.h"

namespace Rhodium::Core
{
	class Runtime : public Application
	{
	public:

		Runtime(Core::Data::ApplicationSpecification spec)
			:Application(spec)
		{
		}

		~Runtime()
		{
		}
	};
}

namespace Rhodium
{
	Core::Data::ApplicationSpecification spec;

	Core::Application* Core::CreateApplication()
	{
		spec = { "Runtime App" };
		return new Runtime(spec);
	}
}