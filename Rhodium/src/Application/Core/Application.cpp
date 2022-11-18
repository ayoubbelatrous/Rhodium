#include "rpch.h"
#include "Application/Core/Application.h"
#include "Input/Input.h"

namespace Rhodium::Core
{
	Application* Application::s_Instance = nullptr;

	Application::Application(Data::ApplicationSpecification spec)
		:m_Specification(spec)
	{
		if (s_Instance == nullptr)
		{
			s_Instance = this;
		}

		WindowSpecification windowSpecification =
		{
			{m_Specification.ApplicationName,720,1280},
			VSync::EveryVBlank
		};
		m_Window = Window::Create(windowSpecification);

		m_Window->SetEventCallback(RH_BIND_EVENT_FN(Application::OnEvent));

		m_RenderingApi = RenderingApi::Create();

		m_GuiLayer = new Gui::GuiLayer;

		m_LayerStack.PushOverlay(m_GuiLayer);

		for (Layer* layer : m_LayerStack)
		{
			layer->OnInit();
		}
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			if (!m_Minimized)
			{
				{
					for (Layer* layer : m_LayerStack)
					{

						layer->OnUpdate();
						layer->OnRender();
					}
				}
				
				{
					
					m_GuiLayer->OnGuiLayerBegin();
					for (Layer* layer : m_LayerStack)
					{
						layer->OnGUIRender();
					}
					m_GuiLayer->OnGuiLayerEnd();
				}
			}
			 m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher eventDispatcher(e);

		eventDispatcher.Dispatch<WindowCloseEvent>(RH_BIND_EVENT_FN(Application::OnWindowClose));
		eventDispatcher.Dispatch<WindowResizeEvent>(RH_BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{

		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_RenderingApi->SetViewPortSize(0, 0, e.GetWidth(), e.GetHeight());

		m_Minimized = false;
		return false;
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	void Application::Shutdown()
	{
	}

}