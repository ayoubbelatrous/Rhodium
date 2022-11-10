#include "rpch.h"
#include "Rendering/GraphicsContext.h"
#include "Platform/OpenGL/OpenGLGraphicsContext.h"

namespace Rhodium::Core
{
	Scope<GraphicsContext> GraphicsContext::Create()
	{
		return CreateScope<Platform::OpenGLGraphicsContext>();
	}
}