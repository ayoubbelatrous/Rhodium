#include "rpch.h"
#include "Input/Input.h"
#include "Application/Core/Application.h"

namespace Rhodium::Core
{
	bool Input::GetKey(const KeyCode keyCode)
	{
		return Application::Get()->GetWindow().GetKey(keyCode);
	}

	bool Input::GetMouseKey(uint16_t index)
	{
		return Application::Get()->GetWindow().GetMouseButton(index);
	}
}