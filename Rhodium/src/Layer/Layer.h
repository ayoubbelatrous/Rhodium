#pragma once

namespace Rhodium::Layers
{
	class Layer
	{
	public:
		virtual void OnInit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnRender() = 0;
		virtual void OnShutdown() = 0;
	};
}