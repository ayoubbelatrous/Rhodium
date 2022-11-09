#pragma once
#include "Application/Core/ApplicationData.h"
#include "Core/Base.h"
#include "Layer/LayerStack.h"
#include "Window/Core/Window.h"

namespace Rhodium::Core
{
	class Application
	{
	public:
		Application() = default;
		Application(Data::ApplicationSpecification spec);
		~Application();
		void Run();
	private:
		Data::ApplicationSpecification m_Specification;
		Ref<Layers::LayerStack> m_LayerStack;
		Scope<Window> m_Window;
	};

	Application* CreateApplication();
}