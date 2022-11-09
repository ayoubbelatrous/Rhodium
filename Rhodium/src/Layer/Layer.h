#pragma once

#include "Events/Event.h"

namespace Rhodium::Core
{
	class Layer
	{
	public:
		virtual void OnInit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnEvent(Core::Event& e) = 0;
		virtual void OnRender() = 0;
		virtual void OnShutdown() = 0;
	};
}