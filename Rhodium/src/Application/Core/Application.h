#pragma once

#include "Application/Core/ApplicationData.h"

#include "Core/Base.h"

#include "Layer/LayerStack.h"
#include "Layer/Layer.h"

#include "Window/Core/Window.h"

#include "Events/Event.h"
#include "Events/ApplicationEvents.h"
#include <Rendering/RenderingApi.h>

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


		inline Window& GetWindow() { return *m_Window; }

		inline RenderingApi& GetRenderingApi() { return *m_RenderingApi; }

	private:

		Data::ApplicationSpecification m_Specification;
		LayerStack m_LayerStack;
		Scope<Window> m_Window;

		Scope<RenderingApi> m_RenderingApi;

		bool m_Minimized = false;
		bool m_Running = true;
		static Application* s_Instance;

	public:
		static Application* Get() { return s_Instance; }
	};

	Application* CreateApplication();
}