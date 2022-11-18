#pragma once

#include "Rendering/RenderingApi.h"

namespace Rhodium::Core
{
	class Renderer
	{
	public:
		static void Init();
		static void OnWindowResize(const glm::vec2& size);
	};
}