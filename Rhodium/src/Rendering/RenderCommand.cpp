#include "rpch.h"
#include "Rendering/RenderCommand.h"

namespace Rhodium::Core
{

	void RenderCommand::Init()
	{
		s_RendererAPI = RenderingApi::Create();
	}

	void RenderCommand::Clear()
	{
		s_RendererAPI->Clear();
	}

	void RenderCommand::SetClearColor(const glm::vec4& color)
	{
		s_RendererAPI->SetClearColor(color);
	}

	void RenderCommand::SetViewPortSize(uint32_t x, uint32_t y, uint32_t w, uint32_t h)
	{
		s_RendererAPI->SetViewPortSize(x,y,w,h);
	}

	Rhodium::Scope<Rhodium::Core::RenderingApi> RenderCommand::s_RendererAPI;

}