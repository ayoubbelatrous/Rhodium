#pragma once
#include "Layer/Layer.h"

namespace Rhodium::Core 
{
	class RuntimeLayer : public Layer
	{

	public:
		void OnInit() override;


		void OnUpdate() override;


		void OnEvent(Core::Event& e) override;


		void OnRender() override;


		void OnShutdown() override;


		void OnGUIRender() override;

	};
}