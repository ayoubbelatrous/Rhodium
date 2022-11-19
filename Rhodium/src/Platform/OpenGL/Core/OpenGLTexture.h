#pragma once
#include "Rendering/Core/Texture.h"

namespace Rhodium::Platform
{
	class OpenGLTexture : public Core::Texture
	{
	public:
		OpenGLTexture(std::string path);
		OpenGLTexture(float* data, uint32_t width, uint32_t height);
		OpenGLTexture(uint32_t width, uint32_t height);

		void Bind(uint32_t slot = 0) const override;


		void UnBind() const override;


		uint32_t GetRendererID() override;


		void SetData(float* data) override;

	private:
		std::string m_Path;
		uint32_t m_Width,m_Height;
		uint32_t m_RendererID;
	};
}