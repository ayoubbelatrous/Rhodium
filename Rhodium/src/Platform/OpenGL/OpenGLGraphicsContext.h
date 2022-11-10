#pragma once
#include "Rendering/GraphicsContext.h"

namespace Rhodium::Platform
{
	class OpenGLGraphicsContext : public Core::GraphicsContext
	{
	public:
		void Init() override;
	};
}