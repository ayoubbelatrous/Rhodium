#pragma once
#include "Input/KeyCodes.h"

namespace Rhodium::Core
{
	class Input
	{
	public:
		static bool GetKey(const KeyCode keyCode);
		static bool GetMouseKey(uint16_t index);
	};

}