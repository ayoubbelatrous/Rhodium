#include "RuntimeLayer.h"
#include "glm/glm.hpp"
namespace Rhodium::Core
{
	void RuntimeLayer::OnInit()
	{
	}

	void RuntimeLayer::OnUpdate()
	{
		std::cout << "test!";
	}

	void RuntimeLayer::OnEvent(Core::Event& e)
	{
	}

	void RuntimeLayer::OnRender()
	{
	}

	void RuntimeLayer::OnShutdown()
	{
	}

	void RuntimeLayer::OnGUIRender()
	{
	}

}