#pragma once
#include "Rendering/RenderingApi.h"


namespace Rhodium::Platform
{
	class OpenGLRenderingApi : public Core::RenderingApi
	{
	public:
		void Init() override;

		void SetViewPortSize(uint32_t x, uint32_t y, uint32_t w, uint32_t h) override;

		void Clear() override;

		void SetClearColor(const glm::vec4& color) override;
	};
}