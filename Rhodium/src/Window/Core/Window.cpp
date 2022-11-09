#include "rpch.h"

#include "Window/Core/Window.h"
#include "Platform/Windows/WindowsWindow.h"

namespace Rhodium::Core
{
	Scope<Window> Window::Create(WindowSpecification& spec)
	{
#ifdef RH_WINDOWS
		return CreateScope<Rhodium::Platform::WindowsWindow>(spec);
#else
		return nullptr;
#endif
	}

}
