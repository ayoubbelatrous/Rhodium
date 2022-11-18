#pragma once

#include "Rendering/RenderingApi.h"

namespace Rhodium::Core
{
	class RenderCommand
	{
	public:
		static void Init();
		static void SetViewPortSize(uint32_t x, uint32_t y, uint32_t w, uint32_t h);
		static void Clear();
		static void SetClearColor(const glm::vec4& color);
	private:
		static Scope<RenderingApi> s_RendererAPI;
	};
}