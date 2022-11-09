#pragma once

#include "Core/Base.h"
#include "Application/Core/Application.h"

#ifdef RH_WINDOWS

extern Rhodium::Core::Application* CreateApplication();

int main()
{
	auto app = Rhodium::Core::CreateApplication();
	app->Run();
	delete app;
}
#endif
