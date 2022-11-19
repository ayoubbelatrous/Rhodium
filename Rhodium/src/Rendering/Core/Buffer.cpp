#include "rpch.h"

#include "Rendering/Core/Buffer.h"
#include "Core/Base.h"

#include "Platform/OpenGL/Core/OpenGLBuffer.h"


namespace Rhodium::Core
{
	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		return CreateRef<Platform::OpenGLVertexBuffer>(size);
	}

	Ref<VertexBuffer> VertexBuffer::Create(float* data, uint32_t size)
	{
		return CreateRef<Platform::OpenGLVertexBuffer>(data,size);
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* data, uint32_t count)
	{
		return CreateRef<Platform::OpenGLIndexBuffer>(data,count);
	}
}
