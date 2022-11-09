#pragma once

#include "Application/Core/ApplicationData.h"

#include "Core/Base.h"

#include "Layer/LayerStack.h"
#include "Layer/Layer.h"

#include "Window/Core/Window.h"

#include "Events/Event.h"
#include "Events/ApplicationEvents.h"


namespace Rhodium::Core
{
	class Application
	{
	public:
		Application() = default;
		Application(Data::ApplicationSpecification spec);
		~Application();

		void Run();
		void OnEvent(Event& e);

		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		Data::ApplicationSpecification m_Specification;
		LayerStack m_LayerStack;
		Scope<Window> m_Window;

		bool m_Minimized = false;
		bool m_Running = true;
	};

	Application* CreateApplication();
}