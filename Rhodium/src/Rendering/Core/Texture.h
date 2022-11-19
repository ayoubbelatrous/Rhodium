#pragma once

namespace Rhodium::Core
{
	class Texture
	{
	public:
		static Ref<Texture> Create(std::string path);
		static Ref<Texture> Create(uint32_t width, uint32_t height);
		static Ref<Texture> Create(float* data, uint32_t width, uint32_t height);

		virtual void Bind(uint32_t slot = 0) const = 0;
		virtual void UnBind() const = 0;

		virtual uint32_t GetRendererID() = 0;
		virtual void SetData(float* data) = 0;
	};
}