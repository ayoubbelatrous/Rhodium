#include "rpch.h"
#include "Rendering/RenderingApi.h"
#include "Platform/OpenGL/OpenGLRenderingApi.h"

namespace Rhodium::Core
{
	RenderApiType RenderingApi::s_API = RenderApiType::OpenGL;

	Scope<Core::RenderingApi> RenderingApi::Create()
	{
		return CreateScope<Platform::OpenGLRenderingApi>();
	}
}