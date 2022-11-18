#pragma once

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
		virtual void SetViewPortSize(int x, int y, int w, int h) = 0;
	private:
		static RenderApiType s_API;
	};
}