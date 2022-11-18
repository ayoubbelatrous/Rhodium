#include "rpch.h"

#include "Platform/OpenGL/OpenGLRenderingApi.h"

#include "glad/glad.h"

namespace Rhodium::Platform
{
	void OpenGLRenderingApi::Init()
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LINE_SMOOTH);
	}

	void OpenGLRenderingApi::SetViewPortSize(int x, int y, int w, int h)
	{
		glViewport(x, y, w, h);
	}

}