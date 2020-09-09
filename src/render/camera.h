#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Undead
{
	namespace Render
	{
		GLfloat lastX = 400, lastY = 300;
		GLfloat yaw = -90.0f;
		GLfloat pitch = 0.0f;

		glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
		GLfloat deltaTime = 0.0f;
		GLfloat lastFrame = 0.0f;

		bool firstMouse = true;

		class Camera
		{
		private:
			glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

		public:

			static void mouse_callback(GLFWwindow* window, double xpos, double ypos)
			{
				if (firstMouse)
				{
					lastX = xpos;
					lastY = ypos;
					firstMouse = false;
				}

				GLfloat xoffset = xpos - lastX;
				GLfloat yoffset = lastY - ypos;
				lastX = xpos;
				lastY = ypos;

				GLfloat sensitivity = 0.05;
				xoffset *= sensitivity;
				yoffset *= sensitivity;

				yaw += xoffset;
				pitch += yoffset;

				if (pitch > 89.0f)
					pitch = 89.0f;
				if (pitch < -89.0f)
					pitch = -89.0f;

				glm::vec3 front;
				front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
				front.y = sin(glm::radians(pitch));
				front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
				cameraFront = glm::normalize(front);
			}


			void calculateDelta()
			{
				GLfloat currentFrame = glfwGetTime();
				deltaTime = currentFrame - lastFrame;
				lastFrame = currentFrame;
			}

			glm::mat4 getViewMatrix()
			{
				return view;
			}

			void do_movement(GLFWwindow* window)
			{
				GLfloat cameraSpeed = 5.0f * deltaTime;
				if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
					cameraPos += cameraSpeed * cameraFront;
				if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
					cameraPos -= cameraSpeed * cameraFront;
				if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
					cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
				if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
					cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
			}
		};

	}
}


