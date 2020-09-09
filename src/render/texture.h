#pragma once

#include <GL/glew.h>
#include <stb/stb_image.h>
#include <iostream>

namespace Undead
{
	namespace Render
	{
		class Texture
		{
		private:
			unsigned int texture;
			int width, height, nrChannels;
			unsigned char* image_data;
			void wrap();
			void filter();
			void loadTexture(const char* path);
		public:
			Texture(const char* path);
			void bind();
			~Texture();
		};
	}
}



