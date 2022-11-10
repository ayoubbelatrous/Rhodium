#include "rpch.h"
#include "Platform/OpenGL/OpenGLGraphicsContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Rhodium::Platform
{
	void OpenGLGraphicsContext::Init()
	{
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	}
}