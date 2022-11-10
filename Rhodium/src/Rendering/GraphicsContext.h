#pragma once

namespace Rhodium::Core
{
	class GraphicsContext
	{
	public:
		GraphicsContext() = default;
		virtual ~GraphicsContext() = default;
		virtual void Init() = 0;
		static Scope<GraphicsContext> Create();
	private:
	};
}