#pragma once
#include "Layer/Layer.h"

namespace Rhodium::Gui
{
	class GuiLayer : public Core::Layer
	{
	public:

		void OnInit() override;


		void OnUpdate() override;


		void OnEvent(Core::Event& e) override;


		void OnGuiLayerBegin();
		void OnRender() override;
		void OnGuiLayerEnd();


		void OnShutdown() override;


		void OnGUIRender() override;
	};
}