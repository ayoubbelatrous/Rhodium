#pragma once

#include "Rendering/Core/Buffer.h"

namespace Rhodium::Platform
{
	class OpenGLVertexBuffer : public Core::VertexBuffer
	{
	public:

		OpenGLVertexBuffer(uint32_t size);
		OpenGLVertexBuffer(float* data, uint32_t size);
		virtual ~OpenGLVertexBuffer();

		void Bind() const override;

		void UnBind() const override;

		void SetData(float* data, uint32_t size) override;

		virtual const Core::BufferLayout& GetLayout() const override { return m_Layout; }
		virtual void SetLayout(const Core::BufferLayout& layout) override { m_Layout = layout; }

	private:
		uint32_t m_RendererID;
		Core::BufferLayout m_Layout;
	};

	class OpenGLIndexBuffer : public Core::IndexBuffer
	{
	public:

		OpenGLIndexBuffer(uint32_t* data, uint32_t count);
		virtual ~OpenGLIndexBuffer();

		void Bind() const override;

		void UnBind() const override;

		uint32_t GetCount() const override { return m_Count; };

	private:
		uint32_t m_RendererID;
		uint32_t m_Count;
	};
}