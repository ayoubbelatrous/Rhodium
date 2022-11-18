#pragma once

#include <glm/glm.hpp>

namespace Rhodium::Core
{
	enum class RenderApiType
	{
		None,
		OpenGL
	};

	class RenderingApi
	{
	public:
		static Scope<RenderingApi> Create();
		virtual ~RenderingApi() = default;
		virtual void Init() = 0;
		static RenderApiType GetApi() { return s_API; };

		virtual void SetViewPortSize(uint32_t x, uint32_t y, uint32_t w, uint32_t h) = 0;
		virtual void Clear() = 0;
		virtual void SetClearColor(const glm::vec4& color) = 0;

	private:
		static RenderApiType s_API;
	};
}