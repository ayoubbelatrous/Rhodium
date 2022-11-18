#pragma once
#include "Rendering/RenderingApi.h"


namespace Rhodium::Platform
{
	class OpenGLRenderingApi : public Core::RenderingApi
	{
	public:
		void Init() override;
		void SetViewPortSize(int x, int y, int w, int h) override;
	};
}