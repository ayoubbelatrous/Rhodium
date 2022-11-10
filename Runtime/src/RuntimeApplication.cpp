#include "Application/Core/Application.h"
#include "Application/Core/Entry.h"
#include "RuntimeLayer.h"

namespace Rhodium::Core
{
	class RuntimeApplication : public Application
	{
	public:

		RuntimeApplication(Core::Data::ApplicationSpecification spec)
			:Application(spec)
		{
		}

		~RuntimeApplication()
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
		RuntimeApplication* App = new RuntimeApplication(spec);
		App->PushLayer(new RuntimeLayer());
		return App;
	}
}