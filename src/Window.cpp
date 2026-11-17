#include "Window.h"

#include <stdexcept>

Window::Window()
{
	if (!glfwInit())
		throw std::runtime_error("glfw initialization failure");

	window = glfwCreateWindow(640, 640, "Snake Game", NULL, NULL);

	if (!window)
		throw std::runtime_error("glfw create window failure");

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		throw std::runtime_error("glad loading failure");
}

Window::~Window()
{
	glfwTerminate();
}

void Window::Run()
{
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
