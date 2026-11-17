#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window();
	~Window();

	void Update() const {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	bool ShouldClose() const { return glfwWindowShouldClose(window); }

private:
	GLFWwindow* window;
};

