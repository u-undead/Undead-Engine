#include "texture.h"

namespace Undead
{
	namespace Render
	{
		Texture::Texture(const char* path)
		{
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			wrap();
			filter();
			loadTexture(path);
		}

		void Texture::wrap()
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		}

		void Texture::filter()
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		}

		void Texture::loadTexture(const char* path)
		{
			image_data = stbi_load(path, &width, &height, &nrChannels, 0);
			if (image_data)
			{
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image_data);
				glGenerateMipmap(GL_TEXTURE_2D);
			}
			else
			{
				std::cout << "File read error" << std::endl;
			}
		}

		void Texture::bind()
		{
			glBindTexture(GL_TEXTURE_2D, texture);
		}

		Texture::~Texture()
		{
			glDeleteTextures(1, &texture);
			stbi_image_free(image_data);
		}
	}
}