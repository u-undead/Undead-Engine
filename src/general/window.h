#pragma once

#include <render/light.h>
#include <render/texture.h>
#include <render/shader.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace Undead
{
	typedef unsigned int uint;
	namespace General
	{
		class Window
		{
		private:
			GLFWwindow* window;
		public:
			Window(int width, int height, const char* title);
			void onUpdate();
			static void windowSizeChangeEvent(GLFWwindow* window, int width, int height);
			~Window();
		};
	}
}



