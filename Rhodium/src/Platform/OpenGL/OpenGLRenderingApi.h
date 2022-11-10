#pragma once
#include "Rendering/RenderingApi.h"


namespace Rhodium::Platform
{
	class OpenGLRenderingApi : public Core::RenderingApi
	{
	public:
		void Init() override;
	};
}