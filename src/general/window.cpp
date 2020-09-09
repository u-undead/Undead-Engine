#include "window.h"

#include <render/camera.h>


namespace Undead
{
	namespace General
	{
		Undead::Render::Camera camera;

		Window::Window(int width, int height, const char* title)
		{
			glfwInit();
			window = glfwCreateWindow(width, height, title, nullptr, nullptr);
			glfwMakeContextCurrent(window);
			glfwSetFramebufferSizeCallback(window, windowSizeChangeEvent);
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			glfwSetCursorPosCallback(window, Undead::Render::Camera::mouse_callback);
			glewInit();
		}

		void Window::onUpdate()
		{

			uint vao, vbo, ibo;

			float vertices[] = {
				-0.5, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
				 0.5, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
				 0.5,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
				 0.5,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
				-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
				-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

				-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 0.0f,
				 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 1.0f, 0.0f,
				 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 1.0f, 1.0f,
				 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 1.0f, 1.0f,
				-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 1.0f,
				-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 0.0f,

				-0.5f,  0.5f,  0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
				-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f,
				-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
				-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
				-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f,
				-0.5f,  0.5f,  0.5f,-1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

				 0.5f,  0.5f,  0.5f, 1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
				 0.5f,  0.5f, -0.5f, 1.0f,  0.0f,  0.0f, 1.0f, 1.0f,
				 0.5f, -0.5f, -0.5f, 1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
				 0.5f, -0.5f, -0.5f, 1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
				 0.5f, -0.5f,  0.5f, 1.0f,  0.0f,  0.0f, 0.0f, 0.0f,
				 0.5f,  0.5f,  0.5f, 1.0f,  0.0f,  0.0f, 1.0f, 0.0f,

				-0.5f, -0.5f, -0.5f, 0.0f, -1.0f,  0.0f, 0.0f, 1.0f,
				 0.5f, -0.5f, -0.5f, 0.0f, -1.0f,  0.0f, 1.0f, 1.0f,
				 0.5f, -0.5f,  0.5f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
				 0.5f, -0.5f,  0.5f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
				-0.5f, -0.5f,  0.5f, 0.0f, -1.0f,  0.0f, 0.0f, 0.0f,
				-0.5f, -0.5f, -0.5f, 0.0f, -1.0f,  0.0f, 0.0f, 1.0f,

				-0.5f,  0.5f, -0.5f, 0.0f,  1.0f,  0.0f, 0.0f, 1.0f,
				 0.5f,  0.5f, -0.5f, 0.0f,  1.0f,  0.0f, 1.0f, 1.0f,
				 0.5f,  0.5f,  0.5f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
				 0.5f,  0.5f,  0.5f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
				-0.5f,  0.5f,  0.5f, 0.0f,  1.0f,  0.0f, 0.0f, 0.0f,
				-0.5f,  0.5f, -0.5f, 0.0f,  1.0f,  0.0f, 0.0f, 1.0f
			};

			unsigned int indices[] = {
				0, 1, 3,
				1, 2, 3
			};

			glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);

			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glGenBuffers(1, &ibo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);

			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
			glEnableVertexAttribArray(1);

			glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(2);

			Undead::Render::Texture texture("res/textures/container.jpg");

			Undead::Render::Shader shader("res/shaders/main_shader.vert", "res/shaders/main_shader.frag");

			unsigned int modelLoc = glGetUniformLocation(shader.program, "model");

			glEnable(GL_DEPTH_TEST);

			
			int screenWidth, screenHeight;

			glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

			Undead::Render::Light light(Undead::Render::Material::RUBY);

			while (!glfwWindowShouldClose(window))
			{
				glfwGetWindowSize(window, &screenWidth, &screenHeight);

				glClearColor(0, 0, 0, 1);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				
				camera.calculateDelta();
				camera.do_movement(window);
				
				texture.bind();

				shader.start();

				light.setupLightPositions(shader, Undead::Render::cameraPos, Undead::Render::cameraPos);
				light.setupMaterial(shader);
				light.setupLighting(shader);

				glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
				glm::mat4 view = glm::mat4(1.0f);
				glm::mat4 projection = glm::mat4(1.0f);

				view = glm::lookAt(Undead::Render::cameraPos, Undead::Render::cameraPos + Undead::Render::cameraFront, Undead::Render::cameraUp);
				projection = glm::perspective(glm::radians(45.0f), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
				
				glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
				shader.setMat4("view", view);
				shader.setMat4("projection", projection);

				glBindVertexArray(vao);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

				glDrawArrays(GL_TRIANGLES, 0, 36);
				shader.stop();

				glfwSwapBuffers(window);
				glfwPollEvents();
			}
		}

		void Window::windowSizeChangeEvent(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		Window::~Window()
		{
			glfwDestroyWindow(window);
			glfwTerminate();
		}
	}
}