#include "rpch.h"
#include "Rendering/Renderer.h"

#include "Rendering/RenderCommand.h"

namespace Rhodium::Core
{
	void Renderer::OnWindowResize(const glm::vec2& size)
	{
		RenderCommand::SetViewPortSize(0, 0, size.x, size.y);
	}

	void Renderer::Init()
	{
		RenderCommand::Init();
	}

}