#include "RuntimeLayer.h"
#include <glm/glm.hpp>

#include "Rendering/RenderCommand.h"


namespace Rhodium::Core
{
	void RuntimeLayer::OnInit()
	{
	}

	void RuntimeLayer::OnUpdate()
	{
	}

	void RuntimeLayer::OnEvent(Core::Event& e)
	{
	}

	void RuntimeLayer::OnRender()
	{
		RenderCommand::Clear();
	}

	void RuntimeLayer::OnShutdown()
	{
	}

	void RuntimeLayer::OnGUIRender()
	{
	}

}