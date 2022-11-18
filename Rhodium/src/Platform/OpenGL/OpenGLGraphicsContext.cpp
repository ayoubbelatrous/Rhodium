#include "rpch.h"
#include "Platform/OpenGL/OpenGLGraphicsContext.h"

#include "Application/Core/Application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Rhodium::Platform
{
	void OpenGLGraphicsContext::Init()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize OpenGL context" << std::endl;
		}
		std::cout << "OpenGL Vendor:    " << glGetString(GL_VENDOR) << std::endl;
		std::cout << "OpenGL Version:   " << glGetString(GL_VERSION) << std::endl;
		std::cout << "OpenGL Device:    " << glGetString(GL_RENDERER) << std::endl;
	}
}