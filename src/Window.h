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

	bool CheckKey(int key) const { return glfwGetKey(window, key) == GLFW_PRESS; }

	double GetTime() const { return glfwGetTime(); }

private:
	GLFWwindow* window;
};

